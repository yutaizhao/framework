/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHMULTITEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHMULTITEST_H

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
class CaseOptionsAlephMultiTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsAlephMultiTest(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"aleph-multi-test"))
      , deltaT(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "deltaT", _element(),
        /* default    */ "0.001",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , iterations(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "iterations", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , iniTemperature(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "ini-temperature", _element(),
        /* default    */ "300",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , hotTemperature(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "hot-temperature", _element(),
        /* default    */ "700",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfSuccessiveSolvers(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-successive-solvers", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfResolutionsPerSolvers(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-resolutions-per-solvers", _element(),
        /* default    */ "0x73",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephUnderlyingSolver(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-underlying-solver", _element(),
        /* default    */ "0x00",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfCores(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-cores", _element(),
        /* default    */ "0x10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Real getDeltaT() { return deltaT(); }
    Arcane::Integer getIterations() { return iterations(); }
    Arcane::Real getIniTemperature() { return iniTemperature(); }
    Arcane::Real getHotTemperature() { return hotTemperature(); }
    Arcane::Integer getAlephNumberOfSuccessiveSolvers() { return alephNumberOfSuccessiveSolvers(); }
    Arcane::Integer getAlephNumberOfResolutionsPerSolvers() { return alephNumberOfResolutionsPerSolvers(); }
    Arcane::Integer getAlephUnderlyingSolver() { return alephUnderlyingSolver(); }
    Arcane::Integer getAlephNumberOfCores() { return alephNumberOfCores(); }
 
 
 
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

  
  Arcane::CaseOptionReal    deltaT;
  Arcane::CaseOptionInteger    iterations;
  Arcane::CaseOptionReal    iniTemperature;
  Arcane::CaseOptionReal    hotTemperature;
  Arcane::CaseOptionInteger    alephNumberOfSuccessiveSolvers;
  Arcane::CaseOptionInteger    alephNumberOfResolutionsPerSolvers;
  Arcane::CaseOptionInteger    alephUnderlyingSolver;
  Arcane::CaseOptionInteger    alephNumberOfCores;
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
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHMULTITEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHMULTITEST_H

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

class CaseOptionsAlephMultiTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneAlephMultiTestObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AlephMultiTest_arcane_aleph_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("aleph-multi-test"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneAlephMultiTestObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_cell_temperature(Arcane::VariableBuildInfo(this, "CellTemperature" ))
    , m_face_temperature(Arcane::VariableBuildInfo(this, "FaceTemperature" , Arcane::IVariable::PNoDump))
  {
    m_options = new CaseOptionsAlephMultiTest(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "init", 
                  &ArcaneAlephMultiTestObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "compute", 
                  &ArcaneAlephMultiTestObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneAlephMultiTestObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void init() = 0; // Init
  virtual void compute() = 0; // Compute

  //! Options du jeu de données du module
  CaseOptionsAlephMultiTest* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsAlephMultiTest* m_options;

protected:

  //! Variables du module
  Arcane::VariableCellReal m_cell_temperature;
  Arcane::VariableFaceReal m_face_temperature;
    
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

#define ARCANE_REGISTER_MODULE_ALEPHMULTITEST(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("AlephMultiTest",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

