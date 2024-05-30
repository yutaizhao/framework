/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SIMPLETABLECOMPARATORUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SIMPLETABLECOMPARATORUNITTEST_H

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
class CaseOptionsSimpleTableComparatorUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsSimpleTableComparatorUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , simpleTableComparator(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-table-comparator", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , simpleTableOutput(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-table-output", _element(),
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
  
 
 
 
     Arcane::ISimpleTableComparator* getSimpleTableComparator() { return simpleTableComparator(); }
    Arcane::ISimpleTableOutput* getSimpleTableOutput() { return simpleTableOutput(); }
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

  
  Arcane::CaseOptionServiceT< Arcane::ISimpleTableComparator >   simpleTableComparator;
  Arcane::CaseOptionServiceT< Arcane::ISimpleTableOutput >   simpleTableOutput;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_SIMPLETABLECOMPARATORUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_SIMPLETABLECOMPARATORUNITTEST_H

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

class CaseOptionsSimpleTableComparatorUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneSimpleTableComparatorUnitTestObject
  : public Arcane::BasicUnitTest
  , public Arcane::UnitTestServiceAdapter<ArcaneSimpleTableComparatorUnitTestObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("SimpleTableComparatorUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("simple-table-comparator-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneSimpleTableComparatorUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , Arcane::UnitTestServiceAdapter<ArcaneSimpleTableComparatorUnitTestObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsSimpleTableComparatorUnitTest(co);
    }
    setClassSetUpFunction(&ArcaneSimpleTableComparatorUnitTestObject::setUpForClass);
 
    setClassTearDownFunction(&ArcaneSimpleTableComparatorUnitTestObject::tearDownForClass);
    setTestSetUpFunction(&ArcaneSimpleTableComparatorUnitTestObject::setUp);
    setTestTearDownFunction(&ArcaneSimpleTableComparatorUnitTestObject::tearDown);
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testSimple, "Test simple", "testSimple");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testFullReal, "Test real", "testFullReal");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testError, "Test error", "testError");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testIncludeRow, "Test include row", "testIncludeRow");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testIncludeColumn, "Test include column", "testIncludeColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testIncludeRowColumn, "Test include row and column", "testIncludeRowColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testRegexRow, "Test regex row", "testRegexRow");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testRegexColumn, "Test regex column", "testRegexColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testRegexRowColumn, "Test regex row and column", "testRegexRowColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testEpsilonRow, "Test epsilon row", "testEpsilonRow");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testEpsilonColumn, "Test epsilon column", "testEpsilonColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testEpsilonRowColumn, "Test epsilon row and column", "testEpsilonRowColumn");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testCompareOneElem, "Test compare one elem", "testCompareOneElem");
    addTestFunction(&ArcaneSimpleTableComparatorUnitTestObject::testCompareWithElem, "Test compare with elem", "testCompareWithElem");
	
  }

  //! Destructeur
  virtual ~ArcaneSimpleTableComparatorUnitTestObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void testSimple() = 0;  //!< Test simple
  virtual void testFullReal() = 0;  //!< Test real
  virtual void testError() = 0;  //!< Test error
  virtual void testIncludeRow() = 0;  //!< Test include row
  virtual void testIncludeColumn() = 0;  //!< Test include column
  virtual void testIncludeRowColumn() = 0;  //!< Test include row and column
  virtual void testRegexRow() = 0;  //!< Test regex row
  virtual void testRegexColumn() = 0;  //!< Test regex column
  virtual void testRegexRowColumn() = 0;  //!< Test regex row and column
  virtual void testEpsilonRow() = 0;  //!< Test epsilon row
  virtual void testEpsilonColumn() = 0;  //!< Test epsilon column
  virtual void testEpsilonRowColumn() = 0;  //!< Test epsilon row and column
  virtual void testCompareOneElem() = 0;  //!< Test compare one elem
  virtual void testCompareWithElem() = 0;  //!< Test compare with elem

public:

  //! Options du jeu de données du service
  CaseOptionsSimpleTableComparatorUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsSimpleTableComparatorUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_SIMPLETABLECOMPARATORUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

