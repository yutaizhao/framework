/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_UNITTESTCARTESIANMESHPATCH_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_UNITTESTCARTESIANMESHPATCH_H

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
class CaseOptionsUnitTestCartesianMeshPatch
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsUnitTestCartesianMeshPatch(Arcane::ICaseOptions* co)
    : m_case_options(co)
  {

  }

public:
  // Interfaces for main CaseOptions
  
 
 
 
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_UNITTESTCARTESIANMESHPATCH_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_UNITTESTCARTESIANMESHPATCH_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/ServiceInfo.h"
#include "arcane/ISubDomain.h"
#include "arcane/ServiceBuildInfo.h"
#include "arcane/ServiceFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicService.h"
#include "arcane/UnitTestServiceAdapter.h"

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

class CaseOptionsUnitTestCartesianMeshPatch;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneUnitTestCartesianMeshPatchObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::UnitTestServiceAdapter<ArcaneUnitTestCartesianMeshPatchObject>
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("UnitTestCartesianMeshPatch_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("unit-test-cartesian-mesh-patch");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
	  ,ARCANE_SERVICE_INTERFACE(Arcane::IXmlUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneUnitTestCartesianMeshPatchObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , Arcane::UnitTestServiceAdapter<ArcaneUnitTestCartesianMeshPatchObject>(this)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsUnitTestCartesianMeshPatch(co);
    }
    setClassSetUpFunction(&ArcaneUnitTestCartesianMeshPatchObject::setUpForClass);
 
    setClassTearDownFunction(&ArcaneUnitTestCartesianMeshPatchObject::tearDownForClass);
    setTestSetUpFunction(&ArcaneUnitTestCartesianMeshPatchObject::setUp);
    setTestTearDownFunction(&ArcaneUnitTestCartesianMeshPatchObject::tearDown);
    addTestFunction(&ArcaneUnitTestCartesianMeshPatchObject::testCartesianMeshPatchCellsAndParents, "Test cartesian mesh patch cells and parents", "testCartesianMeshPatchCellsAndParents");
    addTestFunction(&ArcaneUnitTestCartesianMeshPatchObject::testCartesianMeshPatchCellDirectionMng, "Test cartesian mesh patch cell direction mng", "testCartesianMeshPatchCellDirectionMng");
    addTestFunction(&ArcaneUnitTestCartesianMeshPatchObject::testCartesianMeshPatchFaceDirectionMng, "Test cartesian mesh patch face direction mng", "testCartesianMeshPatchFaceDirectionMng");
    addTestFunction(&ArcaneUnitTestCartesianMeshPatchObject::testCartesianMeshPatchNodeDirectionMng, "Test cartesian mesh patch node direction mng", "testCartesianMeshPatchNodeDirectionMng");
    addTestFunction(&ArcaneUnitTestCartesianMeshPatchObject::testCartesianMeshPatchCartesianConnectivity, "Test cartesian mesh patch cartesian connectivity", "testCartesianMeshPatchCartesianConnectivity");
	
  }

  //! Destructeur
  virtual ~ArcaneUnitTestCartesianMeshPatchObject()
  {
    delete m_options;
  }

public:

    //! Méthodes de test\n");
  virtual void setUpForClass() = 0;
 
  virtual void tearDownForClass() = 0;
  virtual void setUp() = 0;
  virtual void tearDown() = 0;
  virtual void testCartesianMeshPatchCellsAndParents() = 0;  //!< Test cartesian mesh patch cells and parents
  virtual void testCartesianMeshPatchCellDirectionMng() = 0;  //!< Test cartesian mesh patch cell direction mng
  virtual void testCartesianMeshPatchFaceDirectionMng() = 0;  //!< Test cartesian mesh patch face direction mng
  virtual void testCartesianMeshPatchNodeDirectionMng() = 0;  //!< Test cartesian mesh patch node direction mng
  virtual void testCartesianMeshPatchCartesianConnectivity() = 0;  //!< Test cartesian mesh patch cartesian connectivity

public:

  //! Options du jeu de données du service
  CaseOptionsUnitTestCartesianMeshPatch* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsUnitTestCartesianMeshPatch* m_options;
      
protected:

  //! Variables du service
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

#define ARCANE_REGISTER_SERVICE_UNITTESTCARTESIANMESHPATCH(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

