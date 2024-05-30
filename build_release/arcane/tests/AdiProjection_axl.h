/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ADIPROJECTION_H
#define ARCANE_CASEOPTION_AXLSTAR_ADIPROJECTION_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsAdiProjection
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsAdiProjection(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"adi-projection"))
      , ordreProjection(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "ordre-projection", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("projection-adi"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getOrdreProjection() { return ordreProjection(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    ordreProjection;
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
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ADIPROJECTION_H
#define ARCANE_MODULE_AXLSTAR_ADIPROJECTION_H

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

class CaseOptionsAdiProjection;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneAdiProjectionObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AdiProjection_arcane_tests");
    si->setAxlVersion(0.0);
    si->setDefaultTagName(Arcane::String("adi-projection"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("projection-adi"),Arcane::String("fr"));
  }

public:

  ArcaneAdiProjectionObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_eulerian_coordinates(Arcane::VariableBuildInfo(this, "EulerianCoordinates" ))
    , m_lagrangian_coordinates(Arcane::VariableBuildInfo(this, "LagrangianCoordinates" ))
    , m_old_volume(Arcane::VariableBuildInfo(this, "OldCellVolume" ))
    , m_old_velocity(Arcane::VariableBuildInfo(this, "OldVelocity" ))
    , m_velocity(Arcane::VariableBuildInfo(this, "Velocity" ))
    , m_lagrangian_velocity(Arcane::VariableBuildInfo(this, "LagrangianVelocity" ))
    , m_volume_flux_left(Arcane::VariableBuildInfo(this, "VolumeFluxLeft" ))
    , m_volume_flux_right(Arcane::VariableBuildInfo(this, "VolumeFluxRight" ))
    , m_mass_flux_left(Arcane::VariableBuildInfo(this, "MassFluxLeft" ))
    , m_mass_flux_right(Arcane::VariableBuildInfo(this, "MassFluxRight" ))
    , m_nodal_mass_flux_left(Arcane::VariableBuildInfo(this, "NodalMassFluxLeft" ))
    , m_nodal_mass_flux_right(Arcane::VariableBuildInfo(this, "NodalMassFluxRight" ))
    , m_delta_mass(Arcane::VariableBuildInfo(this, "DeltaMass" ))
    , m_pressure_gradient(Arcane::VariableBuildInfo(this, "PressureGradient" ))
    , m_directional_projected_volume(Arcane::VariableBuildInfo(this, "DirectionalProjectedVolume" ))
    , m_nrj(Arcane::VariableBuildInfo(this, "InternalEnergy" ))
    , m_directional_internal_energy(Arcane::VariableBuildInfo(this, "DirectionalInternalEnergy" ))
    , m_initial_oriented_area(Arcane::VariableBuildInfo(this, "InitialOrientedArea" ))
    , m_face_normal(Arcane::VariableBuildInfo(this, "FaceNormal" ))
    , m_face_velocity(Arcane::VariableBuildInfo(this, "FaceVelocity" ))
    , m_old_density(Arcane::VariableBuildInfo(this, "OldDensity" ))
    , m_pressure(Arcane::VariableBuildInfo(this, "Pressure" ))
    , m_density(Arcane::VariableBuildInfo(this, "Density" ))
    , m_nodal_density(Arcane::VariableBuildInfo(this, "NodalDensity" ))
    , m_old_nodal_density(Arcane::VariableBuildInfo(this, "OldNodalDensity" ))
  {
    m_options = new CaseOptionsAdiProjection(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "CartesianHydroStartInit", 
                  &ArcaneAdiProjectionObject::cartesianHydroStartInit,
                  Arcane::IEntryPoint::WStartInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "CartesianHydroMain", 
                  &ArcaneAdiProjectionObject::cartesianHydroMain,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "CopyEulerianCoordinates", 
                  &ArcaneAdiProjectionObject::copyEulerianCoordinates,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneAdiProjectionObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void cartesianHydroStartInit() = 0; // CartesianHydroStartInit
  virtual void cartesianHydroMain() = 0; // CartesianHydroMain
  virtual void copyEulerianCoordinates() = 0; // CopyEulerianCoordinates

  //! Options du jeu de données du module
  CaseOptionsAdiProjection* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsAdiProjection* m_options;

protected:

  //! Variables du module
  Arcane::VariableNodeReal3 m_eulerian_coordinates;
  Arcane::VariableNodeReal3 m_lagrangian_coordinates;
  Arcane::VariableCellReal m_old_volume;
  Arcane::VariableNodeReal3 m_old_velocity;
  Arcane::VariableNodeReal3 m_velocity;
  Arcane::VariableNodeReal3 m_lagrangian_velocity;
  Arcane::VariableCellReal m_volume_flux_left;
  Arcane::VariableCellReal m_volume_flux_right;
  Arcane::VariableCellReal m_mass_flux_left;
  Arcane::VariableCellReal m_mass_flux_right;
  Arcane::VariableNodeReal m_nodal_mass_flux_left;
  Arcane::VariableNodeReal m_nodal_mass_flux_right;
  Arcane::VariableNodeReal m_delta_mass;
  Arcane::VariableNodeReal m_pressure_gradient;
  Arcane::VariableCellReal m_directional_projected_volume;
  Arcane::VariableCellReal m_nrj;
  Arcane::VariableCellReal m_directional_internal_energy;
  Arcane::VariableFaceReal3 m_initial_oriented_area;
  Arcane::VariableFaceReal3 m_face_normal;
  Arcane::VariableFaceReal3 m_face_velocity;
  Arcane::VariableCellReal m_old_density;
  Arcane::VariableCellReal m_pressure;
  Arcane::VariableCellReal m_density;
  Arcane::VariableNodeReal m_nodal_density;
  Arcane::VariableNodeReal m_old_nodal_density;
    
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

#define ARCANE_REGISTER_MODULE_ADIPROJECTION(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("AdiProjection",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

