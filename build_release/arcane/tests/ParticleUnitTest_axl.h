/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PARTICLEUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_PARTICLEUNITTEST_H

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
class CaseOptionsParticleUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsParticleUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , nbParticlePerCell(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-particle-per-cell", _element(),
        /* default    */ "50",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , initNbParticlePerCell(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "init-nb-particle-per-cell", _element(),
        /* default    */ "100",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , maxIteration(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "max-iteration", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , destroyRatio(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "destroy-ratio", _element(),
        /* default    */ "0.5",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , particleExchanger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "particle-exchanger", _element(),
        /* default    */ "BasicParticleExchanger",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
  {

nbParticlePerCell.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-particule-par-maille"));
initNbParticlePerCell.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("init-nb-particule-par-maille"));
maxIteration.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("max-iteration"));
destroyRatio.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("ratio-destruction"));
particleExchanger.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("echangeur-particule"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getNbParticlePerCell() { return nbParticlePerCell(); }
    Arcane::Integer getInitNbParticlePerCell() { return initNbParticlePerCell(); }
    Arcane::Integer getMaxIteration() { return maxIteration(); }
    Arcane::Real getDestroyRatio() { return destroyRatio(); }
 
 
 
     Arcane::IParticleExchanger* getParticleExchanger() { return particleExchanger(); }
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

  
  Arcane::CaseOptionInteger    nbParticlePerCell;
  Arcane::CaseOptionInteger    initNbParticlePerCell;
  Arcane::CaseOptionInteger    maxIteration;
  Arcane::CaseOptionReal    destroyRatio;
  Arcane::CaseOptionServiceT< Arcane::IParticleExchanger >   particleExchanger;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_PARTICLEUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_PARTICLEUNITTEST_H

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

class CaseOptionsParticleUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneParticleUnitTestObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ParticleUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("particle-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneParticleUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
    , m_particle_temperature(Arcane::VariableBuildInfo(sbi.meshHandle(), "Temperature", "ArcaneParticles"  , Arcane::IVariable::PNoNeedSync))
    , m_particle_temperature_with_ghost(Arcane::VariableBuildInfo(sbi.meshHandle(), "Temperature", "ArcaneParticlesWithGhost"  , Arcane::IVariable::PNoNeedSync))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsParticleUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneParticleUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsParticleUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsParticleUnitTest* m_options;
      
protected:

  //! Variables du service
  Arcane::VariableParticleReal m_particle_temperature;
  Arcane::VariableParticleReal m_particle_temperature_with_ghost;
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

#define ARCANE_REGISTER_SERVICE_PARTICLEUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

