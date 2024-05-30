/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:15
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANE_HDF5VARIABLEWRITER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANE_HDF5VARIABLEWRITER_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsHdf5VariableWriter
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'write'
      // Generating multiple arity CaseOption for complex option value 'write'
  class CaseOptionWriteValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionWriteValue ThatClass;

    CaseOptionWriteValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , meshName(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "mesh-name", _element(),
        /* default    */ "Mesh0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , fileName(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "file-name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {

meshName.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nom-maillage"));
fileName.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nom-fichier"));

    }
 public:
  // Interfaces for multi-arity class CaseOptionsWrite
  
    Arcane::String getMeshName() { return meshName(); }
    Arcane::String getFileName() { return fileName(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    meshName;
  Arcane::CaseOptionString    fileName;
  };

  // Generation for sub-option 'write'
  class CaseOptionWrite
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionWriteValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionWriteValue * > BaseClass;

    typedef CaseOptionWriteValue value_type;

  public:

    CaseOptionWrite(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
    {
    // Generating translations and default values.
    addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("ecriture"));
    }

    BaseClass operator()() { return (*this); }

  protected:
    void multiAllocate(const Arcane::XmlNodeList& elist)
    {
      Arcane::Integer s = elist.size();
      value_type** v = 0;
      if (s!=0)
        v = new value_type*[s];
      _setArray(v,s);
      v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
      }
    }

  public:

    ~CaseOptionWrite()
    {
      Arcane::Integer s = count();
      if (s==0) return;
      value_type** v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        delete v[i];
      }
      delete[] v;
    }

  public:

    const value_type& operator[](Arcane::Integer i) const
      { return *(BaseClass::operator[](i)); }
    value_type& operator[](Arcane::Integer i)
      { return *(BaseClass::operator[](i)); }
    Arcane::Integer count() const
      { return BaseClass::size(); }
    Arcane::Integer size() const
      { return BaseClass::size(); }

  };
  

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsHdf5VariableWriter(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , write(_configList(),
        /* name       */ "write", _element())
  {

write.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("ecriture"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("ecrivain-variable-hdf5"));
  }

public:
  // Interfaces for main CaseOptions
  
 
 
 
   // Interfaces for complex options
  
  
public:

  Arcane::ICaseOptions* caseOptions() const 
  { 
    return m_case_options.get();
  }
  
  Arcane::ICaseOptionList* configList() const 
  {
    return m_case_options->configList(); 
  }
  
  void setCaseModule(Arcane::IModule* m) 
  { 
    m_case_options->setCaseModule(m); 
  }
  
  void setCaseServiceInfo(Arcane::IServiceInfo* si) 
  {
    m_case_options->setCaseServiceInfo(si); 
  }
  
  void addAlternativeNodeName(const Arcane::String& lang,
                              const Arcane::String& name)
  { 
    m_case_options->addAlternativeNodeName(lang,name); 
  }

private:

  Arcane::ICaseOptionList* _configList() const { return configList(); }
  Arcane::XmlNode _element() const { return Arcane::XmlNode(); }

private:

  static Arcane::ICaseOptions* _createCaseOption(Arcane::ICaseMng* cm,Arcane::ICaseOptions* co);

  Arcane::ReferenceCounter<Arcane::ICaseOptions> m_case_options;

public:

  
  CaseOptionWrite   write;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:15
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANE_HDF5VARIABLEWRITER_H
#define ARCANE_MODULE_AXLSTAR_ARCANE_HDF5VARIABLEWRITER_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/ServiceInfo.h"
#include "arcane/ISubDomain.h"
#include "arcane/ServiceBuildInfo.h"
#include "arcane/ServiceFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicService.h"

#ifndef ARCANE_HAS_SPECIFIC_BASIC_SERVICE
// Code pour les versions de Arcane avant la 3.8 qui ne possèdent pas les
// classes de base spécifiques pour les services
namespace Arcane
{
using BasicCaseOptionService = BasicService;
using BasicSubDomainService = BasicService;
using BasicMeshService = BasicService;
}
#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsHdf5VariableWriter;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneHdf5VariableWriterObject
  : public BasicTimeLoopService
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("Hdf5VariableWriter_arcane_hdf5");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("hdf5-variable-writer");
    si->setAxlContent(getAxlContent());
    si->setTagName("ecrivain-variable-hdf5","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::ITimeLoopService)
);
  }
  
public:

  //! Constructeur
  ArcaneHdf5VariableWriterObject(const Arcane::ServiceBuildInfo& sbi)
    : BasicTimeLoopService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsHdf5VariableWriter(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneHdf5VariableWriterObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsHdf5VariableWriter* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsHdf5VariableWriter* m_options;
      
protected:

  //! Variables du service
private:
  static Arcane::FileContent getAxlContent()
 {
   const Arcane::Byte* content = (const Arcane::Byte*)"";
   Arcane::Span<const Arcane::Byte> bytes(content,0);
   int file_version = 1;
   return Arcane::FileContent(bytes,file_version,"");
 }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define ARCANE_REGISTER_SERVICE_HDF5VARIABLEWRITER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

