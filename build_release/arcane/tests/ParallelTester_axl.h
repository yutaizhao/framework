/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PARALLELTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PARALLELTESTER_H

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
class CaseOptionsParallelTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsParallelTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"parallel-tester"))
      , nbIteration(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-iteration", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , outputFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-file", _element(),
        /* default    */ "test",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbInternalLoop(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-internal-loop", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbTestSync(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-test-sync", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
    , loadBalanceService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "load-balance-service", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false)
     , testId(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-id", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesParallelTester::eTestParallel")
  {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("TestAll"),
          /* enum object     */ (int)(TypesParallelTester::TestAll));
        testId.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("None"),
          /* enum object     */ (int)(TypesParallelTester::TestNone));
        testId.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("LoadBalance"),
          /* enum object     */ (int)(TypesParallelTester::TestLoadBalance));
        testId.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("GhostItemsReduceOperation"),
          /* enum object     */ (int)(TypesParallelTester::TestGhostItemsReduceOperation));
        testId.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("GetVariableValues"),
          /* enum object     */ (int)(TypesParallelTester::TestGetVariableValues));
        testId.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("TransferValues"),
          /* enum object     */ (int)(TypesParallelTester::TestTransferValues));
        testId.addEnumValue(x,false);
      }
outputFile.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("fichier-sortie"));
nbInternalLoop.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-boucles-internes"));
nbTestSync.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-test-sync"));
loadBalanceService.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("service-equilibrage-charge"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getNbIteration() { return nbIteration(); }
    Arcane::String getOutputFile() { return outputFile(); }
    Arcane::Integer getNbInternalLoop() { return nbInternalLoop(); }
    Arcane::Integer getNbTestSync() { return nbTestSync(); }
 
 
     TypesParallelTester::eTestParallel getTestId() { return testId(); }
 
   Arcane::ConstArrayView< Arcane::IMeshPartitioner* > getLoadBalanceService() { return loadBalanceService; }
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

  
  Arcane::CaseOptionInteger    nbIteration;
  Arcane::CaseOptionString    outputFile;
  Arcane::CaseOptionInteger    nbInternalLoop;
  Arcane::CaseOptionInteger    nbTestSync;
  Arcane::CaseOptionMultiServiceT< Arcane::IMeshPartitioner  >   loadBalanceService;
  Arcane::CaseOptionEnumT< TypesParallelTester::eTestParallel >   testId;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_PARALLELTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_PARALLELTESTER_H

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

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsParallelTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneParallelTesterObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ParallelTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("parallel-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneParallelTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsParallelTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
  }

  virtual ~ArcaneParallelTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée

  //! Options du jeu de données du module
  CaseOptionsParallelTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsParallelTester* m_options;

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

#define ARCANE_REGISTER_MODULE_PARALLELTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("ParallelTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

