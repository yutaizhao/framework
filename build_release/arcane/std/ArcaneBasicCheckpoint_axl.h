/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:39
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANEBASICCHECKPOINT_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANEBASICCHECKPOINT_H

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

ARCANE_BEGIN_NAMESPACE
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsArcaneBasicCheckpoint
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcaneBasicCheckpoint(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , formatVersion(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "format-version", _element(),
        /* default    */ "2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , dataCompressor(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "data-compressor", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* allow-null */ false,
        /* optional   */ true)
  {

addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("arcane-equilibrage-charge"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32 getFormatVersion() { return formatVersion(); }
 
 
 
     Arcane::IDataCompressor* getDataCompressor() { return dataCompressor(); }
  // Interfaces for complex options
      bool hasDataCompressor() const
      { return dataCompressor.isPresent(); }
  
  
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

  
  Arcane::CaseOptionInt32    formatVersion;
  Arcane::CaseOptionServiceT< Arcane::IDataCompressor >   dataCompressor;
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
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANEBASICCHECKPOINT_H
#define ARCANE_MODULE_AXLSTAR_ARCANEBASICCHECKPOINT_H

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

namespace Arcane
{
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsArcaneBasicCheckpoint;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneArcaneBasicCheckpointObject
  : public CheckpointService
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneBasicCheckpoint_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("arcane-basic-checkpoint");
    si->setAxlContent(getAxlContent());
    si->setTagName("arcane-equilibrage-charge","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::ICheckpointWriter)
);
  }
  
public:

  //! Constructeur
  ArcaneArcaneBasicCheckpointObject(const Arcane::ServiceBuildInfo& sbi)
    : CheckpointService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsArcaneBasicCheckpoint(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneArcaneBasicCheckpointObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsArcaneBasicCheckpoint* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsArcaneBasicCheckpoint* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_ARCANEBASICCHECKPOINT(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
