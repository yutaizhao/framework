/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:40
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ZOLTANMESHPARTITIONER_H
#define ARCANE_CASEOPTION_AXLSTAR_ZOLTANMESHPARTITIONER_H

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
class CaseOptionsZoltanMeshPartitioner
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsZoltanMeshPartitioner(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , useHypergraphe(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "use-hypergraphe", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , edgeWeightMultiplier(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "edge-weight-multiplier", _element(),
        /* default    */ "2.",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , repartFrequency(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "repart-frequency", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , model(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "model", _element(),
        /* default    */ "OLDHG",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , imbalanceTol(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "imbalance-tol", _element(),
        /* default    */ "1.05",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , phgRepartMultiplier(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "phg-repart-multiplier", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , phgOutputLevel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "phg-output-level", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , debugLevel(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "debug-level", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

useHypergraphe.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("mode-hypergraphe"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("zoltan"));
  }

public:
  // Interfaces for main CaseOptions
  
    bool getUseHypergraphe() { return useHypergraphe(); }
    Arcane::Real getEdgeWeightMultiplier() { return edgeWeightMultiplier(); }
    Arcane::Integer getRepartFrequency() { return repartFrequency(); }
    Arcane::String getModel() { return model(); }
    Arcane::Real getImbalanceTol() { return imbalanceTol(); }
    Arcane::Real getPhgRepartMultiplier() { return phgRepartMultiplier(); }
    Arcane::Integer getPhgOutputLevel() { return phgOutputLevel(); }
    Arcane::Integer getDebugLevel() { return debugLevel(); }
 
 
 
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

  
  Arcane::CaseOptionBool    useHypergraphe;
  Arcane::CaseOptionReal    edgeWeightMultiplier;
  Arcane::CaseOptionInteger    repartFrequency;
  Arcane::CaseOptionString    model;
  Arcane::CaseOptionReal    imbalanceTol;
  Arcane::CaseOptionReal    phgRepartMultiplier;
  Arcane::CaseOptionInteger    phgOutputLevel;
  Arcane::CaseOptionInteger    debugLevel;
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

#ifndef ARCANE_MODULE_AXLSTAR_ZOLTANMESHPARTITIONER_H
#define ARCANE_MODULE_AXLSTAR_ZOLTANMESHPARTITIONER_H

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

class CaseOptionsZoltanMeshPartitioner;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneZoltanMeshPartitionerObject
  : public MeshPartitionerBase
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ZoltanMeshPartitioner_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("zoltan-mesh-partitioner");
    si->setAxlContent(getAxlContent());
    si->setTagName("zoltan","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshPartitioner)
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshPartitionerBase)
);
  }
  
public:

  //! Constructeur
  ArcaneZoltanMeshPartitionerObject(const Arcane::ServiceBuildInfo& sbi)
    : MeshPartitionerBase(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsZoltanMeshPartitioner(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneZoltanMeshPartitionerObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsZoltanMeshPartitioner* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsZoltanMeshPartitioner* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_ZOLTANMESHPARTITIONER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

