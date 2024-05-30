/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:43
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANE_UNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANE_UNITTEST_H

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
class CaseOptionsUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsUnitTest(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"unit-test"))
    , test(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* allow-null */ false)
    , xmlTest(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "xml-test", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* allow-null */ false)
  {

test.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("test"));
xmlTest.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("xml-test"));
addAlternativeNodeName(
          /* language         */ Arcane::String("en"),
          /* alternative name */ Arcane::String("unit-test-module"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("module-test-unitaire"));
  }

public:
  // Interfaces for main CaseOptions
  
 
 
 
   Arcane::ConstArrayView< Arcane::IUnitTest* > getTest() { return test; }
   Arcane::ConstArrayView< Arcane::IXmlUnitTest* > getXmlTest() { return xmlTest; }
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

  
  Arcane::CaseOptionMultiServiceT< Arcane::IUnitTest  >   test;
  Arcane::CaseOptionMultiServiceT< Arcane::IXmlUnitTest  >   xmlTest;
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
// Arcane version 1.0 : 05/30/2024 13:53:43
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANE_UNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANE_UNITTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/EntryPoint.h"
#include "arcane/ISubDomain.h"
#include "arcane/ModuleBuildInfo.h"
#include "arcane/ModuleFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicModule.h"
#include "arcane/ServiceInfo.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{
class ISubDomain;
class IModule;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneUnitTestObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("UnitTest_arcane_std");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("unit-test"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("unit-test-module"),Arcane::String("en"));
    si->setTagName(Arcane::String("module-test-unitaire"),Arcane::String("fr"));
  }

public:

  ArcaneUnitTestObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsUnitTest(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "UnitTestInit", 
                  &ArcaneUnitTestObject::unitTestInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "UnitTestDoTest", 
                  &ArcaneUnitTestObject::unitTestDoTest,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "UnitTestExit", 
                  &ArcaneUnitTestObject::unitTestExit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneUnitTestObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void unitTestInit() = 0; // UnitTestInit
  virtual void unitTestDoTest() = 0; // UnitTestDoTest
  virtual void unitTestExit() = 0; // UnitTestExit

  //! Options du jeu de données du module
  CaseOptionsUnitTest* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsUnitTest* m_options;

protected:

  //! Variables du module
    
private:
 static Arcane::FileContent getAxlContent()
 {
   const char* str_content = "";
   const Arcane::Byte* content = (const Arcane::Byte*)(str_content);
   Arcane::Span<const Arcane::Byte> bytes(content,0);
   int file_version = 1;
   return Arcane::FileContent(bytes,file_version,"");
 }

};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define ARCANE_REGISTER_MODULE_UNITTEST(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("UnitTest",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

