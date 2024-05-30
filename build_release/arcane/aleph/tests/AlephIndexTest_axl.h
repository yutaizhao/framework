/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHINDEXTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ALEPHINDEXTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/ItemGroup.h"

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
class CaseOptionsAlephIndexTest
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
  
  CaseOptionsAlephIndexTest(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"aleph-index-test"))
      , iterations(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "iterations", _element(),
        /* default    */ "8",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , alephNumberOfSolvers(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "aleph-number-of-solvers", _element(),
        /* default    */ "1",
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
      , boundaryCondition(_configList(),
        /* name       */ "boundary-condition", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getIterations() { return iterations(); }
    Arcane::Integer getAlephNumberOfSolvers() { return alephNumberOfSolvers(); }
    Arcane::Real getDeltaT() { return deltaT(); }
    Arcane::Real getInitTemperature() { return initTemperature(); }
 
 
 
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
  Arcane::CaseOptionInteger    alephNumberOfSolvers;
  Arcane::CaseOptionReal    deltaT;
  Arcane::CaseOptionReal    initTemperature;
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
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHINDEXTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_ALEPHINDEXTEST_H

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

class CaseOptionsAlephIndexTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneAlephIndexTestObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AlephIndexTest_arcane_aleph_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("aleph-index-test"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneAlephIndexTestObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_cell_temperature(Arcane::VariableBuildInfo(this, "CellTemperature" ))
    , m_face_temperature(Arcane::VariableBuildInfo(this, "FaceTemperature" , Arcane::IVariable::PNoDump))
    , m_cell_coefs(Arcane::VariableBuildInfo(this, "CellCoefs" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    m_options = new CaseOptionsAlephIndexTest(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "init", 
                  &ArcaneAlephIndexTestObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "compute", 
                  &ArcaneAlephIndexTestObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneAlephIndexTestObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void init() = 0; // Init
  virtual void compute() = 0; // Compute

  //! Options du jeu de données du module
  CaseOptionsAlephIndexTest* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsAlephIndexTest* m_options;

protected:

  //! Variables du module
  Arcane::VariableCellReal m_cell_temperature;
  Arcane::VariableFaceReal m_face_temperature;
  Arcane::VariableCellReal m_cell_coefs;
    
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

#define ARCANE_REGISTER_MODULE_ALEPHINDEXTEST(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("AlephIndexTest",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

