﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2023 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* BasicReaderWriter.cc                                        (C) 2000-2023 */
/*                                                                           */
/* Lecture/Ecriture simple.                                                  */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/std/internal/BasicReaderWriter.h"

#include "arcane/utils/TraceAccessor.h"
#include "arcane/utils/ScopedPtr.h"
#include "arcane/utils/StringBuilder.h"
#include "arcane/utils/OStringStream.h"
#include "arcane/utils/NotImplementedException.h"
#include "arcane/utils/NotSupportedException.h"
#include "arcane/utils/PlatformUtils.h"
#include "arcane/utils/IOException.h"
#include "arcane/utils/CheckedConvert.h"
#include "arcane/utils/JSONWriter.h"
#include "arcane/utils/JSONReader.h"
#include "arcane/utils/IDataCompressor.h"
#include "arcane/utils/IHashAlgorithm.h"
#include "arcane/utils/ArrayShape.h"
#include "arcane/utils/ValueConvert.h"
#include "arcane/utils/List.h"
#include "arcane/utils/ITraceMng.h"

#include "arcane/core/XmlNode.h"
#include "arcane/core/IXmlDocumentHolder.h"
#include "arcane/core/ISubDomain.h"
#include "arcane/core/IParallelMng.h"
#include "arcane/core/IIOMng.h"
#include "arcane/core/IDataReader.h"
#include "arcane/core/IDataReader2.h"
#include "arcane/core/IDataWriter.h"
#include "arcane/core/CheckpointService.h"
#include "arcane/core/Directory.h"
#include "arcane/core/ArcaneException.h"
#include "arcane/core/FactoryService.h"
#include "arcane/core/ISerializedData.h"
#include "arcane/core/IMesh.h"
#include "arcane/core/IRessourceMng.h"
#include "arcane/core/XmlNodeList.h"
#include "arcane/core/VariableCollection.h"
#include "arcane/core/IParallelReplication.h"
#include "arcane/core/IVariableUtilities.h"
#include "arcane/core/ServiceBuilder.h"
#include "arcane/core/VerifierService.h"
#include "arcane/core/IVariableMng.h"
#include "arcane/core/IItemFamily.h"
#include "arcane/core/IParallelExchanger.h"
#include "arcane/core/ISerializeMessage.h"
#include "arcane/core/ISerializer.h"
#include "arcane/core/SerializeBuffer.h"
#include "arcane/core/VariableMetaData.h"
#include "arcane/core/CheckpointInfo.h"

#include "arcane/std/ParallelDataReader.h"
#include "arcane/std/ParallelDataWriter.h"

#include "arcane/std/TextReader.h"
#include "arcane/std/TextWriter.h"
#include "arcane/std/BasicReaderWriterDatabase.h"

#include "arcane/std/ArcaneBasicCheckpoint_axl.h"

#include <map>
#include <set>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::impl
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableDataInfo::
VariableDataInfo(const String& full_name,const ISerializedData* sdata)
: m_full_name(full_name)
{
  m_nb_dimension = sdata->nbDimension();
  Int64ConstArrayView extents = sdata->extents();

  m_nb_base_element = sdata->nbBaseElement();

  m_nb_element = sdata->nbElement();
  m_is_multi_size = sdata->isMultiSize();
  m_dim2_size = 0;
  m_dim1_size = 0;
  if (m_nb_dimension==2 && !m_is_multi_size){
    m_dim1_size = extents[0];
    m_dim2_size = extents[1];
  }
  m_dimension_array_size = extents.size();
  m_base_data_type = sdata->baseDataType();
  m_memory_size = sdata->memorySize();
  m_shape = sdata->shape();
  m_file_offset = 0;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableDataInfo::
VariableDataInfo(const String& full_name,const XmlNode& element)
: m_full_name(full_name)
{
  m_nb_dimension = _readInteger(element,"nb-dimension");
  m_dim1_size = _readInt64(element,"dim1-size");
  m_dim2_size = _readInt64(element,"dim2-size");
  m_nb_element = _readInt64(element,"nb-element");
  m_nb_base_element = _readInt64(element,"nb-base-element");
  m_dimension_array_size = _readInteger(element,"dimension-array-size");
  m_is_multi_size = _readBool(element,"is-multi-size");
  m_base_data_type = (eDataType)_readInteger(element,"base-data-type");
  m_memory_size = _readInt64(element,"memory-size");
  m_file_offset = _readInt64(element,"file-offset");
  // L'élément est nul si on repart d'une veille protection (avant Arcane 3.7)
  XmlNode shape_attr = element.attr("shape");
  if (!shape_attr.null()){
    String shape_str = shape_attr.value();
    if (!shape_str.empty()){
      UniqueArray<Int32> values;
      if (builtInGetValue(values,shape_str))
        ARCANE_FATAL("Can not read values '{0}' for attribute 'shape'",shape_str);
      m_shape.setDimensions(values);
    }
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void VariableDataInfo::
write(XmlNode element)
{
  _addAttribute(element,"nb-dimension",m_nb_dimension);
  _addAttribute(element,"dim1-size",m_dim1_size);
  _addAttribute(element,"dim2-size",m_dim2_size);
  _addAttribute(element,"nb-element",m_nb_element);
  _addAttribute(element,"nb-base-element",m_nb_base_element);
  _addAttribute(element,"dimension-array-size",m_dimension_array_size);
  _addAttribute(element,"is-multi-size",(m_is_multi_size) ? 1 : 0);
  _addAttribute(element,"base-data-type",(Integer)m_base_data_type);
  _addAttribute(element,"memory-size",m_memory_size);
  _addAttribute(element,"file-offset",m_file_offset);
  _addAttribute(element,"shape-size",m_shape.dimensions().size());
  {
    String s;
    if (builtInPutValue(m_shape.dimensions().smallView(),s))
      ARCANE_FATAL("Can not write '{0}'",m_shape.dimensions());
    _addAttribute(element,"shape",s);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace
{
String _getArcaneDBTag()
{
  return "ArcaneCheckpointRestartDataBase";
}

String
_getOwnMetatadaFile(const String& path,Int32 rank)
{
  StringBuilder filename = path;
  filename += "/own_metadata_";
  filename += rank;
  filename += ".txt";
  return filename;
}

String
_getArcaneDBFile(const String& path,Int32 rank)
{
  StringBuilder filename = path;
  filename += "/arcane_db_n";
  filename += rank;
  filename += ".acr";
  return filename;
}

String
_getBasicVariableFile(Int32 version,const String& path,Int32 rank)
{
  if (version>=3){
    return _getArcaneDBFile(path,rank);
  }
  StringBuilder filename = path;
  filename += "/var___MAIN___";
  filename += rank;
  filename += ".txt";
  return filename;
}

String
_getBasicGroupFile(const String& path,const String& name,Int32 rank)
{
  StringBuilder filename = path;
  filename += "/group_";
  filename += name;
  filename += "_";
  filename += rank;
  filename += ".txt";
  return filename;
}

Ref<IDataCompressor>
_createDeflater(IApplication* app,const String& name)
{
  ServiceBuilder<IDataCompressor> sf(app);
  Ref<IDataCompressor> bc = sf.createReference(app,name);
  return bc;
}

Ref<IHashAlgorithm>
_createHashAlgorithm(IApplication* app,const String& name)
{
  ServiceBuilder<IHashAlgorithm> sf(app);
  Ref<IHashAlgorithm> bc = sf.createReference(app,name);
  return bc;
}

void
_fillUniqueIds(const ItemGroup& group,Array<Int64>& uids)
{
  Integer nb_item = group.size();
  uids.clear();
  uids.reserve(nb_item);
  ENUMERATE_ITEM(iitem,group){
    Int64 uid = iitem->uniqueId();
    uids.add(uid);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicGenericReader::
BasicGenericReader(IApplication* app, Int32 version, Ref<impl::KeyValueTextReader> text_reader)
: TraceAccessor(app->traceMng())
, m_application(app)
, m_text_reader(text_reader)
, m_rank(A_NULL_RANK)
, m_version(version)
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicGenericReader::
~BasicGenericReader()
{
  for (const auto& x : m_variables_data_info)
    delete x.second;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericReader::
initialize(const String& path,Int32 rank)
{
  // Dans le cas de la version 1 ou 2, on ne peut pas créer le KeyValueTextReader
  // avant de lire les 'OwnMetaData' car ce sont ces dernières qui contiennent
  // le numéro de version.

  m_path = path;
  m_rank = rank;

  info(4) << "BasicGenericReader::initialize known_version=" << m_version;

  ScopedPtrT<IXmlDocumentHolder> xdoc;

  if (m_version>=3){
    if (!m_text_reader.get())
      ARCANE_FATAL("Null text reader");
    String dc_name;
    if (m_text_reader->dataCompressor().get())
      dc_name = m_text_reader->dataCompressor()->name();
    info(4) << "BasicGenericReader::initialize data_compressor=" << dc_name;

    // Si on connait déjà la version et qu'elle est supérieure ou égale à 3
    // alors les informations sont dans la base de données. Dans ce cas on lit
    // directement les infos depuis cette base.
    String main_filename = _getBasicVariableFile(m_version,m_path,rank);
    Int64 meta_data_size = 0;
    String key_name = "Global:OwnMetadata";
    m_text_reader->getExtents(key_name,Int64ArrayView(1,&meta_data_size));
    UniqueArray<std::byte> bytes(meta_data_size);
    m_text_reader->read(key_name,bytes);
    info(4) << "Reading own metadata rank=" << rank << " from database";
    xdoc = IXmlDocumentHolder::loadFromBuffer(bytes,"OwnMetadata",traceMng());
  }
  else{
    StringBuilder filename = _getOwnMetatadaFile(m_path,m_rank);
    info(4) << "Reading own metadata rank=" << rank << " file=" << filename;
    IApplication* app = m_application;
    xdoc = app->ioMng()->parseXmlFile(filename);
  }
  XmlNode root = xdoc->documentNode().documentElement();
  XmlNodeList variables_elem = root.children("variable-data");
  String deflater_name = root.attrValue("deflater-service");
  String hash_algorithm_name = root.attrValue("hash-algorithm-service");
  String version_id = root.attrValue("version",false);
  info(4) << "Infos from metadata deflater-service=" << deflater_name
          << " hash-algorithm-service=" << hash_algorithm_name
          << " version=" << version_id;
  if (version_id.null() || version_id=="1")
    // Version 1:
    // - taille des dimensions sur 32 bits
    m_version = 1;
  else if (version_id=="2")
    // Version 2:
    // - taille des dimensions sur 64 bits
    m_version = 2;
  else if (version_id=="3")
    // Version 3:
    // - taille des dimensions sur 64 bits
    // - 1 seul fichier pour toutes les meta-données
    m_version = 3;
  else
    ARCANE_FATAL("Unsupported version '{0}' (max=3)",version_id);

  Ref<IDataCompressor> deflater;
  if (!deflater_name.null())
    deflater = _createDeflater(m_application,deflater_name);

  Ref<IHashAlgorithm> hash_algorithm;
  if (!hash_algorithm_name.null())
    hash_algorithm = _createHashAlgorithm(m_application,hash_algorithm_name);

  for( Integer i=0, is=variables_elem.size(); i<is; ++i ){
    XmlNode n = variables_elem[i];
    String var_full_name = n.attrValue("full-name");
    auto vdi = new VariableDataInfo(var_full_name,n);
    m_variables_data_info.insert(std::make_pair(var_full_name,vdi));
  }

  if (!m_text_reader.get()){
    String main_filename = _getBasicVariableFile(m_version,m_path,rank);
    m_text_reader = makeRef(new KeyValueTextReader(traceMng(),main_filename,m_version));
  }

  // Il est possible qu'il y ait déjà un algorithme de compression spécifié.
  // Il ne faut pas l'écraser si aucun n'est spécifié dans 'OwnMetadata'.
  // (Normalement cela ne devrait pas arriver sauf incohérence).
  if (deflater.get())
    m_text_reader->setDataCompressor(deflater);
  if (hash_algorithm.get())
    m_text_reader->setHashAlgorithm(hash_algorithm);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableDataInfo* BasicGenericReader::
_getVarInfo(const String& full_name)
{
  VariableDataInfoMap::const_iterator ivar = m_variables_data_info.find(full_name);
  if (ivar==m_variables_data_info.end())
    ARCANE_THROW(ReaderWriterException,
                 "Can not find own metadata infos for data var={0} rank={1}",full_name,m_rank);
  VariableDataInfo* vdi = ivar->second;
  return vdi;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericReader::
readData(const String& var_full_name,IData* data)
{
  KeyValueTextReader* reader = m_text_reader.get();
  String vname = var_full_name;
  VariableDataInfo* vdi = _getVarInfo(vname);
  if (m_version<3)
    reader->setFileOffset(vdi->fileOffset());

  eDataType data_type = vdi->baseDataType();
  Int64 memory_size = vdi->memorySize();
  Integer dimension_array_size = vdi->dimensionArraySize();
  Int64 nb_element = vdi->nbElement();
  Integer nb_dimension = vdi->nbDimension();
  Int64 nb_base_element = vdi->nbBaseElement();
  bool is_multi_size = vdi->isMultiSize();
  UniqueArray<Int64> extents(dimension_array_size);
  reader->getExtents(var_full_name,extents.view());
  ArrayShape shape = vdi->shape();

  Ref<ISerializedData> sd(arcaneCreateSerializedDataRef(data_type,memory_size,nb_dimension,nb_element,
                                                        nb_base_element,is_multi_size,extents,shape));

  Int64 storage_size = sd->memorySize();
  info(4) << " READ DATA storage_size=" << storage_size << " DATA=" << data;

  data->allocateBufferForSerializedData(sd.get());

  if (storage_size!=0)
    reader->read(var_full_name,asWritableBytes(sd->writableBytes()));

  data->assignSerializedData(sd.get());
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericReader::
readItemGroup(const String& group_full_name,Int64Array& written_unique_ids,
              Int64Array& wanted_unique_ids)
{
  if (m_version>=3){
    {
      String written_uid_name = String("GroupWrittenUid:")+group_full_name;
      Int64 nb_written_uid = 0;
      m_text_reader->getExtents(written_uid_name,Int64ArrayView(1,&nb_written_uid));
      written_unique_ids.resize(nb_written_uid);
      m_text_reader->read(written_uid_name,asWritableBytes(written_unique_ids.span()));
    }
    {
      String wanted_uid_name = String("GroupWantedUid:")+group_full_name;
      Int64 nb_wanted_uid = 0;
      m_text_reader->getExtents(wanted_uid_name,Int64ArrayView(1,&nb_wanted_uid));
      wanted_unique_ids.resize(nb_wanted_uid);
      m_text_reader->read(wanted_uid_name,asWritableBytes(wanted_unique_ids.span()));
    }
    return;
  }
  info(5) << "READ GROUP " << group_full_name;
  String filename = _getBasicGroupFile(m_path,group_full_name,m_rank);
  impl::TextReader reader(filename);

  {
    Integer nb_unique_id = 0;
    reader.readIntegers(IntegerArrayView(1,&nb_unique_id));
    info(5) << "NB_WRITTEN_UNIQUE_ID = " << nb_unique_id;
    written_unique_ids.resize(nb_unique_id);
    reader.read(asWritableBytes(written_unique_ids.span()));
  }

  {
    Integer nb_unique_id = 0;
    reader.readIntegers(IntegerArrayView(1,&nb_unique_id));
    info(5) << "NB_WANTED_UNIQUE_ID = " << nb_unique_id;
    wanted_unique_ids.resize(nb_unique_id);
    reader.read(asWritableBytes(wanted_unique_ids.span()));
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicGenericWriter::
BasicGenericWriter(IApplication* app, Int32 version,
                   Ref<impl::KeyValueTextWriter> text_writer)
: TraceAccessor(app->traceMng())
, m_application(app)
, m_version(version)
, m_rank(A_NULL_RANK)
, m_text_writer(text_writer)
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicGenericWriter::
~BasicGenericWriter()
{
  for (const auto& x : m_variables_data_info) {
    delete x.second;
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericWriter::
initialize(const String& path, Int32 rank)
{
  if (!m_text_writer)
    ARCANE_FATAL("Null text writer");
  m_path = path;
  m_rank = rank;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericWriter::
writeData(const String& var_full_name,const ISerializedData* sdata)
{
  //TODO: Verifier que initialize() a bien été appelé.
  auto var_data_info = new VariableDataInfo(var_full_name,sdata);
  KeyValueTextWriter* writer = m_text_writer.get();
  var_data_info->setFileOffset(writer->fileOffset());
  m_variables_data_info.insert(std::make_pair(var_full_name,var_data_info));
  info(4) << " SDATA name=" << var_full_name << " nb_element=" << sdata->nbElement()
          << " dim=" << sdata->nbDimension() << " datatype=" << sdata->baseDataType()
          << " nb_basic_element=" << sdata->nbBaseElement()
          << " is_multi=" << sdata->isMultiSize()
          << " dimensions_size=" << sdata->extents().size()
          << " memory_size=" << sdata->memorySize()
          << " bytes_size=" << sdata->constBytes().size();

  const void* ptr = sdata->constBytes().data();

  // Si la variable est de type tableau à deux dimensions, sauve les
  // tailles de la deuxième dimension par élément.
  Int64ConstArrayView extents = sdata->extents();
  writer->setExtents(var_full_name,extents);

  // Maintenant, sauve les valeurs si necessaire
  Int64 nb_base_element = sdata->nbBaseElement();
  if (nb_base_element!=0 && ptr){
    writer->write(var_full_name,asBytes(sdata->constBytes()));
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericWriter::
writeItemGroup(const String& group_full_name,SmallSpan<const Int64> written_unique_ids,
               SmallSpan<const Int64> wanted_unique_ids)
{
  if (m_version>=3){
    // Sauve les informations du groupe la base de données (clé,valeur)
    {
      String written_uid_name = String("GroupWrittenUid:")+group_full_name;
      Int64 nb_written_uid = written_unique_ids.size();
      m_text_writer->setExtents(written_uid_name,Int64ConstArrayView(1,&nb_written_uid));
      m_text_writer->write(written_uid_name,asBytes(written_unique_ids));
    }
    {
      String wanted_uid_name = String("GroupWantedUid:")+group_full_name;
      Int64 nb_wanted_uid = wanted_unique_ids.size();
      m_text_writer->setExtents(wanted_uid_name,Int64ConstArrayView(1,&nb_wanted_uid));
      m_text_writer->write(wanted_uid_name,asBytes(wanted_unique_ids));
    }
    return;
  }

  String filename = _getBasicGroupFile(m_path,group_full_name,m_rank);
  impl::TextWriter writer(filename);

  // Sauve la liste des unique_ids écrits
  {
    Integer nb_unique_id = written_unique_ids.size();
    writer.write(asBytes(Span<const Int32>(&nb_unique_id,1)));
    writer.write(asBytes(written_unique_ids));
  }

  // Sauve la liste des unique_ids souhaités par ce sous-domaine
  {
    Integer nb_unique_id = wanted_unique_ids.size();
    writer.write(asBytes(Span<const Int32>(&nb_unique_id,1)));
    writer.write(asBytes(wanted_unique_ids));
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicGenericWriter::
endWrite()
{
  IApplication* app = m_application;
  ScopedPtrT<IXmlDocumentHolder> xdoc(app->ressourceMng()->createXmlDocument());
  XmlNode doc = xdoc->documentNode();
  XmlElement root(doc,"variables-data");
  IDataCompressor* dc = m_text_writer->dataCompressor().get();
  if (dc){
    root.setAttrValue("deflater-service",dc->name());
    root.setAttrValue("min-compress-size",String::fromNumber(dc->minCompressSize()));
  }
  root.setAttrValue("version",String::fromNumber(m_version));
  for( const auto& i : m_variables_data_info ){
    VariableDataInfo* vdi = i.second;
    XmlNode e = root.createAndAppendElement("variable-data");
    e.setAttrValue("full-name",vdi->fullName());
    vdi->write(e);
  }
  if (m_version>=3){
    // Sauve les méta-données dans la base de données.
    UniqueArray<Byte> bytes;
    xdoc->save(bytes);
    Int64 length = bytes.length();
    String key_name = "Global:OwnMetadata";
    m_text_writer->setExtents(key_name,Int64ConstArrayView(1,&length));
    m_text_writer->write(key_name,asBytes(bytes.span()));
  }
  else{
    String filename = _getOwnMetatadaFile(m_path,m_rank);
    app->ioMng()->writeXmlFile(xdoc.get(),filename);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicReaderWriterCommon::
BasicReaderWriterCommon(IApplication* app,IParallelMng* pm,
                        const String& path,eOpenMode open_mode)
: TraceAccessor(pm->traceMng())
, m_application(app)
, m_parallel_mng(pm)
, m_open_mode(open_mode)
, m_path(path)
, m_verbose_level(0)
{}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicReaderWriterCommon::
~BasicReaderWriterCommon()
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

String BasicReaderWriterCommon::
_getMetaDataFileName(Int32 rank)
{
  StringBuilder filename = m_path;
  filename += "/metadata";
  filename += "-";
  filename += rank;
  filename += ".txt";
  return filename;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicWriter::
BasicWriter(IApplication* app,IParallelMng* pm,const String& path,
            eOpenMode open_mode,Integer version,bool want_parallel)
: BasicReaderWriterCommon(app,pm,path,open_mode)
, m_want_parallel(want_parallel)
, m_is_gather(false)
, m_version(version)
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicWriter::
~BasicWriter()
{
  for( const auto& i : m_parallel_data_writers )
    delete i.second;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
initialize()
{
  Int32 rank = m_parallel_mng->commRank();
  if (m_open_mode==OpenModeTruncate && m_parallel_mng->isMasterIO())
    platform::recursiveCreateDirectory(m_path);
  m_parallel_mng->barrier();
  String filename = _getBasicVariableFile(m_version,m_path,rank);
  m_text_writer = makeRef(new KeyValueTextWriter(traceMng(),filename,m_version));
  m_text_writer->setDataCompressor(m_data_compressor);
  m_text_writer->setHashAlgorithm(m_hash_algorithm);

  // Permet de surcharger le service utilisé pour la compression par une
  // variable d'environnement si aucun n'est positionné
  if (!m_data_compressor.get()){
    String data_compressor_name = platform::getEnvironmentVariable("ARCANE_DEFLATER");
    if (!data_compressor_name.null()){
      data_compressor_name = data_compressor_name + "DataCompressor";
      auto bc = _createDeflater(m_application,data_compressor_name);
      info() << "Use data_compressor from environment variable ARCANE_DEFLATER name=" << data_compressor_name;
      m_data_compressor = bc;
      m_text_writer->setDataCompressor(bc);
    }
  }
  // Idem pour le service de calcul de hash
  if (!m_hash_algorithm.get()){
    String hash_algorithm_name = platform::getEnvironmentVariable("ARCANE_HASHALGORITHM");
    if (hash_algorithm_name.null())
      hash_algorithm_name = "SHA3_256";
    else
      info() << "Use hash algorithm from environment variable ARCANE_HASHALGORITHM name=" << hash_algorithm_name;
    hash_algorithm_name = hash_algorithm_name + "HashAlgorithm";
    auto v = _createHashAlgorithm(m_application,hash_algorithm_name);
    m_hash_algorithm = v;
    m_text_writer->setHashAlgorithm(v);
  }

  m_global_writer = new BasicGenericWriter(m_application,m_version,m_text_writer);
  if (m_verbose_level>0)
    info() << "** OPEN MODE = " << m_open_mode;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ParallelDataWriter* BasicWriter::
_getWriter(IVariable* var)
{
  ItemGroup group = var->itemGroup();
  auto i = m_parallel_data_writers.find(group);
  if (i!=m_parallel_data_writers.end())
    return i->second;
  ParallelDataWriter* writer = new ParallelDataWriter(m_parallel_mng);
  writer->setGatherAll(m_is_gather);
  {
    Int64UniqueArray items_uid;
    ItemGroup own_group = var->itemGroup().own();
    _fillUniqueIds(own_group,items_uid);
    Int32ConstArrayView local_ids = own_group.internal()->itemsLocalId();
    writer->sort(local_ids,items_uid);
  }
  m_parallel_data_writers.insert(std::make_pair(group,writer));
  return writer;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
_directWriteVal(IVariable* var,IData* data)
{
  info(4) << "DIRECT WRITE VAL v=" << var->fullName();

  IData* write_data = data;
  Int64ConstArrayView written_unique_ids;
  Int64UniqueArray wanted_unique_ids;
  Int64UniqueArray sequential_written_unique_ids;
  Ref<IData> allocated_write_data;
  if (var->itemKind()!=IK_Unknown){
    ItemGroup group = var->itemGroup();
    if (m_want_parallel){
      ParallelDataWriter* writer = _getWriter(var);
      written_unique_ids = writer->sortedUniqueIds();
      allocated_write_data = writer->getSortedValues(data);
      write_data = allocated_write_data.get();
    }
    else{
      //TODO il faut trier les uniqueId
      _fillUniqueIds(group,sequential_written_unique_ids);
      written_unique_ids = sequential_written_unique_ids.view();
    }
    _fillUniqueIds(group,wanted_unique_ids);
    if (m_written_groups.find(group)==m_written_groups.end()){
      info(5) << "WRITE GROUP " << group.name();
      IItemFamily* item_family = group.itemFamily();
      String gname = group.name();
      String group_full_name = item_family->fullName() + "_" + gname;
      m_global_writer->writeItemGroup(group_full_name,written_unique_ids,wanted_unique_ids.view());
      m_written_groups.insert(group);
    }
  }
  Ref<ISerializedData> sdata(write_data->createSerializedDataRef(false));
  m_global_writer->writeData(var->fullName(),sdata.get());
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
write(IVariable* var,IData* data)
{
  if (var->isPartial()){
    info() << "** WARNING: partial variable not implemented in BasicWriter";
    return;
  }
  _directWriteVal(var,data);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
setMetaData(const String& meta_data)
{
  // Dans la version 3, les méta-données de la protection sont dans la
  // base de données.
  if (m_version>=3){
    Span<const Byte> bytes = meta_data.utf8();
    Int64 length = bytes.length();
    String key_name = "Global:CheckpointMetadata";
    m_text_writer->setExtents(key_name,Int64ConstArrayView(1,&length));
    m_text_writer->write(key_name,asBytes(bytes));
  }
  else{
    Int32 my_rank = m_parallel_mng->commRank();
    String filename = _getMetaDataFileName(my_rank);
    std::ofstream ofile(filename.localstr());
    meta_data.writeBytes(ofile);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
beginWrite(const VariableCollection& vars)
{
  ARCANE_UNUSED(vars);
  Int32 my_rank = m_parallel_mng->commRank();
  m_global_writer->initialize(m_path,my_rank);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicWriter::
endWrite()
{
  IParallelMng* pm = m_parallel_mng;
  if (pm->isMasterIO()){
    Int64 nb_part = pm->commSize();
    if (m_version>=3){
      // Sauvegarde les informations au format JSON
      JSONWriter jsw;
      {
        JSONWriter::Object main_object(jsw);
        jsw.writeKey(_getArcaneDBTag());
        {
          JSONWriter::Object db_object(jsw);
          jsw.write("Version",(Int64)m_version);
          jsw.write("NbPart",nb_part);

          String data_compressor_name;
          Int64 data_compressor_min_size =0;
          if (m_data_compressor.get()){
            data_compressor_name = m_data_compressor->name();
            data_compressor_min_size = m_data_compressor->minCompressSize();
          }
          jsw.write("DataCompressor",data_compressor_name);
          jsw.write("DataCompressorMinSize",String::fromNumber(data_compressor_min_size));

          String hash_algorithm_name;
          if (m_hash_algorithm.get())
            hash_algorithm_name = m_hash_algorithm->name();
          jsw.write("HashAlgorithm",hash_algorithm_name);
        }
      }
      StringBuilder filename = m_path;
      filename += "/arcane_acr_db.json";
      String fn = filename.toString();
      std::ofstream ofile(fn.localstr());
      ofile << jsw.getBuffer();
    }
    else{
      StringBuilder filename = m_path;
      filename += "/infos.txt";
      String fn = filename.toString();
      std::ofstream ofile(fn.localstr());
      ofile << nb_part << '\n';
    }
  }
  m_global_writer->endWrite();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicReader::
BasicReader(IApplication* app,IParallelMng* pm,Int32 forced_rank_to_read,
            const String& path,bool want_parallel)
: BasicReaderWriterCommon(app,pm,path,BasicReaderWriterCommon::OpenModeRead)
, m_want_parallel(want_parallel)
, m_nb_written_part(0)
, m_version(-1)
, m_first_rank_to_read(0)
, m_nb_rank_to_read(0)
, m_forced_rank_to_read(forced_rank_to_read)
, m_item_group_finder(nullptr)
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
initialize()
{
  info() << "BasicReader::initialize()";

  IParallelMng* pm = m_parallel_mng;
  // Si un fichier 'arcane_acr_db.json' existe alors on lit les informations
  // de ce fichier pour détecter entre autre le numéro de version. Il faut
  // le faire avant de lire les informations telles que les méta-données
  // de la protection car l'emplacement des ces dernières dépend de la version
  String db_filename = String::concat(m_path,"/arcane_acr_db.json");
  Int32 has_db_file = 0;
  {
    if (pm->isMasterIO())
      has_db_file = platform::isFileReadable(db_filename) ? 1 : 0;
    pm->broadcast(Int32ArrayView(1,&has_db_file),pm->masterIORank());
  }
  String data_compressor_name;
  String hash_algorithm_name;
  if (has_db_file){
    UniqueArray<Byte> bytes;
    pm->ioMng()->collectiveRead(db_filename,bytes,false);
    JSONDocument json_doc;
    json_doc.parse(bytes,db_filename);
    JSONValue root = json_doc.root();
    JSONValue jv_arcane_db = root.expectedChild(_getArcaneDBTag());
    m_version = jv_arcane_db.expectedChild("Version").valueAsInt32();
    m_nb_written_part = jv_arcane_db.expectedChild("NbPart").valueAsInt32();
    data_compressor_name = jv_arcane_db.child("DataCompressor").value();
    hash_algorithm_name = jv_arcane_db.child("HashAlgorithm").value();
    info() << "**--** Begin read using database version=" << m_version
           << " nb_part=" << m_nb_written_part
           << " compressor=" << data_compressor_name
           << " hash_algorithm=" << hash_algorithm_name;
  }
  else{
    // Ancien format
    // Le proc maitre lit le fichier 'infos.txt' et envoie les informations
    // aux autres. Ce format ne permet d'avoir que le nombre de parties
    // comme information.
    if (pm->isMasterIO()){
      Integer nb_part = 0;
      String filename = String::concat(m_path,"/infos.txt");
      std::ifstream ifile(filename.localstr());
      ifile >> nb_part;
      info(4) << "** NB PART=" << nb_part;
      m_nb_written_part = nb_part;
    }
    pm->broadcast(Int32ArrayView(1,&m_nb_written_part),pm->masterIORank());
  }
  if (m_version>=3){
    Int32 rank_to_read = m_forced_rank_to_read;
    if (rank_to_read<0){
      if (m_nb_written_part>1)
        rank_to_read = pm->commRank();
      else
        rank_to_read = 0;
    }
    String main_filename = _getBasicVariableFile(m_version,m_path,rank_to_read);
    m_forced_rank_to_read_text_reader = makeRef(new KeyValueTextReader(traceMng(),main_filename,m_version));
    if (!data_compressor_name.empty()){
      Ref<IDataCompressor> dc = _createDeflater(m_application,data_compressor_name);
      m_forced_rank_to_read_text_reader->setDataCompressor(dc);
    }
    if (!hash_algorithm_name.empty()){
      Ref<IHashAlgorithm> v = _createHashAlgorithm(m_application,hash_algorithm_name);
      m_forced_rank_to_read_text_reader->setHashAlgorithm(v);
    }
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BasicReader::
~BasicReader()
{
  for( const auto& i : m_parallel_data_readers )
    delete i.second;
  for( const auto& r : m_global_readers )
    delete r;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
_directReadVal(VariableMetaData* varmd,IData* data)
{
  info(4) << "DIRECT READ VAL v=" << varmd->fullName();

  bool is_item_variable = !varmd->itemFamilyName().null();
  Int32 nb_rank_to_read = m_nb_rank_to_read;
  // S'il s'agit d'une variable qui n'est pas sur le maillage,
  // il ne faut lire qu'un seul rang car il n'est pas
  // certain que cette variable soit definie partout
  if (!is_item_variable)
    if (nb_rank_to_read>1)
      nb_rank_to_read = 1;
        
  UniqueArray<Ref<IData>> allocated_data;
  UniqueArray<IData*> written_data(nb_rank_to_read);

  for( Integer i=0; i<nb_rank_to_read; ++i ){
    written_data[i] = data;
    if ((nb_rank_to_read>1 || m_want_parallel) && is_item_variable){
      Ref<IData> new_data = data->cloneEmptyRef();
      written_data[i] = new_data.get();
      allocated_data.add(new_data);
    }
    String vname = varmd->fullName();
    info(4) << " TRY TO READ var_full_name=" << vname;
    m_global_readers[i]->readData(vname,written_data[i]);
  }
  
  if (is_item_variable){
    ParallelDataReader* parallel_data_reader = _getReader(varmd);

    Int64UniqueArray full_written_unique_ids;
    IData* full_written_data = nullptr;

    if (nb_rank_to_read==0){
      // Rien à lire
      // Il faut tout de même passer dans le reader parallèle
      // pour assurer les opérations collectives
      full_written_data = nullptr;
    }
    else if (nb_rank_to_read==1){
      //full_written_unique_ids = written_unique_ids[0];
      full_written_data = written_data[0];
    }
    else{
      // Il faut créer une donnée qui contient l'union des written_data
      Ref<IData> allocated_written_data = data->cloneEmptyRef();
      allocated_data.add(allocated_written_data);
      full_written_data = allocated_written_data.get();
      SerializeBuffer sbuf;
      sbuf.setMode(ISerializer::ModeReserve);
      for( Int32 i=0; i<nb_rank_to_read; ++i )
        written_data[i]->serialize(&sbuf,nullptr);
      sbuf.allocateBuffer();
      sbuf.setMode(ISerializer::ModePut);
      for( Int32 i=0; i<nb_rank_to_read; ++i )
        written_data[i]->serialize(&sbuf,nullptr);
      sbuf.setMode(ISerializer::ModeGet);
      sbuf.setReadMode(ISerializer::ReadAdd);
      for( Int32 i=0; i<nb_rank_to_read; ++i )
        full_written_data->serialize(&sbuf,nullptr);

    }
    if (data!=full_written_data){
      info(5) << "PARALLEL READ";
      parallel_data_reader->getSortedValues(full_written_data,data);
    }
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ParallelDataReader* BasicReader::
_getReader(VariableMetaData* varmd)
{
  Int32 nb_to_read = m_nb_rank_to_read;

  // Pour la lecture, lors d'une reprise, le groupe (var->itemGroup())
  // associé à la variable ainsi que la famille (var->itemFamily())
  // n'existe pas encore. Il ne faut donc pas l'utiliser
  const String& var_group_name = varmd->itemGroupName();
  String group_full_name = varmd->meshName()+ "_" + varmd->itemFamilyName() + "_" + var_group_name;
  auto ix = m_parallel_data_readers.find(group_full_name);
  if (ix!=m_parallel_data_readers.end())
    return ix->second;

  IParallelMng* pm = m_parallel_mng;
  auto reader = new ParallelDataReader(pm);
  {
    UniqueArray<SharedArray<Int64> > written_unique_ids(nb_to_read);
    Int64Array& wanted_unique_ids = reader->wantedUniqueIds();
    for( Integer i=0; i<nb_to_read; ++i ){
      m_global_readers[i]->readItemGroup(group_full_name,written_unique_ids[i],wanted_unique_ids);
    }
    // Cela ne doit être actif que pour les comparaisons (pas en reprise car les groupes
    // ne sont pas valides)
    if (m_item_group_finder){
      ItemGroup ig = m_item_group_finder->getWantedGroup(varmd);
      _fillUniqueIds(ig,wanted_unique_ids);
    }
    for( Integer i=0; i<nb_to_read; ++i ){
      Integer nb_uid = written_unique_ids[i].size();
      if (nb_uid>=1)
        info(5) << "PART I=" << i
               << " nb_uid=" << nb_uid
               << " min_uid=" << written_unique_ids[i][0]
               << " max_uid=" << written_unique_ids[i][nb_uid-1];
    }
    Int64Array& full_written_unique_ids = reader->writtenUniqueIds();
    for( Integer i=0; i<nb_to_read; ++i )
      for( Integer z=0, zs=written_unique_ids[i].size(); z<zs; ++z )
        full_written_unique_ids.add(written_unique_ids[i][z]);
    info(5) << "FULL UID SIZE=" << full_written_unique_ids.size();
    if (m_want_parallel)
      reader->sort();
  }
  m_parallel_data_readers.insert(std::make_pair(group_full_name,reader));
  return reader;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
read(IVariable* var,IData* data)
{
  info(4) << "MASTER READ var=" << var->fullName() << " data=" << data;
  if (var->isPartial()){
    info() << "** WARNING: partial variable not implemented in BasicReaderWriter";
    return;
  }
  ScopedPtrT<VariableMetaData> vmd(var->createMetaData());
  _directReadVal(vmd.get(),data);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
read(const VariableDataReadInfo& infos)
{
  VariableMetaData* vmd = infos.variableMetaData();
  IData* data = infos.data();
  info(4) << "MASTER2 READ var=" << vmd->fullName() << " data=" << data;
  if (vmd->isPartial()){
    info() << "** WARNING: partial variable not implemented in BasicReaderWriter";
    return;
  }
  _directReadVal(vmd,data);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

String BasicReader::
metaData()
{
  ByteUniqueArray bytes;
  fillMetaData(bytes);
  String s(bytes);
  info(5) << " S=" << s << '\n';
  return s;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
fillMetaData(ByteArray& bytes)
{
  Int32 rank = m_parallel_mng->commRank();
  if (m_forced_rank_to_read>=0)
    rank = m_forced_rank_to_read;
  if (m_version>=3){
    Int64 meta_data_size = 0;
    String key_name = "Global:CheckpointMetadata";
    info(4) << "Reading checkpoint metadata from database";
    m_forced_rank_to_read_text_reader->getExtents(key_name,Int64ArrayView(1,&meta_data_size));
    bytes.resize(meta_data_size);
    m_forced_rank_to_read_text_reader->read(key_name,asWritableBytes(bytes.span()));
  }
  else{
    String filename = _getMetaDataFileName(rank);
    info(4) << "Reading checkpoint metadata file=" << filename;
    platform::readAllFile(filename,false,bytes);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
_setRanksToRead()
{
  IParallelMng* pm = m_parallel_mng;
  Int32 my_rank = pm->commRank();
  Int32 nb_rank = pm->commSize();
  Int32 first_to_read = my_rank;
  Int32 nb_to_read = 1;

  if (m_forced_rank_to_read>=0){
    m_first_rank_to_read = m_forced_rank_to_read;
    m_nb_rank_to_read = 1;
    return;
  }
  if (nb_rank==1){
    nb_to_read = m_nb_written_part;
  }
  else if (nb_rank<m_nb_written_part){
    // Il y a plus de fichiers que de processeurs.
    // Un des processeurs doit donc lire au moins deux fichiers.
    // Pour ceux dont c'est le cas, il faut que ces fichiers
    // soient consécutifs pour que l'intervalle des uniqueId()
    // des entités du processeur soient consécutifs
    Int32 nb_part_per_rank = m_nb_written_part / nb_rank;
    Int32 remaining_nb_part = m_nb_written_part - (nb_part_per_rank*nb_rank);
    first_to_read = nb_part_per_rank * my_rank;
    nb_to_read = nb_part_per_rank;
    info(4) << "NB_PART_PER_RANK = " << nb_part_per_rank
            << " REMAINING=" << remaining_nb_part;
    if (my_rank>=remaining_nb_part){
      first_to_read += remaining_nb_part;
    }
    else{
      first_to_read += my_rank;
      ++nb_to_read;
    }
  }
  else{
    if (my_rank>=m_nb_written_part){
      // Aucune partie à lire
      nb_to_read = 0;
    }
  }

  m_first_rank_to_read = first_to_read;
  m_nb_rank_to_read = nb_to_read;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

IGenericReader* BasicReader::
_readOwnMetaDataAndCreateReader(Int32 rank)
{
  String main_filename = _getBasicVariableFile(m_version,m_path,rank);
  Ref<KeyValueTextReader> text_reader;
  if (m_version>=3){
    // Si le rang est le même que m_forced_rank_to_read, alors on peut réutiliser
    // le lecteur déjà créé.
    if (rank==m_forced_rank_to_read)
      text_reader = m_forced_rank_to_read_text_reader;
    else{
      text_reader = makeRef(new KeyValueTextReader(traceMng(),main_filename,m_version));
      // Il faut que ce lecteur ait le même gestionnaire de compression
      // que celui déjà créé
      text_reader->setDataCompressor(m_forced_rank_to_read_text_reader->dataCompressor());
      text_reader->setHashAlgorithm(m_forced_rank_to_read_text_reader->hashAlgorithm());
    }
  }

  auto r = new BasicGenericReader(m_application,m_version,text_reader);
  r->initialize(m_path,rank);
  return r;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
beginRead(const VariableCollection& vars)
{
  ARCANE_UNUSED(vars);
  beginRead(DataReaderInfo());
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void BasicReader::
beginRead(const DataReaderInfo& infos)
{
  ARCANE_UNUSED(infos);
  info(4) << "** ** BEGIN READ";

  _setRanksToRead();
  info(4) << "RanksToRead: FIRST TO READ =" << m_first_rank_to_read
          << " nb=" << m_nb_rank_to_read << " version=" << m_version;
  m_global_readers.resize(m_nb_rank_to_read);
  for( Integer i=0; i<m_nb_rank_to_read; ++i )
    m_global_readers[i] = _readOwnMetaDataAndCreateReader(i+m_first_rank_to_read);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
