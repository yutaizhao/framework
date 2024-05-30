/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST__MINIWEATHER_MINIWEATHER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST__MINIWEATHER_MINIWEATHER_H

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

namespace ArcaneTest::MiniWeather {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsMiniWeather
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMiniWeather(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"mini-weather"))
      , nbCellX(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-cell-x", _element(),
        /* default    */ "400",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbCellZ(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-cell-z", _element(),
        /* default    */ "200",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , finalTime(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "final-time", _element(),
        /* default    */ "2.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , useDeviceMemory(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "use-device-memory", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , useLeftLayout(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "use-left-layout", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , implementation(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "implementation", _element(),
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
  
    Arcane::Int32 getNbCellX() { return nbCellX(); }
    Arcane::Int32 getNbCellZ() { return nbCellZ(); }
    Arcane::Real getFinalTime() { return finalTime(); }
    bool getUseDeviceMemory() { return useDeviceMemory(); }
    bool getUseLeftLayout() { return useLeftLayout(); }
 
 
 
     ArcaneTest::MiniWeather::IMiniWeatherService* getImplementation() { return implementation(); }
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

  
  Arcane::CaseOptionInt32    nbCellX;
  Arcane::CaseOptionInt32    nbCellZ;
  Arcane::CaseOptionReal    finalTime;
  Arcane::CaseOptionBool    useDeviceMemory;
  Arcane::CaseOptionBool    useLeftLayout;
  Arcane::CaseOptionServiceT< ArcaneTest::MiniWeather::IMiniWeatherService >   implementation;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST__MINIWEATHER_MINIWEATHER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST__MINIWEATHER_MINIWEATHER_H

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

namespace ArcaneTest::MiniWeather {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsMiniWeather;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneMiniWeatherObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MiniWeather_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("mini-weather"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneMiniWeatherObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsMiniWeather(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "MW_Build", 
                  &ArcaneMiniWeatherObject::build,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "MW_Init", 
                  &ArcaneMiniWeatherObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "MW_Exit", 
                  &ArcaneMiniWeatherObject::exit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "MW_ComputeLoop", 
                  &ArcaneMiniWeatherObject::computeLoop,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneMiniWeatherObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void build() = 0; // Build
  virtual void init() = 0; // Init
  virtual void exit() = 0; // Exit
  virtual void computeLoop() = 0; // ComputeLoop

  //! Options du jeu de données du module
  CaseOptionsMiniWeather* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsMiniWeather* m_options;

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

#define ARCANE_REGISTER_MODULE_MINIWEATHER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("MiniWeather",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

