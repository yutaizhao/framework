/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_AMRCARTESIANMESHTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_AMRCARTESIANMESHTESTER_H

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
class CaseOptionsAMRCartesianMeshTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'refinement-2d'
      // Generating multiple arity CaseOption for complex option value 'refinement-2d'
  class CaseOptionRefinement2DValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionRefinement2DValue ThatClass;

    CaseOptionRefinement2DValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , position(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "position", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , length(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "length", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsRefinement2D
  
    Arcane::Real2 getPosition() { return position(); }
    Arcane::Real2 getLength() { return length(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal2    position;
  Arcane::CaseOptionReal2    length;
  };

  // Generation for sub-option 'refinement-2d'
  class CaseOptionRefinement2D
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionRefinement2DValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionRefinement2DValue * > BaseClass;

    typedef CaseOptionRefinement2DValue value_type;

  public:

    CaseOptionRefinement2D(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionRefinement2D()
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
  
  // Generation for option 'refinement-3d'
      // Generating multiple arity CaseOption for complex option value 'refinement-3d'
  class CaseOptionRefinement3DValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionRefinement3DValue ThatClass;

    CaseOptionRefinement3DValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , position(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "position", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , length(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "length", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsRefinement3D
  
    Arcane::Real3 getPosition() { return position(); }
    Arcane::Real3 getLength() { return length(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal3    position;
  Arcane::CaseOptionReal3    length;
  };

  // Generation for sub-option 'refinement-3d'
  class CaseOptionRefinement3D
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionRefinement3DValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionRefinement3DValue * > BaseClass;

    typedef CaseOptionRefinement3DValue value_type;

  public:

    CaseOptionRefinement3D(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionRefinement3D()
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
  
  CaseOptionsAMRCartesianMeshTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"a-m-r-cartesian-mesh-tester"))
      , expectedNumberOfCellsInPatchs(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "expected-number-of-cells-in-patchs", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , expectedNumberOfGhostCellsInPatchs(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "expected-number-of-ghost-cells-in-patchs", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , nodesUidHash(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nodes-uid-hash", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , facesUidHash(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "faces-uid-hash", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , cellsUidHash(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "cells-uid-hash", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , renumberPatchMethod(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "renumber-patch-method", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , coarseAtInit(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "coarse-at-init", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , verbosityLevel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "verbosity-level", _element(),
        /* default    */ "1",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , dumpSvg(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "dump-svg", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , postProcessor(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "post-processor", _element(),
        /* default    */ "Ensight7PostProcessor",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , refinement2d(_configList(),
        /* name       */ "refinement-2d", _element())
      , refinement3d(_configList(),
        /* name       */ "refinement-3d", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32ConstArrayView getExpectedNumberOfCellsInPatchs() { return expectedNumberOfCellsInPatchs(); }
    Arcane::Int32ConstArrayView getExpectedNumberOfGhostCellsInPatchs() { return expectedNumberOfGhostCellsInPatchs(); }
    Arcane::String getNodesUidHash() { return nodesUidHash(); }
    Arcane::String getFacesUidHash() { return facesUidHash(); }
    Arcane::String getCellsUidHash() { return cellsUidHash(); }
    Arcane::Integer getRenumberPatchMethod() { return renumberPatchMethod(); }
    bool getCoarseAtInit() { return coarseAtInit(); }
    Arcane::Int32 getVerbosityLevel() { return verbosityLevel(); }
    bool getDumpSvg() { return dumpSvg(); }
 
 
 
     Arcane::IPostProcessorWriter* getPostProcessor() { return postProcessor(); }
  // Interfaces for complex options
      bool hasExpectedNumberOfGhostCellsInPatchs() const
      { return expectedNumberOfGhostCellsInPatchs.isPresent(); }
  
  
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

  
  Arcane::CaseOptionInt32Array    expectedNumberOfCellsInPatchs;
  Arcane::CaseOptionInt32Array    expectedNumberOfGhostCellsInPatchs;
  Arcane::CaseOptionString    nodesUidHash;
  Arcane::CaseOptionString    facesUidHash;
  Arcane::CaseOptionString    cellsUidHash;
  Arcane::CaseOptionInteger    renumberPatchMethod;
  Arcane::CaseOptionBool    coarseAtInit;
  Arcane::CaseOptionInt32    verbosityLevel;
  Arcane::CaseOptionBool    dumpSvg;
  Arcane::CaseOptionServiceT< Arcane::IPostProcessorWriter >   postProcessor;
  CaseOptionRefinement2D   refinement2d;
  CaseOptionRefinement3D   refinement3d;
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
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_AMRCARTESIANMESHTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_AMRCARTESIANMESHTESTER_H

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

class CaseOptionsAMRCartesianMeshTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneAMRCartesianMeshTesterObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AMRCartesianMeshTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("a-m-r-cartesian-mesh-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneAMRCartesianMeshTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsAMRCartesianMeshTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "compute", 
                  &ArcaneAMRCartesianMeshTesterObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "init", 
                  &ArcaneAMRCartesianMeshTesterObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "buildInit", 
                  &ArcaneAMRCartesianMeshTesterObject::buildInit,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneAMRCartesianMeshTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void compute() = 0; // Compute
  virtual void init() = 0; // Init
  virtual void buildInit() = 0; // BuildInit

  //! Options du jeu de données du module
  CaseOptionsAMRCartesianMeshTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsAMRCartesianMeshTester* m_options;

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

#define ARCANE_REGISTER_MODULE_AMRCARTESIANMESHTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("AMRCartesianMeshTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

