/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_TESTUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_TESTUNITTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsTestUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsTestUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , myInt(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "my-int", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , myDouble(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "my-double", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , myBoolean(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "my-boolean", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32 getMyInt() { return myInt(); }
    Arcane::Real getMyDouble() { return myDouble(); }
    bool getMyBoolean() { return myBoolean(); }
 
 
 
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

  
  Arcane::CaseOptionInt32    myInt;
  Arcane::CaseOptionReal    myDouble;
  Arcane::CaseOptionBool    myBoolean;
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
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_TESTUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_TESTUNITTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/ServiceInfo.h"
#include "arcane/ISubDomain.h"
#include "arcane/ServiceBuildInfo.h"
#include "arcane/ServiceFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicService.h"
#include "arcane/UnitTestServiceAdapter.h"

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

class CaseOptionsTestUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneTestUnitTestObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::UnitTestServiceAdapter<ArcaneTestUnitTestObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("TestUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("test-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(ArcaneTest::ITestBidonInterface)
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneTestUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , Arcane::UnitTestServiceAdapter<ArcaneTestUnitTestObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsTestUnitTest(co);
    }
    setClassSetUpFunction(&ArcaneTestUnitTestObject::setUpForClass);
 
    setClassTearDownFunction(&ArcaneTestUnitTestObject::tearDownForClass);
    setTestSetUpFunction(&ArcaneTestUnitTestObject::setUp);
    setTestTearDownFunction(&ArcaneTestUnitTestObject::tearDown);
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod1, "Test 1", "myTestMethod1");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod2, "Test 2", "myTestMethod2");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod3, "Test 3", "myTestMethod3");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod4, "Test 4", "myTestMethod4");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod5, "Test 5", "myTestMethod5");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod1Parallel, "Test 6 (parallel)", "myTestMethod1Parallel");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod2Parallel, "Test 7 (parallel)", "myTestMethod2Parallel");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod3Parallel, "Test 8 (parallel)", "myTestMethod3Parallel");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod4Parallel, "Test 9 (parallel)", "myTestMethod4Parallel");
    addTestFunction(&ArcaneTestUnitTestObject::myTestMethod5Parallel, "Test 10 (parallel)", "myTestMethod5Parallel");
	
  }

  //! Destructeur
  virtual ~ArcaneTestUnitTestObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void myTestMethod1() = 0;  //!< Test 1
  virtual void myTestMethod2() = 0;  //!< Test 2
  virtual void myTestMethod3() = 0;  //!< Test 3
  virtual void myTestMethod4() = 0;  //!< Test 4
  virtual void myTestMethod5() = 0;  //!< Test 5
  virtual void myTestMethod1Parallel() = 0;  //!< Test 6 (parallel)
  virtual void myTestMethod2Parallel() = 0;  //!< Test 7 (parallel)
  virtual void myTestMethod3Parallel() = 0;  //!< Test 8 (parallel)
  virtual void myTestMethod4Parallel() = 0;  //!< Test 9 (parallel)
  virtual void myTestMethod5Parallel() = 0;  //!< Test 10 (parallel)

public:

  //! Options du jeu de données du service
  CaseOptionsTestUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsTestUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_TESTUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

