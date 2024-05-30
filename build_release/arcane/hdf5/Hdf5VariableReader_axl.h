/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:15
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANE_HDF5VARIABLEREADER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANE_HDF5VARIABLEREADER_H

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
class CaseOptionsHdf5VariableReader
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'read'
      // Generating multiple arity CaseOption for complex option value 'read'
  class CaseOptionReadValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionReadValue ThatClass;

    CaseOptionReadValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
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
  // Interfaces for multi-arity class CaseOptionsRead
  
    Arcane::String getMeshName() { return meshName(); }
    Arcane::String getFileName() { return fileName(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    meshName;
  Arcane::CaseOptionString    fileName;
  };

  // Generation for sub-option 'read'
  class CaseOptionRead
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionReadValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionReadValue * > BaseClass;

    typedef CaseOptionReadValue value_type;

  public:

    CaseOptionRead(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
    {
    // Generating translations and default values.
    addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("lecture"));
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

    ~CaseOptionRead()
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
  
  CaseOptionsHdf5VariableReader(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , read(_configList(),
        /* name       */ "read", _element())
  {

read.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("lecture"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("lecteur-variable-hdf5"));
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

  
  CaseOptionRead   read;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANE_HDF5VARIABLEREADER_H
#define ARCANE_MODULE_AXLSTAR_ARCANE_HDF5VARIABLEREADER_H

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

class CaseOptionsHdf5VariableReader;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneHdf5VariableReaderObject
  : public BasicTimeLoopService
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("Hdf5VariableReader_arcane_hdf5");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("hdf5-variable-reader");
    si->setAxlContent(getAxlContent());
    si->setTagName("lecteur-variable-hdf5","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::ITimeLoopService)
);
  }
  
public:

  //! Constructeur
  ArcaneHdf5VariableReaderObject(const Arcane::ServiceBuildInfo& sbi)
    : BasicTimeLoopService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsHdf5VariableReader(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneHdf5VariableReaderObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsHdf5VariableReader* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsHdf5VariableReader* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_HDF5VARIABLEREADER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

