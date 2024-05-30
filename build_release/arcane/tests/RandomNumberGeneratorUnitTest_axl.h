/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_RANDOMNUMBERGENERATORUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_RANDOMNUMBERGENERATORUNITTEST_H

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

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsRandomNumberGeneratorUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsRandomNumberGeneratorUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , randomNumberGenerator(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "random-number-generator", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
  {

  }

public:
  // Interfaces for main CaseOptions
  
 
 
 
     Arcane::IRandomNumberGenerator* getRandomNumberGenerator() { return randomNumberGenerator(); }
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

  
  Arcane::CaseOptionServiceT< Arcane::IRandomNumberGenerator >   randomNumberGenerator;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_RANDOMNUMBERGENERATORUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_RANDOMNUMBERGENERATORUNITTEST_H

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

class CaseOptionsRandomNumberGeneratorUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneRandomNumberGeneratorUnitTestObject
  : public Arcane::BasicUnitTest
  , public Arcane::UnitTestServiceAdapter<ArcaneRandomNumberGeneratorUnitTestObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("RandomNumberGeneratorUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("random-number-generator-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneRandomNumberGeneratorUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , Arcane::UnitTestServiceAdapter<ArcaneRandomNumberGeneratorUnitTestObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsRandomNumberGeneratorUnitTest(co);
    }
    setClassSetUpFunction(&ArcaneRandomNumberGeneratorUnitTestObject::setUpForClass);
 
    setClassTearDownFunction(&ArcaneRandomNumberGeneratorUnitTestObject::tearDownForClass);
    setTestSetUpFunction(&ArcaneRandomNumberGeneratorUnitTestObject::setUp);
    setTestTearDownFunction(&ArcaneRandomNumberGeneratorUnitTestObject::tearDown);
    addTestFunction(&ArcaneRandomNumberGeneratorUnitTestObject::testMcPi, "Test Pi", "testMcPi");
    addTestFunction(&ArcaneRandomNumberGeneratorUnitTestObject::testLeepNumbers, "Test leap RNG", "testLeepNumbers");
    addTestFunction(&ArcaneRandomNumberGeneratorUnitTestObject::testLeepSeeds, "Test leap RSG", "testLeepSeeds");
	
  }

  //! Destructeur
  virtual ~ArcaneRandomNumberGeneratorUnitTestObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void testMcPi() = 0;  //!< Test Pi
  virtual void testLeepNumbers() = 0;  //!< Test leap RNG
  virtual void testLeepSeeds() = 0;  //!< Test leap RSG

public:

  //! Options du jeu de données du service
  CaseOptionsRandomNumberGeneratorUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsRandomNumberGeneratorUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_RANDOMNUMBERGENERATORUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
