/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:54
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHMATERIALSYNCUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MESHMATERIALSYNCUNITTEST_H

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
class CaseOptionsMeshMaterialSyncUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMeshMaterialSyncUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , nbMaterial(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-material", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getNbMaterial() { return nbMaterial(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    nbMaterial;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHMATERIALSYNCUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_MESHMATERIALSYNCUNITTEST_H

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

class CaseOptionsMeshMaterialSyncUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneMeshMaterialSyncUnitTestObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MeshMaterialSyncUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("mesh-material-sync-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneMeshMaterialSyncUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsMeshMaterialSyncUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneMeshMaterialSyncUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsMeshMaterialSyncUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsMeshMaterialSyncUnitTest* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_MESHMATERIALSYNCUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
