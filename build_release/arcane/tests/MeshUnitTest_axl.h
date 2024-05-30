/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHUNITTEST_H

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
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::NodeGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsMeshUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMeshUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , outputFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "output-file", _element(),
        /* default    */ "meshinfos",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , testVariableWriter(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-variable-writer", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , testAdjency(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-adjency", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , writeMesh(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "write-mesh", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , additionalMesh(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "additional-mesh", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , testDeallocateMesh(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-deallocate-mesh", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , testSortNodeFacesAndEdges(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-sort-node-faces-and-edges", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , computeNormal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "compute-normal", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "Arcane::FaceGroup")
      , computeDirection(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "compute-direction", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "Arcane::NodeGroup")
  {

outputFile.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("fichier-sortie"));
computeNormal.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("calcul-normale"));
computeDirection.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("calcul-direction"));
testVariableWriter.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("test-ecrivain-variable"));
testAdjency.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("test-adjacence"));
writeMesh.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("ecrire-maillage"));
additionalMesh.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("maillage-additionnel"));
testDeallocateMesh.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("test-desallocation-maillage"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::ConstArrayView<  Arcane::String > getAdditionalMesh() { return additionalMesh.values(); }
    Arcane::String getOutputFile() { return outputFile(); }
    bool getTestVariableWriter() { return testVariableWriter(); }
    bool getTestAdjency() { return testAdjency(); }
    bool getWriteMesh() { return writeMesh(); }
    bool getTestDeallocateMesh() { return testDeallocateMesh(); }
    bool getTestSortNodeFacesAndEdges() { return testSortNodeFacesAndEdges(); }
 
    Arcane::ConstArrayView<  Arcane::FaceGroup > getComputeNormal() { return computeNormal; }
    Arcane::ConstArrayView<  Arcane::NodeGroup > getComputeDirection() { return computeDirection; }
 
 
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

  
  Arcane::CaseOptionString    outputFile;
  Arcane::CaseOptionBool    testVariableWriter;
  Arcane::CaseOptionBool    testAdjency;
  Arcane::CaseOptionBool    writeMesh;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   additionalMesh;
  Arcane::CaseOptionBool    testDeallocateMesh;
  Arcane::CaseOptionBool    testSortNodeFacesAndEdges;
  Arcane::CaseOptionMultiExtendedT< Arcane::FaceGroup  >   computeNormal;
  Arcane::CaseOptionMultiExtendedT< Arcane::NodeGroup  >   computeDirection;
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
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHUNITTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/ServiceInfo.h"
#include "arcane/ISubDomain.h"
#include "arcane/ServiceBuildInfo.h"
#include "arcane/ServiceFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicService.h"

#ifndef ARCANE_HAS_SPECIFIC_BASIC_SERVICE
// Code pour les versions de Arcane avant la 3.8 qui ne possèdent pas les
// classes de base spécifiques pour les services
namespace Arcane
{
using BasicCaseOptionService = BasicService;
using BasicSubDomainService = BasicService;
using BasicMeshService = BasicService;
}
#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsMeshUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneMeshUnitTestObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MeshUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("mesh-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneMeshUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
    , m_cell_flag(Arcane::VariableBuildInfo(sbi.meshHandle(), "MeshUnitTest_CellFlags" , Arcane::IVariable::PNoDump))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsMeshUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneMeshUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsMeshUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsMeshUnitTest* m_options;
      
protected:

  //! Variables du service
  Arcane::VariableCellInteger m_cell_flag;
private:
  static Arcane::FileContent getAxlContent()
 {
   const Arcane::Byte* content = (const Arcane::Byte*)"";
   Arcane::Span<const Arcane::Byte> bytes(content,0);
   int file_version = 1;
   return Arcane::FileContent(bytes,file_version,"");
 }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define ARCANE_REGISTER_SERVICE_MESHUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

