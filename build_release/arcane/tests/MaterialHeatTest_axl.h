/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:54
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MATERIALHEATTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MATERIALHEATTEST_H

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
class CaseOptionsMaterialHeatTest
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
  
  // Generation for option 'heat-object'
      // Generating multiple arity CaseOption for complex option value 'heat-object'
  class CaseOptionHeatObjectValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionHeatObjectValue ThatClass;

    CaseOptionHeatObjectValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , center(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "center", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , radius(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "radius", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , velocity(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "velocity", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , material(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "material", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , expectedFinalTemperature(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "expected-final-temperature", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsHeatObject
  
    Arcane::Real3 getCenter() { return center(); }
    Arcane::Real getRadius() { return radius(); }
    Arcane::Real3 getVelocity() { return velocity(); }
    Arcane::String getMaterial() { return material(); }
    Arcane::Real getExpectedFinalTemperature() { return expectedFinalTemperature(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal3    center;
  Arcane::CaseOptionReal    radius;
  Arcane::CaseOptionReal3    velocity;
  Arcane::CaseOptionString    material;
  Arcane::CaseOptionReal    expectedFinalTemperature;
  };

  // Generation for sub-option 'heat-object'
  class CaseOptionHeatObject
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionHeatObjectValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionHeatObjectValue * > BaseClass;

    typedef CaseOptionHeatObjectValue value_type;

  public:

    CaseOptionHeatObject(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
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

    ~CaseOptionHeatObject()
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
  
  CaseOptionsMaterialHeatTest(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"material-heat-test"))
      , nbIteration(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-iteration", _element(),
        /* default    */ "15",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , modificationFlags(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "modification-flags", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , checkNumericalResult(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-numerical-result", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , verbosityLevel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "verbosity-level", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , material(_configList(),
        /* name       */ "material", _element())
      , environment(_configList(),
        /* name       */ "environment", _element())
      , heatObject(_configList(),
        /* name       */ "heat-object", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32 getNbIteration() { return nbIteration(); }
    Arcane::Int32 getModificationFlags() { return modificationFlags(); }
    bool getCheckNumericalResult() { return checkNumericalResult(); }
    Arcane::Int32 getVerbosityLevel() { return verbosityLevel(); }
 
 
 
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

  
  Arcane::CaseOptionInt32    nbIteration;
  Arcane::CaseOptionInt32    modificationFlags;
  Arcane::CaseOptionBool    checkNumericalResult;
  Arcane::CaseOptionInt32    verbosityLevel;
  CaseOptionMaterial   material;
  CaseOptionEnvironment   environment;
  CaseOptionHeatObject   heatObject;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_MATERIALHEATTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_MATERIALHEATTEST_H

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

class CaseOptionsMaterialHeatTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneMaterialHeatTestObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MaterialHeatTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("material-heat-test"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneMaterialHeatTestObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_mat_temperature(Arcane::VariableBuildInfo(this, "Temperature" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_cell_center(Arcane::VariableBuildInfo(this, "CellCenter" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_all_temperature(Arcane::VariableBuildInfo(this, "AllTemperatures" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_mat_device_temperature(Arcane::VariableBuildInfo(this, "DeviceTemperature" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    m_options = new CaseOptionsMaterialHeatTest(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "Compute", 
                  &ArcaneMaterialHeatTestObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "StartInit", 
                  &ArcaneMaterialHeatTestObject::startInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "ContinueInit", 
                  &ArcaneMaterialHeatTestObject::continueInit,
                  Arcane::IEntryPoint::WContinueInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "BuildInit", 
                  &ArcaneMaterialHeatTestObject::buildInit,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneMaterialHeatTestObject()
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
  CaseOptionsMaterialHeatTest* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsMaterialHeatTest* m_options;

protected:

  //! Variables du module
  Arcane::Materials::MaterialVariableCellReal m_mat_temperature;
  Arcane::VariableCellReal3 m_cell_center;
  Arcane::VariableCellArrayReal m_all_temperature;
  Arcane::Materials::MaterialVariableCellReal m_mat_device_temperature;
    
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

#define ARCANE_REGISTER_MODULE_MATERIALHEATTEST(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("MaterialHeatTest",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

