/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:39
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANE_ARCANECASEPARTITIONER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANE_ARCANECASEPARTITIONER_H

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
                   ItemGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsArcaneCasePartitioner
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsArcaneCasePartitioner(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , nbCutPart(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-cut-part", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , library(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "library", _element(),
        /* default    */ "DefaultPartitioner",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , createCorrespondances(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "create-correspondances", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbGhostLayer(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-ghost-layer", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , writerServiceName(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "writer-service-name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , meshFileNamePattern(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "mesh-file-name-pattern", _element(),
        /* default    */ "CPU%05d",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , constraints(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "constraints", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "ItemGroup")
  {

nbCutPart.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-partie-decoupees"));
library.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("bibliotheque"));
constraints.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("indivisible"));
createCorrespondances.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("correspondance"));
nbGhostLayer.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-couches-fantomes"));
writerServiceName.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nom-service-ecriture"));
meshFileNamePattern.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("patron-nom-fichier-maillage"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("partitionneur-cas"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Int32 getNbCutPart() { return nbCutPart(); }
    Arcane::String getLibrary() { return library(); }
    bool getCreateCorrespondances() { return createCorrespondances(); }
    Arcane::Int32 getNbGhostLayer() { return nbGhostLayer(); }
    Arcane::String getWriterServiceName() { return writerServiceName(); }
    Arcane::String getMeshFileNamePattern() { return meshFileNamePattern(); }
 
    Arcane::ConstArrayView<  ItemGroup > getConstraints() { return constraints; }
 
 
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

  
  Arcane::CaseOptionInt32    nbCutPart;
  Arcane::CaseOptionString    library;
  Arcane::CaseOptionBool    createCorrespondances;
  Arcane::CaseOptionInt32    nbGhostLayer;
  Arcane::CaseOptionString    writerServiceName;
  Arcane::CaseOptionString    meshFileNamePattern;
  Arcane::CaseOptionMultiExtendedT< ItemGroup  >   constraints;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANE_ARCANECASEPARTITIONER_H
#define ARCANE_MODULE_AXLSTAR_ARCANE_ARCANECASEPARTITIONER_H

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

ARCANE_BEGIN_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsArcaneCasePartitioner;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneArcaneCasePartitionerObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::IDirectExecution
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneCasePartitioner_arcane_std");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("arcane-case-partitioner");
    si->setAxlContent(getAxlContent());
    si->setTagName("partitionneur-cas","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IDirectExecution)
);
  }
  
public:

  //! Constructeur
  ArcaneArcaneCasePartitionerObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsArcaneCasePartitioner(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneArcaneCasePartitionerObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsArcaneCasePartitioner* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsArcaneCasePartitioner* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_ARCANECASEPARTITIONER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

