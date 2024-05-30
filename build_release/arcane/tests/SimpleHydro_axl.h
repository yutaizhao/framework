/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_SIMPLE_HYDRO_SIMPLEHYDRO_H
#define ARCANE_CASEOPTION_AXLSTAR_SIMPLE_HYDRO_SIMPLEHYDRO_H

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
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::FaceGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

SIMPLE_HYDRO_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsSimpleHydro
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'boundary-condition'
      // Generating multiple arity CaseOption for complex option value 'boundary-condition'
  class CaseOptionBoundaryConditionValue
  : public Arcane::CaseOptionComplexValue
    , private SimpleHydro::IBoundaryCondition
  {
  public:

    typedef CaseOptionBoundaryConditionValue ThatClass;

    CaseOptionBoundaryConditionValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , value(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "value", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
     , type(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "type", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesSimpleHydro::eBoundaryCondition")
      , surface(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "surface", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::FaceGroup")

    {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vx"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityX));
        type.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vy"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityY));
        type.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vz"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityZ));
        type.addEnumValue(x,false);
      }

    }
 public:
  // Interfaces for multi-arity class CaseOptionsBoundaryCondition
  
    Arcane::Real getValue() { return value(); }
 
 
    Arcane::FaceGroup getSurface() { return surface(); }
     TypesSimpleHydro::eBoundaryCondition getType() { return type(); }
 
   // Interfaces for complex options
  
  
    SimpleHydro::IBoundaryCondition* _interface() { return this; }
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal    value;
  Arcane::CaseOptionEnumT< TypesSimpleHydro::eBoundaryCondition >   type;
  Arcane::CaseOptionExtendedT< Arcane::FaceGroup >   surface;
  };

  // Generation for sub-option 'boundary-condition'
  class CaseOptionBoundaryCondition
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionBoundaryConditionValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionBoundaryConditionValue * > BaseClass;

    typedef CaseOptionBoundaryConditionValue value_type;

  public:

    CaseOptionBoundaryCondition(Arcane::ICaseOptionList* icl,
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
      m_interfaces.resize(s);
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
        m_interfaces[i] = v[i]->_interface();
      }
    }

  public:

    ~CaseOptionBoundaryCondition()
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

  public: 

    Arcane::ConstArrayView< SimpleHydro::IBoundaryCondition* > _interface()
      { return m_interfaces; }

  private: 

    Arcane::UniqueArray< SimpleHydro::IBoundaryCondition* > m_interfaces;
  };
  

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsSimpleHydro(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"simple-hydro"))
      , deltatMin(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "deltat-min", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , deltatMax(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "deltat-max", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , deltatInit(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "deltat-init", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , finalTime(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "final-time", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , testInt32(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-int32", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , cfl(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "cfl", _element(),
        /* default    */ "0.3",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , variationInf(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "variation-inf", _element(),
        /* default    */ "0.99",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , variationSup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "variation-sup", _element(),
        /* default    */ "0.10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , densityGlobalRatio(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "density-global-ratio", _element(),
        /* default    */ "0.1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , viscosityLinearCoef(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "viscosity-linear-coef", _element(),
        /* default    */ "1.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , viscosityQuadraticCoef(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "viscosity-quadratic-coef", _element(),
        /* default    */ "1.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , useMinimumMemory(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "use-minimum-memory", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , backwardIteration(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "backward-iteration", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , specificTraceListener(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "specific-trace-listener", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , checkNumericalResult(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-numerical-result", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , genericService(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "generic-service", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
     , viscosity(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "viscosity", _element(),
        /* default    */ "none",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesSimpleHydro::eViscosity")
     , subType(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "sub-type", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "TypesSimpleHydro::eBoundaryCondition")
      , volume(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "volume", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "Arcane::ItemGroup")
      , boundaryCondition(_configList(),
        /* name       */ "boundary-condition", _element())
  {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("none"),
          /* enum object     */ (int)(TypesSimpleHydro::ViscosityNo));
        viscosity.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("cell"),
          /* enum object     */ (int)(TypesSimpleHydro::ViscosityCellScalar));
        viscosity.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vx"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityX));
        subType.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vy"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityY));
        subType.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("Vz"),
          /* enum object     */ (int)(TypesSimpleHydro::VelocityZ));
        subType.addEnumValue(x,false);
      }
finalTime.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("temps-final"));
testInt32.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("test-int32"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::ConstArrayView<  Arcane::Int32 > getTestInt32() { return testInt32.values(); }
    Arcane::Real getDeltatMin() { return deltatMin(); }
    Arcane::Real getDeltatMax() { return deltatMax(); }
    Arcane::Real getDeltatInit() { return deltatInit(); }
    Arcane::Real getFinalTime() { return finalTime(); }
    Arcane::Real getCfl() { return cfl(); }
    Arcane::Real getVariationInf() { return variationInf(); }
    Arcane::Real getVariationSup() { return variationSup(); }
    Arcane::Real getDensityGlobalRatio() { return densityGlobalRatio(); }
    Arcane::Real getViscosityLinearCoef() { return viscosityLinearCoef(); }
    Arcane::Real getViscosityQuadraticCoef() { return viscosityQuadraticCoef(); }
    bool getUseMinimumMemory() { return useMinimumMemory(); }
    Arcane::Int32 getBackwardIteration() { return backwardIteration(); }
    bool getSpecificTraceListener() { return specificTraceListener(); }
    bool getCheckNumericalResult() { return checkNumericalResult(); }
 
    Arcane::ConstArrayView<  Arcane::ItemGroup > getVolume() { return volume; }
 
    Arcane::ConstArrayView<  TypesSimpleHydro::eBoundaryCondition > getSubType() { return subType; }
     TypesSimpleHydro::eViscosity getViscosity() { return viscosity(); }
 
     SimpleHydro::ISimpleHydroService* getGenericService() { return genericService(); }
  // Interfaces for complex options
   Arcane::ConstArrayView<  SimpleHydro::IBoundaryCondition* > getBoundaryCondition() { return boundaryCondition._interface(); }
      bool hasGenericService() const
      { return genericService.isPresent(); }
  
  
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

  
  Arcane::CaseOptionReal    deltatMin;
  Arcane::CaseOptionReal    deltatMax;
  Arcane::CaseOptionReal    deltatInit;
  Arcane::CaseOptionReal    finalTime;
  Arcane::CaseOptionMultiSimpleT< Arcane::Int32 >   testInt32;
  Arcane::CaseOptionReal    cfl;
  Arcane::CaseOptionReal    variationInf;
  Arcane::CaseOptionReal    variationSup;
  Arcane::CaseOptionReal    densityGlobalRatio;
  Arcane::CaseOptionReal    viscosityLinearCoef;
  Arcane::CaseOptionReal    viscosityQuadraticCoef;
  Arcane::CaseOptionBool    useMinimumMemory;
  Arcane::CaseOptionInt32    backwardIteration;
  Arcane::CaseOptionBool    specificTraceListener;
  Arcane::CaseOptionBool    checkNumericalResult;
  Arcane::CaseOptionServiceT< SimpleHydro::ISimpleHydroService >   genericService;
  Arcane::CaseOptionEnumT< TypesSimpleHydro::eViscosity >   viscosity;
  Arcane::CaseOptionMultiEnumT< TypesSimpleHydro::eBoundaryCondition  >   subType;
  Arcane::CaseOptionMultiExtendedT< Arcane::ItemGroup  >   volume;
  CaseOptionBoundaryCondition   boundaryCondition;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

SIMPLE_HYDRO_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:06
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_SIMPLE_HYDRO_SIMPLEHYDRO_H
#define ARCANE_MODULE_AXLSTAR_SIMPLE_HYDRO_SIMPLEHYDRO_H

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

SIMPLE_HYDRO_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsSimpleHydro;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneSimpleHydroObject
  : public Arcane::BasicModule
  , public SimpleHydro::SimpleHydroModuleBase
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("SimpleHydro_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("simple-hydro"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneSimpleHydroObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_cell_unique_id(Arcane::VariableBuildInfo(this, "UniqueId" , Arcane::IVariable::PNoNeedSync))
    , m_sub_domain_id(Arcane::VariableBuildInfo(this, "SubDomainId" , Arcane::IVariable::PNoNeedSync))
    , m_rank_as_int16(Arcane::VariableBuildInfo(this, "RankAsInt16" , Arcane::IVariable::PNoNeedSync))
    , m_density(Arcane::VariableBuildInfo(this, "Density" ))
    , m_pressure(Arcane::VariableBuildInfo(this, "Pressure" ))
    , m_cell_mass(Arcane::VariableBuildInfo(this, "CellMass" ))
    , m_internal_energy(Arcane::VariableBuildInfo(this, "InternalEnergy" ))
    , m_volume(Arcane::VariableBuildInfo(this, "CellVolume" ))
    , m_old_volume(Arcane::VariableBuildInfo(this, "OldCellVolume" ))
    , m_cell_viscosity_force(Arcane::VariableBuildInfo(this, "CellViscosityForce" ))
    , m_cell_viscosity_work(Arcane::VariableBuildInfo(this, "CellViscosityWork" ))
    , m_force(Arcane::VariableBuildInfo(this, "Force" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_velocity(Arcane::VariableBuildInfo(this, "Velocity" ))
    , m_node_mass(Arcane::VariableBuildInfo(this, "NodeMass" ))
    , m_adiabatic_cst(Arcane::VariableBuildInfo(this, "AdiabaticCst" ))
    , m_caracteristic_length(Arcane::VariableBuildInfo(this, "CaracteristicLength" ))
    , m_sound_speed(Arcane::VariableBuildInfo(this, "SoundSpeed" ))
    , m_node_coord(Arcane::VariableBuildInfo(this, "NodeCoord" ))
    , m_cell_cqs(Arcane::VariableBuildInfo(this, "CellCQS" ))
  {
    m_options = new CaseOptionsSimpleHydro(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "SH_HydroBuild", 
                  &ArcaneSimpleHydroObject::hydroBuild,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_HydroExit", 
                  &ArcaneSimpleHydroObject::hydroExit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_HydroInit", 
                  &ArcaneSimpleHydroObject::hydroInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_HydroStartInit", 
                  &ArcaneSimpleHydroObject::hydroStartInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_HydroContinueInit", 
                  &ArcaneSimpleHydroObject::hydroContinueInit,
                  Arcane::IEntryPoint::WContinueInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputeForces", 
                  &ArcaneSimpleHydroObject::computeForces,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputePseudoViscosity", 
                  &ArcaneSimpleHydroObject::computePseudoViscosity,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputeVelocity", 
                  &ArcaneSimpleHydroObject::computeVelocity,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputeViscosityWork", 
                  &ArcaneSimpleHydroObject::computeViscosityWork,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ApplyBoundaryCondition", 
                  &ArcaneSimpleHydroObject::applyBoundaryCondition,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_MoveNodes", 
                  &ArcaneSimpleHydroObject::moveNodes,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputeGeometricValues", 
                  &ArcaneSimpleHydroObject::computeGeometricValues,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_UpdateDensity", 
                  &ArcaneSimpleHydroObject::updateDensity,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ApplyEquationOfState", 
                  &ArcaneSimpleHydroObject::applyEquationOfState,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_ComputeDeltaT", 
                  &ArcaneSimpleHydroObject::computeDeltaT,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "SH_DoOneIteration", 
                  &ArcaneSimpleHydroObject::doOneIteration,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneSimpleHydroObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void hydroBuild() = 0; // HydroBuild
  virtual void hydroExit() = 0; // HydroExit
  virtual void hydroInit() = 0; // HydroInit
  virtual void hydroStartInit() = 0; // HydroStartInit
  virtual void hydroContinueInit() = 0; // HydroContinueInit
  virtual void computeForces() = 0; // ComputeForces
  virtual void computePseudoViscosity() = 0; // ComputePseudoViscosity
  virtual void computeVelocity() = 0; // ComputeVelocity
  virtual void computeViscosityWork() = 0; // ComputeViscosityWork
  virtual void applyBoundaryCondition() = 0; // ApplyBoundaryCondition
  virtual void moveNodes() = 0; // MoveNodes
  virtual void computeGeometricValues() = 0; // ComputeGeometricValues
  virtual void updateDensity() = 0; // UpdateDensity
  virtual void applyEquationOfState() = 0; // ApplyEquationOfState
  virtual void computeDeltaT() = 0; // ComputeDeltaT
  virtual void doOneIteration() = 0; // DoOneIteration

  //! Options du jeu de données du module
  CaseOptionsSimpleHydro* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsSimpleHydro* m_options;

protected:

  //! Variables du module
  Arcane::VariableCellInt64 m_cell_unique_id;
  Arcane::VariableCellInteger m_sub_domain_id;
  Arcane::VariableCellInt16 m_rank_as_int16;
  Arcane::VariableCellReal m_density;
  Arcane::VariableCellReal m_pressure;
  Arcane::VariableCellReal m_cell_mass;
  Arcane::VariableCellReal m_internal_energy;
  Arcane::VariableCellReal m_volume;
  Arcane::VariableCellReal m_old_volume;
  Arcane::VariableCellReal m_cell_viscosity_force;
  Arcane::VariableCellReal m_cell_viscosity_work;
  Arcane::VariableNodeReal3 m_force;
  Arcane::VariableNodeReal3 m_velocity;
  Arcane::VariableNodeReal m_node_mass;
  Arcane::VariableCellReal m_adiabatic_cst;
  Arcane::VariableCellReal m_caracteristic_length;
  Arcane::VariableCellReal m_sound_speed;
  Arcane::VariableNodeReal3 m_node_coord;
  Arcane::VariableCellArrayReal3 m_cell_cqs;
    
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

#define ARCANE_REGISTER_MODULE_SIMPLEHYDRO(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("SimpleHydro",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

SIMPLE_HYDRO_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

