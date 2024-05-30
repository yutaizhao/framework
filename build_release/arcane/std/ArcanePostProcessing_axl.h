/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:41
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANEPOSTPROCESSING_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANEPOSTPROCESSING_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/ItemGroup.h"
#include "arcane/CaseOptionService.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::ItemGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsArcanePostProcessing
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'output'
      // Generating simple arity CaseOption for option 'output'
  class CaseOptionOutput
    : public Arcane::CaseOptions
  {
  public:

    CaseOptionOutput(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , variable(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "variable", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , group(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "Arcane::ItemGroup")
    {

variable.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("variable"));
group.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("groupe"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("depouillement"));
    }
        
    const CaseOptionOutput& operator()() const { return *this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::ConstArrayView<  Arcane::String > getVariable() { return variable.values(); }
 
    Arcane::ConstArrayView<  Arcane::ItemGroup > getGroup() { return group; }
 
 
   // Interfaces for complex options
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   variable;
  Arcane::CaseOptionMultiExtendedT< Arcane::ItemGroup  >   group;

  };

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcanePostProcessing(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"arcane-post-processing"))
      , outputFrequency(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-frequency", _element(),
        /* default    */ "0.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , outputPeriod(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-period", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , outputHistoryPeriod(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-history-period", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , outputHistoryShrink(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-history-shrink", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , saveInit(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "save-init", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , saveFinalTime(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "save-final-time", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , endExecutionOutput(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "end-execution-output", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , format(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "format", _element(),
        /* default    */ "Ensight7PostProcessor",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , output(_configList(),
        /* name       */ "output", _element())
  {

format.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("format-service"));
outputFrequency.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("frequence-sortie"));
outputPeriod.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("periode-sortie"));
outputHistoryPeriod.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("periode-sortie-historique"));
outputHistoryShrink.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("compression-sortie-historique"));
saveInit.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("sauvegarde-initiale"));
saveFinalTime.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("sauvegarde-temps-final"));
endExecutionOutput.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("sortie-fin-execution"));
output.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("depouillement"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("arcane-post-traitement"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Real getOutputFrequency() { return outputFrequency(); }
    Arcane::Integer getOutputPeriod() { return outputPeriod(); }
    Arcane::Integer getOutputHistoryPeriod() { return outputHistoryPeriod(); }
    bool getOutputHistoryShrink() { return outputHistoryShrink(); }
    bool getSaveInit() { return saveInit(); }
    bool getSaveFinalTime() { return saveFinalTime(); }
    bool getEndExecutionOutput() { return endExecutionOutput(); }
 
 
 
     Arcane::IPostProcessorWriter* getFormat() { return format(); }
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

  
  Arcane::CaseOptionReal    outputFrequency;
  Arcane::CaseOptionInteger    outputPeriod;
  Arcane::CaseOptionInteger    outputHistoryPeriod;
  Arcane::CaseOptionBool    outputHistoryShrink;
  Arcane::CaseOptionBool    saveInit;
  Arcane::CaseOptionBool    saveFinalTime;
  Arcane::CaseOptionBool    endExecutionOutput;
  Arcane::CaseOptionServiceT< Arcane::IPostProcessorWriter >   format;
  CaseOptionOutput   output;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:41
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANEPOSTPROCESSING_H
#define ARCANE_MODULE_AXLSTAR_ARCANEPOSTPROCESSING_H

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

class CaseOptionsArcanePostProcessing;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneArcanePostProcessingObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcanePostProcessing_arcane_std");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("arcane-post-processing"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("arcane-post-traitement"),Arcane::String("fr"));
  }

public:

  ArcaneArcanePostProcessingObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_next_iteration(Arcane::VariableBuildInfo(this, "PostProcessingNextIteration" ))
    , m_next_global_time(Arcane::VariableBuildInfo(this, "PostProcessingNextGlobalTime" ))
    , m_curves_next_iteration(Arcane::VariableBuildInfo(this, "PostProcessingCurvesNextIteration" ))
    , m_curves_next_global_time(Arcane::VariableBuildInfo(this, "PostProcessingCurvesNextGlobalTime" ))
    , m_history_next_iteration(Arcane::VariableBuildInfo(this, "PostProcessingHistoryNextIteration" ))
  {
    m_options = new CaseOptionsArcanePostProcessing(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "PostProcessingExportData", 
                  &ArcaneArcanePostProcessingObject::exportData,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "PostProcessingExportDataStart", 
                  &ArcaneArcanePostProcessingObject::exportDataStart,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PAutoLoadBegin);
    addEntryPoint(this, "PostProcessingStartInit", 
                  &ArcaneArcanePostProcessingObject::postProcessingStartInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PAutoLoadBegin);
    addEntryPoint(this, "PostProcessingInit", 
                  &ArcaneArcanePostProcessingObject::postProcessingInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "PostProcessingExit", 
                  &ArcaneArcanePostProcessingObject::postProcessingExit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
  }

  virtual ~ArcaneArcanePostProcessingObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void exportData() = 0; // ExportData
  virtual void exportDataStart() = 0; // ExportDataStart
  virtual void postProcessingStartInit() = 0; // PostProcessingStartInit
  virtual void postProcessingInit() = 0; // PostProcessingInit
  virtual void postProcessingExit() = 0; // PostProcessingExit

  //! Options du jeu de données du module
  CaseOptionsArcanePostProcessing* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsArcanePostProcessing* m_options;

protected:

  //! Variables du module
  Arcane::VariableScalarInteger m_next_iteration;
  Arcane::VariableScalarReal m_next_global_time;
  Arcane::VariableScalarInteger m_curves_next_iteration;
  Arcane::VariableScalarReal m_curves_next_global_time;
  Arcane::VariableScalarInteger m_history_next_iteration;
    
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

#define ARCANE_REGISTER_MODULE_ARCANEPOSTPROCESSING(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("ArcanePostProcessing",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

