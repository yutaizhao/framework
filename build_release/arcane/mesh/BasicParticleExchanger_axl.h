/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:50:18
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_BASICPARTICLEEXCHANGER_H
#define ARCANE_CASEOPTION_AXLSTAR_BASICPARTICLEEXCHANGER_H

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
class CaseOptionsBasicParticleExchanger
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsBasicParticleExchanger(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , maxNbMessageWithoutReduce(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "max-nb-message-without-reduce", _element(),
        /* default    */ "5",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , debugExchangeItemsLevel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "debug-exchange-items-level", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32 getMaxNbMessageWithoutReduce() { return maxNbMessageWithoutReduce(); }
    Arcane::Int32 getDebugExchangeItemsLevel() { return debugExchangeItemsLevel(); }
 
 
 
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

  
  Arcane::CaseOptionInt32    maxNbMessageWithoutReduce;
  Arcane::CaseOptionInt32    debugExchangeItemsLevel;
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
// Arcane version 1.0 : 05/30/2024 13:50:18
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_BASICPARTICLEEXCHANGER_H
#define ARCANE_MODULE_AXLSTAR_BASICPARTICLEEXCHANGER_H

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

class CaseOptionsBasicParticleExchanger;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneBasicParticleExchangerObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::IParticleExchanger
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("BasicParticleExchanger_arcane_mesh");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("basic-particle-exchanger");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IParticleExchanger)
);
  }
  
public:

  //! Constructeur
  ArcaneBasicParticleExchangerObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsBasicParticleExchanger(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneBasicParticleExchangerObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsBasicParticleExchanger* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsBasicParticleExchanger* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_BASICPARTICLEEXCHANGER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
