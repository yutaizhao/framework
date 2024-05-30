/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANELOADBALANCE_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANELOADBALANCE_H

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
class CaseOptionsArcaneLoadBalance
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcaneLoadBalance(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"arcane-load-balance"))
      , active(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "active", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , period(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "period", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , compact(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "compact", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , maxImbalance(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "max-imbalance", _element(),
        /* default    */ "0.6",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , statistics(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "statistics", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , minCpuTime(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "min-cpu-time", _element(),
        /* default    */ "800.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , partitioner(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "partitioner", _element(),
        /* default    */ "DefaultPartitioner",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
  {

partitioner.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("partitionneur"));
active.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("actif"));
period.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("periode"));
compact.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("compacte"));
maxImbalance.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("desequilibre-maximal"));
statistics.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("statistiques"));
minCpuTime.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("temps-cpu-minimal"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("arcane-equilibrage-charge"));
  }

public:
  // Interfaces for main CaseOptions
  
    bool getActive() { return active(); }
    Arcane::Integer getPeriod() { return period(); }
    bool getCompact() { return compact(); }
    Arcane::Real getMaxImbalance() { return maxImbalance(); }
    bool getStatistics() { return statistics(); }
    Arcane::Real getMinCpuTime() { return minCpuTime(); }
 
 
 
     Arcane::IMeshPartitioner* getPartitioner() { return partitioner(); }
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

  
  Arcane::CaseOptionBool    active;
  Arcane::CaseOptionInteger    period;
  Arcane::CaseOptionBool    compact;
  Arcane::CaseOptionReal    maxImbalance;
  Arcane::CaseOptionBool    statistics;
  Arcane::CaseOptionReal    minCpuTime;
  Arcane::CaseOptionServiceT< Arcane::IMeshPartitioner >   partitioner;
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
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANELOADBALANCE_H
#define ARCANE_MODULE_AXLSTAR_ARCANELOADBALANCE_H

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

namespace Arcane
{
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsArcaneLoadBalance;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneArcaneLoadBalanceObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneLoadBalance_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName(Arcane::String("arcane-load-balance"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("arcane-equilibrage-charge"),Arcane::String("fr"));
  }

public:

  ArcaneArcaneLoadBalanceObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsArcaneLoadBalance(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "LoadBalanceCheckLoadBalance", 
                  &ArcaneArcaneLoadBalanceObject::checkLoadBalance,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "LoadBalanceInit", 
                  &ArcaneArcaneLoadBalanceObject::loadBalanceInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
  }

  virtual ~ArcaneArcaneLoadBalanceObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void checkLoadBalance() = 0; // CheckLoadBalance
  virtual void loadBalanceInit() = 0; // LoadBalanceInit

  //! Options du jeu de données du module
  CaseOptionsArcaneLoadBalance* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsArcaneLoadBalance* m_options;

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

#define ARCANE_REGISTER_MODULE_ARCANELOADBALANCE(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("ArcaneLoadBalance",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

