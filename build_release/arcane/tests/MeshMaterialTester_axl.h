/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:54
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHMATERIALTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHMATERIALTESTER_H

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
class CaseOptionsMeshMaterialTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'material'
      // Generating multiple arity CaseOption for complex option value 'material'
  class CaseOptionMaterialValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionMaterialValue ThatClass;

    CaseOptionMaterialValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsMaterial
  
    Arcane::String getName() { return name(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  };

  // Generation for sub-option 'material'
  class CaseOptionMaterial
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionMaterialValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionMaterialValue * > BaseClass;

    typedef CaseOptionMaterialValue value_type;

  public:

    CaseOptionMaterial(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,1,-1) 
    {
    // Generating translations and default values.
        }

    BaseClass operator()() { return (*this); }

  protected:
    void multiAllocate(const Arcane::XmlNodeList& elist)
    {
      Arcane::Integer s = elist.size();
      value_type** v = 0;
      if (s!=0)
        v = new value_type*[s];
      _setArray(v,s);
      v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
      }
    }

  public:

    ~CaseOptionMaterial()
    {
      Arcane::Integer s = count();
      if (s==0) return;
      value_type** v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        delete v[i];
      }
      delete[] v;
    }

  public:

    const value_type& operator[](Arcane::Integer i) const
      { return *(BaseClass::operator[](i)); }
    value_type& operator[](Arcane::Integer i)
      { return *(BaseClass::operator[](i)); }
    Arcane::Integer count() const
      { return BaseClass::size(); }
    Arcane::Integer size() const
      { return BaseClass::size(); }

  };
  
  // Generation for option 'environment'
      // Generating multiple arity CaseOption for complex option value 'environment'
  class CaseOptionEnvironmentValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionEnvironmentValue ThatClass;

    CaseOptionEnvironmentValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , material(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "material", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ -1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsEnvironment
  
    Arcane::ConstArrayView<  Arcane::String > getMaterial() { return material.values(); }
    Arcane::String getName() { return name(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   material;
  };

  // Generation for sub-option 'environment'
  class CaseOptionEnvironment
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionEnvironmentValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionEnvironmentValue * > BaseClass;

    typedef CaseOptionEnvironmentValue value_type;

  public:

    CaseOptionEnvironment(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,1,-1) 
    {
    // Generating translations and default values.
        }

    BaseClass operator()() { return (*this); }

  protected:
    void multiAllocate(const Arcane::XmlNodeList& elist)
    {
      Arcane::Integer s = elist.size();
      value_type** v = 0;
      if (s!=0)
        v = new value_type*[s];
      _setArray(v,s);
      v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
      }
    }

  public:

    ~CaseOptionEnvironment()
    {
      Arcane::Integer s = count();
      if (s==0) return;
      value_type** v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        delete v[i];
      }
      delete[] v;
    }

  public:

    const value_type& operator[](Arcane::Integer i) const
      { return *(BaseClass::operator[](i)); }
    value_type& operator[](Arcane::Integer i)
      { return *(BaseClass::operator[](i)); }
    Arcane::Integer count() const
      { return BaseClass::size(); }
    Arcane::Integer size() const
      { return BaseClass::size(); }

  };
  

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMeshMaterialTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"mesh-material-tester"))
      , recreateFromDump(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "recreate-from-dump", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , modificationFlags(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "modification-flags", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , loadBalanceService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "load-balance-service", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
      , additionalTestService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "additional-test-service", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
      , additionalEosService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "additional-eos-service", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
      , material(_configList(),
        /* name       */ "material", _element())
      , environment(_configList(),
        /* name       */ "environment", _element())
  {

loadBalanceService.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("service-equilibrage-charge"));
additionalTestService.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("service-additionnel-test-unitaire"));
additionalEosService.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("service-additionnel-eos"));
  }

public:
  // Interfaces for main CaseOptions
  
    bool getRecreateFromDump() { return recreateFromDump(); }
    Arcane::Int32 getModificationFlags() { return modificationFlags(); }
 
 
 
     Arcane::IMeshPartitioner* getLoadBalanceService() { return loadBalanceService(); }
    Arcane::IUnitTest* getAdditionalTestService() { return additionalTestService(); }
    MaterialEos::IMaterialEquationOfState* getAdditionalEosService() { return additionalEosService(); }
  // Interfaces for complex options
      bool hasLoadBalanceService() const
      { return loadBalanceService.isPresent(); }
      bool hasAdditionalTestService() const
      { return additionalTestService.isPresent(); }
      bool hasAdditionalEosService() const
      { return additionalEosService.isPresent(); }
  
  
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

  
  Arcane::CaseOptionBool    recreateFromDump;
  Arcane::CaseOptionInt32    modificationFlags;
  Arcane::CaseOptionServiceT< Arcane::IMeshPartitioner >   loadBalanceService;
  Arcane::CaseOptionServiceT< Arcane::IUnitTest >   additionalTestService;
  Arcane::CaseOptionServiceT< MaterialEos::IMaterialEquationOfState >   additionalEosService;
  CaseOptionMaterial   material;
  CaseOptionEnvironment   environment;
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
// Arcane version 1.0 : 05/30/2024 13:54:54
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHMATERIALTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHMATERIALTESTER_H

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

class CaseOptionsMeshMaterialTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneMeshMaterialTesterObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MeshMaterialTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("mesh-material-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneMeshMaterialTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_mat_density(Arcane::VariableBuildInfo(this, "Density" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_pressure(Arcane::VariableBuildInfo(this, "Pressure" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_internal_energy(Arcane::VariableBuildInfo(this, "InternalEnergy" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_sound_speed(Arcane::VariableBuildInfo(this, "SoundSpeed" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_spectral1(Arcane::VariableBuildInfo(this, "Spectral1" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_spectral2(Arcane::VariableBuildInfo(this, "Spectral2" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_env_int32(Arcane::VariableBuildInfo(this, "EnvInt32" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_env_empty_int64array(Arcane::VariableBuildInfo(this, "EnvEmptyInt64Array" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_env_spectral1(Arcane::VariableBuildInfo(this, "EnvOnlySpectral1" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_env_spectral2(Arcane::VariableBuildInfo(this, "EnvOnlySpectral2" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    m_options = new CaseOptionsMeshMaterialTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "compute", 
                  &ArcaneMeshMaterialTesterObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "startInit", 
                  &ArcaneMeshMaterialTesterObject::startInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "continueInit", 
                  &ArcaneMeshMaterialTesterObject::continueInit,
                  Arcane::IEntryPoint::WContinueInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "buildInit", 
                  &ArcaneMeshMaterialTesterObject::buildInit,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneMeshMaterialTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void compute() = 0; // Compute
  virtual void startInit() = 0; // StartInit
  virtual void continueInit() = 0; // ContinueInit
  virtual void buildInit() = 0; // BuildInit

  //! Options du jeu de données du module
  CaseOptionsMeshMaterialTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsMeshMaterialTester* m_options;

protected:

  //! Variables du module
  Arcane::Materials::MaterialVariableCellReal m_mat_density;
  Arcane::Materials::MaterialVariableCellReal m_mat_pressure;
  Arcane::Materials::MaterialVariableCellReal m_mat_internal_energy;
  Arcane::Materials::MaterialVariableCellReal m_mat_sound_speed;
  Arcane::Materials::MaterialVariableCellArrayReal m_mat_spectral1;
  Arcane::Materials::MaterialVariableCellArrayInt32 m_mat_spectral2;
  Arcane::Materials::EnvironmentVariableCellInt32 m_env_int32;
  Arcane::Materials::EnvironmentVariableCellArrayInt64 m_env_empty_int64array;
  Arcane::Materials::EnvironmentVariableCellArrayReal m_env_spectral1;
  Arcane::Materials::EnvironmentVariableCellArrayInt32 m_env_spectral2;
    
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

#define ARCANE_REGISTER_MODULE_MESHMATERIALTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("MeshMaterialTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

