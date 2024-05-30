/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANECHECKPOINT_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANECHECKPOINT_H

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

//! Options
class CaseOptionsArcaneCheckpoint
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcaneCheckpoint(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"arcane-checkpoint"))
      , frequency(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "frequency", _element(),
        /* default    */ "0.",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , period(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "period", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , frequencyCpu(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "frequency-cpu", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , doDumpAtEnd(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "do-dump-at-end", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , checkpointService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "checkpoint-service", _element(),
        /* default    */ "ArcaneHdf5Checkpoint2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ true,
        /* optional   */ false)
  {

frequency.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("frequence"));
period.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("periode"));
frequencyCpu.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("frequence-cpu"));
doDumpAtEnd.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("en-fin-de-calcul"));
checkpointService.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("service-protection"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("arcane-protections-reprises"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Real getFrequency() { return frequency(); }
    Arcane::Integer getPeriod() { return period(); }
    Arcane::Integer getFrequencyCpu() { return frequencyCpu(); }
    bool getDoDumpAtEnd() { return doDumpAtEnd(); }
 
 
 
     Arcane::ICheckpointWriter* getCheckpointService() { return checkpointService(); }
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

  
  Arcane::CaseOptionReal    frequency;
  Arcane::CaseOptionInteger    period;
  Arcane::CaseOptionInteger    frequencyCpu;
  Arcane::CaseOptionBool    doDumpAtEnd;
  Arcane::CaseOptionServiceT< Arcane::ICheckpointWriter >   checkpointService;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANECHECKPOINT_H
#define ARCANE_MODULE_AXLSTAR_ARCANECHECKPOINT_H

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

class CaseOptionsArcaneCheckpoint;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneArcaneCheckpointObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneCheckpoint_arcane_std");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("arcane-checkpoint"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("arcane-protections-reprises"),Arcane::String("fr"));
  }

public:

  ArcaneArcaneCheckpointObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_next_iteration(Arcane::VariableBuildInfo(this, "ArcaneCheckpointNextIteration" ))
    , m_next_global_time(Arcane::VariableBuildInfo(this, "ArcaneCheckpointNextGlobalTime" ))
    , m_next_cpu_time(Arcane::VariableBuildInfo(this, "ArcaneCheckpointNextCPUTime" ))
    , m_checkpoints_time(Arcane::VariableBuildInfo(this, "ArcaneCheckpointCheckpointsTime" ))
  {
    m_options = new CaseOptionsArcaneCheckpoint(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "ArcaneCheckpointCheckAndWriteData", 
                  &ArcaneArcaneCheckpointObject::checkpointCheckAndWriteData,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "ArcaneCheckpointStartInit", 
                  &ArcaneArcaneCheckpointObject::checkpointStartInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "ArcaneCheckpointInit", 
                  &ArcaneArcaneCheckpointObject::checkpointInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "ArcaneCheckpointExit", 
                  &ArcaneArcaneCheckpointObject::checkpointExit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
  }

  virtual ~ArcaneArcaneCheckpointObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void checkpointCheckAndWriteData() = 0; // CheckpointCheckAndWriteData
  virtual void checkpointStartInit() = 0; // CheckpointStartInit
  virtual void checkpointInit() = 0; // CheckpointInit
  virtual void checkpointExit() = 0; // CheckpointExit

  //! Options du jeu de données du module
  CaseOptionsArcaneCheckpoint* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsArcaneCheckpoint* m_options;

protected:

  //! Variables du module
  Arcane::VariableScalarInteger m_next_iteration;
  Arcane::VariableScalarReal m_next_global_time;
  Arcane::VariableScalarInteger m_next_cpu_time;
  Arcane::VariableArrayReal m_checkpoints_time;
    
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

#define ARCANE_REGISTER_MODULE_ARCANECHECKPOINT(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("ArcaneCheckpoint",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

