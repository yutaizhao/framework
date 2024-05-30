/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ALEPHTESTSCHEMEFACES_H
#define ARCANE_CASEOPTION_AXLSTAR_ALEPHTESTSCHEMEFACES_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsAlephTestSchemeFaces
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsAlephTestSchemeFaces(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , amr(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "amr", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    bool getAmr() { return amr(); }
 
 
 
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

  
  Arcane::CaseOptionBool    amr;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif



/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:29
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ALEPHTESTSCHEMEFACES_H
#define ARCANE_MODULE_AXLSTAR_ALEPHTESTSCHEMEFACES_H

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

class CaseOptionsAlephTestSchemeFaces;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneAlephTestSchemeFacesObject
  : public Arcane::BasicCaseOptionService
  , public ArcaneTest::AlephTestScheme
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AlephTestSchemeFaces_arcane_aleph_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("aleph-test-scheme-faces");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(ArcaneTest::AlephTestScheme)
);
  }
  
public:

  //! Constructeur
  ArcaneAlephTestSchemeFacesObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
    , m_cell_temperature(Arcane::VariableBuildInfo(sbi.meshHandle(), "CellTemperature" ))
    , m_face_temperature(Arcane::VariableBuildInfo(sbi.meshHandle(), "FaceTemperature" , Arcane::IVariable::PNoDump))
    , m_cell_matrix_idx(Arcane::VariableBuildInfo(sbi.meshHandle(), "CellMatrixIdx" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_cell_coefs(Arcane::VariableBuildInfo(sbi.meshHandle(), "CellCoefs" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsAlephTestSchemeFaces(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneAlephTestSchemeFacesObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsAlephTestSchemeFaces* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsAlephTestSchemeFaces* m_options;
      
protected:

  //! Variables du service
  Arcane::VariableCellReal m_cell_temperature;
  Arcane::VariableFaceReal m_face_temperature;
  Arcane::VariableCellInteger m_cell_matrix_idx;
  Arcane::VariableCellReal m_cell_coefs;
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

#define ARCANE_REGISTER_SERVICE_ALEPHTESTSCHEMEFACES(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

