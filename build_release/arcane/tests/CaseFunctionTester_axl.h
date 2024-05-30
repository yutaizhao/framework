/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CASEFUNCTIONTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CASEFUNCTIONTESTER_H

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
class CaseOptionsCaseFunctionTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsCaseFunctionTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"case-function-tester"))
      , realTimeMultiply2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "real-time-multiply-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , intIterMultiply3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "int-iter-multiply-3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , realNormL2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "real-norm-l2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Real getRealTimeMultiply2() { return realTimeMultiply2(); }
    Arcane::Int32 getIntIterMultiply3() { return intIterMultiply3(); }
    Arcane::Real getRealNormL2() { return realNormL2(); }
 
 
 
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

  
  Arcane::CaseOptionReal    realTimeMultiply2;
  Arcane::CaseOptionInt32    intIterMultiply3;
  Arcane::CaseOptionReal    realNormL2;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_CASEFUNCTIONTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_CASEFUNCTIONTESTER_H

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

class CaseOptionsCaseFunctionTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneCaseFunctionTesterObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("CaseFunctionTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("case-function-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneCaseFunctionTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsCaseFunctionTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
  }

  virtual ~ArcaneCaseFunctionTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée

  //! Options du jeu de données du module
  CaseOptionsCaseFunctionTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsCaseFunctionTester* m_options;

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

#define ARCANE_REGISTER_MODULE_CASEFUNCTIONTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("CaseFunctionTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

