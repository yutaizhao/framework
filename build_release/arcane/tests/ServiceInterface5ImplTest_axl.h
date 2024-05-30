/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SERVICEINTERFACE5IMPLTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SERVICEINTERFACE5IMPLTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/ItemGroup.h"
#include "arcane/CaseOptionService.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::CellGroup &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::CellGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsServiceInterface5ImplTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'complex5'
      // Generating simple arity CaseOption for option 'complex5'
  class CaseOptionComplex5
    : public Arcane::CaseOptions
  {
  public:

    CaseOptionComplex5(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , simpleReal2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , cellGroup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "cell-group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::CellGroup")
    {

    }
        
    const CaseOptionComplex5& operator()() const { return *this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::Real getSimpleReal2() { return simpleReal2(); }
 
 
    Arcane::CellGroup getCellGroup() { return cellGroup(); }
 
   // Interfaces for complex options
      bool hasSimpleReal2() const
      { return simpleReal2.isPresent(); }
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionReal    simpleReal2;
  Arcane::CaseOptionExtendedT< Arcane::CellGroup >   cellGroup;

  };
  // Generation for option 'multi-complex5'
      // Generating multiple arity CaseOption for complex option value 'multi-complex5'
  class CaseOptionMultiComplex5Value
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionMultiComplex5Value ThatClass;

    CaseOptionMultiComplex5Value(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , trueCellGroup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "true-cell-group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::CellGroup")

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsMultiComplex5
  
 
 
    Arcane::CellGroup getTrueCellGroup() { return trueCellGroup(); }
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionExtendedT< Arcane::CellGroup >   trueCellGroup;
  };

  // Generation for sub-option 'multi-complex5'
  class CaseOptionMultiComplex5
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionMultiComplex5Value * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionMultiComplex5Value * > BaseClass;

    typedef CaseOptionMultiComplex5Value value_type;

  public:

    CaseOptionMultiComplex5(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionMultiComplex5()
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
  
  CaseOptionsServiceInterface5ImplTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , subServiceInstance(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "sub-service-instance", _element(),
        /* default    */ "ServiceTestImpl1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , complex5(_configList(),
        /* name       */ "complex5", _element())
      , multiComplex5(_configList(),
        /* name       */ "multi-complex5", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
 
 
 
     ArcaneTest::IServiceInterface1* getSubServiceInstance() { return subServiceInstance(); }
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

  
  Arcane::CaseOptionServiceT< ArcaneTest::IServiceInterface1 >   subServiceInstance;
  CaseOptionComplex5   complex5;
  CaseOptionMultiComplex5   multiComplex5;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_SERVICEINTERFACE5IMPLTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_SERVICEINTERFACE5IMPLTEST_H

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

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsServiceInterface5ImplTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneServiceInterface5ImplTestObject
  : public Arcane::BasicCaseOptionService
  , public ArcaneTest::IServiceInterface1
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ServiceInterface5ImplTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("service-interface5-impl-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(ArcaneTest::IServiceInterface1)
);
  }
  
public:

  //! Constructeur
  ArcaneServiceInterface5ImplTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsServiceInterface5ImplTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneServiceInterface5ImplTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsServiceInterface5ImplTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsServiceInterface5ImplTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_SERVICEINTERFACE5IMPLTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

