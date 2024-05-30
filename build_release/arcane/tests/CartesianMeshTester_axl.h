/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CARTESIANMESHTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CARTESIANMESHTESTER_H

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
class CaseOptionsCartesianMeshTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsCartesianMeshTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"cartesian-mesh-tester"))
      , unstructuredMeshFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "unstructured-mesh-file", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , checkContiguousFaceUniqueIds(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-contiguous-face-unique-ids", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , expectedMeshOrigin(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "expected-mesh-origin", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , expectedMeshLength(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "expected-mesh-length", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , hasEdges(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "has-edges", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , coarseCartesianMesh(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "coarse-cartesian-mesh", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::String getUnstructuredMeshFile() { return unstructuredMeshFile(); }
    bool getCheckContiguousFaceUniqueIds() { return checkContiguousFaceUniqueIds(); }
    Arcane::Real3 getExpectedMeshOrigin() { return expectedMeshOrigin(); }
    Arcane::Real3 getExpectedMeshLength() { return expectedMeshLength(); }
    bool getHasEdges() { return hasEdges(); }
    Arcane::Int32 getCoarseCartesianMesh() { return coarseCartesianMesh(); }
 
 
 
   // Interfaces for complex options
      bool hasUnstructuredMeshFile() const
      { return unstructuredMeshFile.isPresent(); }
      bool hasExpectedMeshOrigin() const
      { return expectedMeshOrigin.isPresent(); }
      bool hasExpectedMeshLength() const
      { return expectedMeshLength.isPresent(); }
  
  
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

  
  Arcane::CaseOptionString    unstructuredMeshFile;
  Arcane::CaseOptionBool    checkContiguousFaceUniqueIds;
  Arcane::CaseOptionReal3    expectedMeshOrigin;
  Arcane::CaseOptionReal3    expectedMeshLength;
  Arcane::CaseOptionBool    hasEdges;
  Arcane::CaseOptionInt32    coarseCartesianMesh;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_CARTESIANMESHTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_CARTESIANMESHTESTER_H

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

class CaseOptionsCartesianMeshTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneCartesianMeshTesterObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("CartesianMeshTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("cartesian-mesh-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneCartesianMeshTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsCartesianMeshTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "compute", 
                  &ArcaneCartesianMeshTesterObject::compute,
                  Arcane::IEntryPoint::WComputeLoop,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "init", 
                  &ArcaneCartesianMeshTesterObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
    addEntryPoint(this, "buildInit", 
                  &ArcaneCartesianMeshTesterObject::buildInit,
                  Arcane::IEntryPoint::WBuild,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneCartesianMeshTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void compute() = 0; // Compute
  virtual void init() = 0; // Init
  virtual void buildInit() = 0; // BuildInit

  //! Options du jeu de données du module
  CaseOptionsCartesianMeshTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsCartesianMeshTester* m_options;

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

#define ARCANE_REGISTER_MODULE_CARTESIANMESHTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("CartesianMeshTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

