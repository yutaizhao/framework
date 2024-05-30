/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PDESRANDOMNUMBERGENERATORUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PDESRANDOMNUMBERGENERATORUNITTEST_H

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
class CaseOptionsPDESRandomNumberGeneratorUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsPDESRandomNumberGeneratorUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , pdesRandomNumberGenerator(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "pdes-random-number-generator", _element(),
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
  
 
 
 
     Arcane::IRandomNumberGenerator* getPdesRandomNumberGenerator() { return pdesRandomNumberGenerator(); }
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

  
  Arcane::CaseOptionServiceT< Arcane::IRandomNumberGenerator >   pdesRandomNumberGenerator;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_PDESRANDOMNUMBERGENERATORUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_PDESRANDOMNUMBERGENERATORUNITTEST_H

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

class CaseOptionsPDESRandomNumberGeneratorUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcanePDESRandomNumberGeneratorUnitTestObject
  : public Arcane::BasicUnitTest
  , public Arcane::UnitTestServiceAdapter<ArcanePDESRandomNumberGeneratorUnitTestObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("PDESRandomNumberGeneratorUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("p-d-e-s-random-number-generator-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcanePDESRandomNumberGeneratorUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , Arcane::UnitTestServiceAdapter<ArcanePDESRandomNumberGeneratorUnitTestObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsPDESRandomNumberGeneratorUnitTest(co);
    }
    setClassSetUpFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::setUpForClass);
 
    setClassTearDownFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::tearDownForClass);
    setTestSetUpFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::setUp);
    setTestTearDownFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::tearDown);
    addTestFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::testHardcodedValues, "Test valeurs générées", "testHardcodedValues");
    addTestFunction(&ArcanePDESRandomNumberGeneratorUnitTestObject::testHardcodedSeeds, "Test graines générées", "testHardcodedSeeds");
	
  }

  //! Destructeur
  virtual ~ArcanePDESRandomNumberGeneratorUnitTestObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void testHardcodedValues() = 0;  //!< Test valeurs générées
  virtual void testHardcodedSeeds() = 0;  //!< Test graines générées

public:

  //! Options du jeu de données du service
  CaseOptionsPDESRandomNumberGeneratorUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsPDESRandomNumberGeneratorUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_PDESRANDOMNUMBERGENERATORUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

