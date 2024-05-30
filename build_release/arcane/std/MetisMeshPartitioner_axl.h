/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:42
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_METISMESHPARTITIONER_H
#define ARCANE_CASEOPTION_AXLSTAR_METISMESHPARTITIONER_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/std/TypesMetisMeshPartitioner.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsMetisMeshPartitioner
: public TypesMetisMeshPartitioner
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMetisMeshPartitioner(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , maxDiffusiveCount(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "max-diffusive-count", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , imbalanceRelativeTolerance(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "imbalance-relative-tolerance", _element(),
        /* default    */ "4.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , toleranceTarget(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "tolerance-target", _element(),
        /* default    */ "1.05",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , dumpGraph(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "dump-graph", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , inputOutputDigest(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "input-output-digest", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
     , metisCallStrategy(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "metis-call-strategy", _element(),
        /* default    */ "one-processor-per-node",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "MetisCallStrategy")
     , emptyPartitionStrategy(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "empty-partition-strategy", _element(),
        /* default    */ "take-from-biggest-partition-v2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "MetisEmptyPartitionStrategy")
  {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("all-processors"),
          /* enum object     */ (int)(MetisCallStrategy::all_processors));
        metisCallStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("one-processor-per-node"),
          /* enum object     */ (int)(MetisCallStrategy::one_processor_per_node));
        metisCallStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("two-processors-two-nodes"),
          /* enum object     */ (int)(MetisCallStrategy::two_processors_two_nodes));
        metisCallStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("two-gathered-processors"),
          /* enum object     */ (int)(MetisCallStrategy::two_gathered_processors));
        metisCallStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("two-scattered-processors"),
          /* enum object     */ (int)(MetisCallStrategy::two_scattered_processors));
        metisCallStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("none"),
          /* enum object     */ (int)(MetisEmptyPartitionStrategy::DoNothing));
        emptyPartitionStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("take-from-biggest-partition-v1"),
          /* enum object     */ (int)(MetisEmptyPartitionStrategy::TakeFromBiggestPartitionV1));
        emptyPartitionStrategy.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("take-from-biggest-partition-v2"),
          /* enum object     */ (int)(MetisEmptyPartitionStrategy::TakeFromBiggestPartitionV2));
        emptyPartitionStrategy.addEnumValue(x,false);
      }
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("metis"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getMaxDiffusiveCount() { return maxDiffusiveCount(); }
    Arcane::Real getImbalanceRelativeTolerance() { return imbalanceRelativeTolerance(); }
    Arcane::Real getToleranceTarget() { return toleranceTarget(); }
    bool getDumpGraph() { return dumpGraph(); }
    bool getInputOutputDigest() { return inputOutputDigest(); }
 
 
     MetisCallStrategy getMetisCallStrategy() { return metisCallStrategy(); }
     MetisEmptyPartitionStrategy getEmptyPartitionStrategy() { return emptyPartitionStrategy(); }
 
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

  
  Arcane::CaseOptionInteger    maxDiffusiveCount;
  Arcane::CaseOptionReal    imbalanceRelativeTolerance;
  Arcane::CaseOptionReal    toleranceTarget;
  Arcane::CaseOptionBool    dumpGraph;
  Arcane::CaseOptionBool    inputOutputDigest;
  Arcane::CaseOptionEnumT< MetisCallStrategy >   metisCallStrategy;
  Arcane::CaseOptionEnumT< MetisEmptyPartitionStrategy >   emptyPartitionStrategy;
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
// Arcane version 1.0 : 05/30/2024 13:53:42
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_METISMESHPARTITIONER_H
#define ARCANE_MODULE_AXLSTAR_METISMESHPARTITIONER_H

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

class CaseOptionsMetisMeshPartitioner;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneMetisMeshPartitionerObject
  : public MeshPartitionerBase
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MetisMeshPartitioner_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("metis-mesh-partitioner");
    si->setAxlContent(getAxlContent());
    si->setTagName("metis","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshPartitioner)
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshPartitionerBase)
);
  }
  
public:

  //! Constructeur
  ArcaneMetisMeshPartitionerObject(const Arcane::ServiceBuildInfo& sbi)
    : MeshPartitionerBase(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsMetisMeshPartitioner(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneMetisMeshPartitionerObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsMetisMeshPartitioner* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsMetisMeshPartitioner* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_METISMESHPARTITIONER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

