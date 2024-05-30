/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:30
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHTESTMODULE_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHTESTMODULE_H

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
                   Arcane::FaceGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsAlephTestModule
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'boundary-condition'
      // Generating multiple arity CaseOption for complex option value 'boundary-condition'
  class CaseOptionBoundaryConditionValue
  : public Arcane::CaseOptionComplexValue
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
      , surface(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "surface", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::FaceGroup")

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsBoundaryCondition
  
    Arcane::Real getValue() { return value(); }
 
 
    Arcane::FaceGroup getSurface() { return surface(); }
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal    value;
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
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
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

  };
  

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsAlephTestModule(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"aleph-test-module"))
      , iterations(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "iterations", _element(),
        /* default    */ "8",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephDeleteKernel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-delete-kernel", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfSolvers(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-solvers", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephUnderlyingSolver(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-underlying-solver", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfCores(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-cores", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephCellOrdering(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-cell-ordering", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , deltaT(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "deltaT", _element(),
        /* default    */ "0.005",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , initTemperature(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "init-temperature", _element(),
        /* default    */ "200",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , initAmr(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "init-amr", _element(),
        /* default    */ "0.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , trigRefine(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "trig-refine", _element(),
        /* default    */ "0.001",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , trigCoarse(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "trig-coarse", _element(),
        /* default    */ "0.001",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , schema(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "schema", _element(),
        /* default    */ "Faces",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , boundaryCondition(_configList(),
        /* name       */ "boundary-condition", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getIterations() { return iterations(); }
    bool getAlephDeleteKernel() { return alephDeleteKernel(); }
    Arcane::Integer getAlephNumberOfSolvers() { return alephNumberOfSolvers(); }
    Arcane::Integer getAlephUnderlyingSolver() { return alephUnderlyingSolver(); }
    Arcane::Integer getAlephNumberOfCores() { return alephNumberOfCores(); }
    bool getAlephCellOrdering() { return alephCellOrdering(); }
    Arcane::Real getDeltaT() { return deltaT(); }
    Arcane::Real getInitTemperature() { return initTemperature(); }
    Arcane::Real getInitAmr() { return initAmr(); }
    Arcane::Real getTrigRefine() { return trigRefine(); }
    Arcane::Real getTrigCoarse() { return trigCoarse(); }
 
 
 
     AlephTestScheme* getSchema() { return schema(); }
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

  
  Arcane::CaseOptionInteger    iterations;
  Arcane::CaseOptionBool    alephDeleteKernel;
  Arcane::CaseOptionInteger    alephNumberOfSolvers;
  Arcane::CaseOptionInteger    alephUnderlyingSolver;
  Arcane::CaseOptionInteger    alephNumberOfCores;
  Arcane::CaseOptionBool    alephCellOrdering;
  Arcane::CaseOptionReal    deltaT;
  Arcane::CaseOptionReal    initTemperature;
  Arcane::CaseOptionReal    initAmr;
  Arcane::CaseOptionReal    trigRefine;
  Arcane::CaseOptionReal    trigCoarse;
  Arcane::CaseOptionServiceT< AlephTestScheme >   schema;
  CaseOptionBoundaryCondition   boundaryCondition;
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
// Arcane version 1.0 : 05/30/2024 13:53:30
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHTESTMODULE_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHTESTMODULE_H

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

class CaseOptionsAlephTestModule;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneAlephTestModuleObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AlephTestModule_arcane_aleph_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("aleph-test-module"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneAlephTestModuleObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_cell_temperature(Arcane::VariableBuildInfo(this, "CellTemperature" ))
    , m_face_temperature(Arcane::VariableBuildInfo(this, "FaceTemperature" , Arcane::IVariable::PNoDump))
    , m_cell_matrix_idx(Arcane::VariableBuildInfo(this, "CellMatrixIdx" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_sub_domain_id(Arcane::VariableBuildInfo(this, "SubDomainId" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_unique_id(Arcane::VariableBuildInfo(this, "UniqueId" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    m_options = new CaseOptionsAlephTestModule(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "init", 
                  &ArcaneAlephTestModuleObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "compute", 
                  &ArcaneAlephTestModuleObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneAlephTestModuleObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void init() = 0; // Init
  virtual void compute() = 0; // Compute

  //! Options du jeu de données du module
  CaseOptionsAlephTestModule* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsAlephTestModule* m_options;

protected:

  //! Variables du module
  Arcane::VariableCellReal m_cell_temperature;
  Arcane::VariableFaceReal m_face_temperature;
  Arcane::VariableCellInteger m_cell_matrix_idx;
  Arcane::VariableCellInteger m_sub_domain_id;
  Arcane::VariableCellInt64 m_unique_id;
    
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

#define ARCANE_REGISTER_MODULE_ALEPHTESTMODULE(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("AlephTestModule",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

