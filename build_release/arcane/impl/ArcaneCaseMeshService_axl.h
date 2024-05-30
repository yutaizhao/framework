/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:50:19
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANECASEMESHSERVICE_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANECASEMESHSERVICE_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/CaseOptionService.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsArcaneCaseMeshService
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'variable'
      // Generating multiple arity CaseOption for complex option value 'variable'
  class CaseOptionInitVariableValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionInitVariableValue ThatClass;

    CaseOptionInitVariableValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , value(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "value", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , group(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsInitVariable
  
    Arcane::String getName() { return name(); }
    Arcane::String getValue() { return value(); }
    Arcane::String getGroup() { return group(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  Arcane::CaseOptionString    value;
  Arcane::CaseOptionString    group;
  };

  // Generation for sub-option 'variable'
  class CaseOptionInitVariable
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionInitVariableValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionInitVariableValue * > BaseClass;

    typedef CaseOptionInitVariableValue value_type;

  public:

    CaseOptionInitVariable(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
    {
    // Generating translations and default values.
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

    ~CaseOptionInitVariable()
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
  
  // Generation for option 'initialization'
      // Generating simple arity CaseOption for option 'initialization'
  class CaseOptionInit
    : public Arcane::CaseOptions
  {
  public:

    CaseOptionInit(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , variable(_configList(),
        /* name       */ "variable", _element())
    {

    }
        
    const CaseOptionInit& operator()() const { return *this; }

 public:
  // Interfaces for simple arity CaseOptions
  
 
 
 
   // Interfaces for complex options
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  CaseOptionInitVariable   variable;

  };

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcaneCaseMeshService(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , filename(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "filename", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , partitioner(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "partitioner", _element(),
        /* default    */ "DefaultPartitioner",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbGhostLayer(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-ghost-layer", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , ghostLayerBuilderVersion(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "ghost-layer-builder-version", _element(),
        /* default    */ "3",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , generator(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "generator", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
      , specificReader(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "specific-reader", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
      , initialization(_configList(),
        /* name       */ "initialization", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::String getFilename() { return filename(); }
    Arcane::String getPartitioner() { return partitioner(); }
    Arcane::Int32 getNbGhostLayer() { return nbGhostLayer(); }
    Arcane::Int32 getGhostLayerBuilderVersion() { return ghostLayerBuilderVersion(); }
 
 
 
     Arcane::IMeshBuilder* getGenerator() { return generator(); }
    Arcane::ICaseMeshReader* getSpecificReader() { return specificReader(); }
  // Interfaces for complex options
      bool hasGenerator() const
      { return generator.isPresent(); }
      bool hasFilename() const
      { return filename.isPresent(); }
      bool hasSpecificReader() const
      { return specificReader.isPresent(); }
  
  
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

  
  Arcane::CaseOptionString    filename;
  Arcane::CaseOptionString    partitioner;
  Arcane::CaseOptionInt32    nbGhostLayer;
  Arcane::CaseOptionInt32    ghostLayerBuilderVersion;
  Arcane::CaseOptionServiceT< Arcane::IMeshBuilder >   generator;
  Arcane::CaseOptionServiceT< Arcane::ICaseMeshReader >   specificReader;
  CaseOptionInit   initialization;
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
// Arcane version 1.0 : 05/30/2024 13:50:19
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANECASEMESHSERVICE_H
#define ARCANE_MODULE_AXLSTAR_ARCANECASEMESHSERVICE_H

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

namespace Arcane
{
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsArcaneCaseMeshService;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneArcaneCaseMeshServiceObject
  : public AbstractService
  , public Arcane::ICaseMeshService
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneCaseMeshService_arcane_impl");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("arcane-case-mesh-service");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::ICaseMeshService)
);
  }
  
public:

  //! Constructeur
  ArcaneArcaneCaseMeshServiceObject(const Arcane::ServiceBuildInfo& sbi)
    : AbstractService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsArcaneCaseMeshService(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneArcaneCaseMeshServiceObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsArcaneCaseMeshService* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsArcaneCaseMeshService* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_ARCANECASEMESHSERVICE(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

