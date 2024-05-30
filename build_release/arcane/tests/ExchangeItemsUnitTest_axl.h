/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_EXCHANGEITEMSUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_EXCHANGEITEMSUNITTEST_H

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
class CaseOptionsExchangeItemsUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsExchangeItemsUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
     , testOperation(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-operation", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TestOperation")
  {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("repartition-cells"),
          /* enum object     */ (int)(TestOperation::GatherBroadcastCells));
        testOperation.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("exchange-cell-owners"),
          /* enum object     */ (int)(TestOperation::ExchangeCellOwners));
        testOperation.addEnumValue(x,false);
      }
  }

public:
  // Interfaces for main CaseOptions
  
 
 
     TestOperation getTestOperation() { return testOperation(); }
 
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

  
  Arcane::CaseOptionEnumT< TestOperation >   testOperation;
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
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_EXCHANGEITEMSUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_EXCHANGEITEMSUNITTEST_H

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

class CaseOptionsExchangeItemsUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneExchangeItemsUnitTestObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ExchangeItemsUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("exchange-items-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneExchangeItemsUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
    , m_cell_uids(Arcane::VariableBuildInfo(sbi.meshHandle(), "ExchangeItemsTest_CellUids" , Arcane::IVariable::PNoDump))
    , m_ghostpp(Arcane::VariableBuildInfo(sbi.meshHandle(), "GhostPP" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_node_ghostpp(Arcane::VariableBuildInfo(sbi.meshHandle(), "NodeGhostPP" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_face_ghostpp(Arcane::VariableBuildInfo(sbi.meshHandle(), "FaceGhostPP" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsExchangeItemsUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneExchangeItemsUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsExchangeItemsUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsExchangeItemsUnitTest* m_options;
      
protected:

  //! Variables du service
  Arcane::VariableCellInt64 m_cell_uids;
  Arcane::VariableCellArrayInteger m_ghostpp;
  Arcane::VariableNodeArrayInteger m_node_ghostpp;
  Arcane::VariableFaceArrayInteger m_face_ghostpp;
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

#define ARCANE_REGISTER_SERVICE_EXCHANGEITEMSUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

