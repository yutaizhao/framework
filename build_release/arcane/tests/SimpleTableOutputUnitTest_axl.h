/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SIMPLETABLEOUTPUTUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_SIMPLETABLEOUTPUTUNITTEST_H

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
class CaseOptionsSimpleTableOutputUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsSimpleTableOutputUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_SIMPLETABLEOUTPUTUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_SIMPLETABLEOUTPUTUNITTEST_H

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

class CaseOptionsSimpleTableOutputUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneSimpleTableOutputUnitTestObject
  : public Arcane::BasicUnitTest
  , public Arcane::UnitTestServiceAdapter<ArcaneSimpleTableOutputUnitTestObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("SimpleTableOutputUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("simple-table-output-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneSimpleTableOutputUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , Arcane::UnitTestServiceAdapter<ArcaneSimpleTableOutputUnitTestObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsSimpleTableOutputUnitTest(co);
    }
    setClassSetUpFunction(&ArcaneSimpleTableOutputUnitTestObject::setUpForClass);
 
    setClassTearDownFunction(&ArcaneSimpleTableOutputUnitTestObject::tearDownForClass);
    setTestSetUpFunction(&ArcaneSimpleTableOutputUnitTestObject::setUp);
    setTestTearDownFunction(&ArcaneSimpleTableOutputUnitTestObject::tearDown);
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testInit, "Test initial", "testInit");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRow1, "Test addRow() 1", "testAddRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRow2, "Test addRow() 2", "testAddRow2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRow3, "Test addRow() 3", "testAddRow3");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRows1, "Test addRows() 1", "testAddRows1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumn1, "Test addColumn() 1", "testAddColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumn2, "Test addColumn() 2", "testAddColumn2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumn3, "Test addColumn() 3", "testAddColumn3");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumn4, "Test addColumn() 4", "testAddColumn4");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumns1, "Test addColumns() 1", "testAddColumns1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemRow1, "Test addElementInRow() 1", "testAddElemRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemRow2, "Test addElementInRow() 2", "testAddElemRow2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemSameRow1, "Test addElementInSameRow() 1", "testAddElemSameRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsRow1, "Test addElementsInRow() 1", "testAddElemsRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsRow2, "Test addElementsInRow() 2", "testAddElemsRow2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsSameRow1, "Test addElementsInSameRow() 1", "testAddElemsSameRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemColumn1, "Test addElementInColumn() 1", "testAddElemColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemColumn2, "Test addElementInColumn() 2", "testAddElemColumn2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemSameColumn1, "Test addElementInSameColumn() 1", "testAddElemSameColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsColumn1, "Test addElementsInColumn() 1", "testAddElemsColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsColumn2, "Test addElementsInColumn() 2", "testAddElemsColumn2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemsSameColumn1, "Test addElementsInSameColumn() 1", "testAddElemsSameColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddElemSame1, "Test addElementInSameColumn/Row() 1", "testAddElemSame1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditElem1, "Test editElement() 1", "testEditElem1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditElem2, "Test editElement() 2", "testEditElem2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testElem1, "Test element() 1", "testElem1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testElem2, "Test element() 2", "testElem2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testSizeRow1, "Test rowSize() 1", "testSizeRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testSizeRow2, "Test rowSize() 2", "testSizeRow2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testSizeColumn1, "Test columnSize() 1", "testSizeColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testSizeColumn2, "Test columnSize() 2", "testSizeColumn2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testPosRowColumn1, "Test posRowColumn() 1", "testPosRowColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testNumRowColumn1, "Test numRowColumn() 1", "testNumRowColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRowSameColumn1, "Test addElementInRow() / addElementInSameColumn() 1", "testAddRowSameColumn1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRowSameColumn2, "Test addElementInRow() / addElementInSameColumn() 2", "testAddRowSameColumn2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddRowSameColumn3, "Test addElementInRow() / addElementInSameColumn() 3", "testAddRowSameColumn3");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumnSameRow1, "Test addElementInColumn() / addElementInSameRow() 1", "testAddColumnSameRow1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumnSameRow2, "Test addElementInColumn() / addElementInSameRow() 2", "testAddColumnSameRow2");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testAddColumnSameRow3, "Test addElementInColumn() / addElementInSameRow() 3", "testAddColumnSameRow3");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditElemUDLR1, "Test editElementUp/Down/Left/Right() 1", "testEditElemUDLR1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditElemDown1, "Test editElementDown() 1", "testEditElemDown1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditElemRight1, "Test editElementRight() 1", "testEditElemRight1");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditNameRow, "Test editRowName()", "testEditNameRow");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testEditNameColumn, "Test editColumnName()", "testEditNameColumn");
    addTestFunction(&ArcaneSimpleTableOutputUnitTestObject::testWriteFile, "Test writeFile()", "testWriteFile");
	
  }

  //! Destructeur
  virtual ~ArcaneSimpleTableOutputUnitTestObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void testInit() = 0;  //!< Test initial
  virtual void testAddRow1() = 0;  //!< Test addRow() 1
  virtual void testAddRow2() = 0;  //!< Test addRow() 2
  virtual void testAddRow3() = 0;  //!< Test addRow() 3
  virtual void testAddRows1() = 0;  //!< Test addRows() 1
  virtual void testAddColumn1() = 0;  //!< Test addColumn() 1
  virtual void testAddColumn2() = 0;  //!< Test addColumn() 2
  virtual void testAddColumn3() = 0;  //!< Test addColumn() 3
  virtual void testAddColumn4() = 0;  //!< Test addColumn() 4
  virtual void testAddColumns1() = 0;  //!< Test addColumns() 1
  virtual void testAddElemRow1() = 0;  //!< Test addElementInRow() 1
  virtual void testAddElemRow2() = 0;  //!< Test addElementInRow() 2
  virtual void testAddElemSameRow1() = 0;  //!< Test addElementInSameRow() 1
  virtual void testAddElemsRow1() = 0;  //!< Test addElementsInRow() 1
  virtual void testAddElemsRow2() = 0;  //!< Test addElementsInRow() 2
  virtual void testAddElemsSameRow1() = 0;  //!< Test addElementsInSameRow() 1
  virtual void testAddElemColumn1() = 0;  //!< Test addElementInColumn() 1
  virtual void testAddElemColumn2() = 0;  //!< Test addElementInColumn() 2
  virtual void testAddElemSameColumn1() = 0;  //!< Test addElementInSameColumn() 1
  virtual void testAddElemsColumn1() = 0;  //!< Test addElementsInColumn() 1
  virtual void testAddElemsColumn2() = 0;  //!< Test addElementsInColumn() 2
  virtual void testAddElemsSameColumn1() = 0;  //!< Test addElementsInSameColumn() 1
  virtual void testAddElemSame1() = 0;  //!< Test addElementInSameColumn/Row() 1
  virtual void testEditElem1() = 0;  //!< Test editElement() 1
  virtual void testEditElem2() = 0;  //!< Test editElement() 2
  virtual void testElem1() = 0;  //!< Test element() 1
  virtual void testElem2() = 0;  //!< Test element() 2
  virtual void testSizeRow1() = 0;  //!< Test rowSize() 1
  virtual void testSizeRow2() = 0;  //!< Test rowSize() 2
  virtual void testSizeColumn1() = 0;  //!< Test columnSize() 1
  virtual void testSizeColumn2() = 0;  //!< Test columnSize() 2
  virtual void testPosRowColumn1() = 0;  //!< Test posRowColumn() 1
  virtual void testNumRowColumn1() = 0;  //!< Test numRowColumn() 1
  virtual void testAddRowSameColumn1() = 0;  //!< Test addElementInRow() / addElementInSameColumn() 1
  virtual void testAddRowSameColumn2() = 0;  //!< Test addElementInRow() / addElementInSameColumn() 2
  virtual void testAddRowSameColumn3() = 0;  //!< Test addElementInRow() / addElementInSameColumn() 3
  virtual void testAddColumnSameRow1() = 0;  //!< Test addElementInColumn() / addElementInSameRow() 1
  virtual void testAddColumnSameRow2() = 0;  //!< Test addElementInColumn() / addElementInSameRow() 2
  virtual void testAddColumnSameRow3() = 0;  //!< Test addElementInColumn() / addElementInSameRow() 3
  virtual void testEditElemUDLR1() = 0;  //!< Test editElementUp/Down/Left/Right() 1
  virtual void testEditElemDown1() = 0;  //!< Test editElementDown() 1
  virtual void testEditElemRight1() = 0;  //!< Test editElementRight() 1
  virtual void testEditNameRow() = 0;  //!< Test editRowName()
  virtual void testEditNameColumn() = 0;  //!< Test editColumnName()
  virtual void testWriteFile() = 0;  //!< Test writeFile()

public:

  //! Options du jeu de données du service
  CaseOptionsSimpleTableOutputUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsSimpleTableOutputUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_SIMPLETABLEOUTPUTUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

