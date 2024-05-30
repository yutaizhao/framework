/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:41
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ENSIGHT7POSTPROCESSOR_H
#define ARCANE_CASEOPTION_AXLSTAR_ENSIGHT7POSTPROCESSOR_H

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
class CaseOptionsEnsight7PostProcessor
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsEnsight7PostProcessor(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , filesetSize(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "fileset-size", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , useDegeneratedHexa(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "use-degenerated-hexa", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , binaryFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "binary-file", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , forceFirstGeometry(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "force-first-geometry", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , saveUids(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "save-uids", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

filesetSize.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nb-temps-par-fichier"));
binaryFile.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("fichier-binaire"));
forceFirstGeometry.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("force-premiere-geometie"));
saveUids.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("sauve-uids"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("post-processeur-ensight7"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getFilesetSize() { return filesetSize(); }
    bool getUseDegeneratedHexa() { return useDegeneratedHexa(); }
    bool getBinaryFile() { return binaryFile(); }
    bool getForceFirstGeometry() { return forceFirstGeometry(); }
    bool getSaveUids() { return saveUids(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    filesetSize;
  Arcane::CaseOptionBool    useDegeneratedHexa;
  Arcane::CaseOptionBool    binaryFile;
  Arcane::CaseOptionBool    forceFirstGeometry;
  Arcane::CaseOptionBool    saveUids;
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
// Arcane version 1.0 : 05/30/2024 13:53:41
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ENSIGHT7POSTPROCESSOR_H
#define ARCANE_MODULE_AXLSTAR_ENSIGHT7POSTPROCESSOR_H

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

class CaseOptionsEnsight7PostProcessor;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneEnsight7PostProcessorObject
  : public PostProcessorWriterBase
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("Ensight7PostProcessor_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("ensight7-post-processor");
    si->setAxlContent(getAxlContent());
    si->setTagName("post-processeur-ensight7","fr");
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IPostProcessorWriter)
);
  }
  
public:

  //! Constructeur
  ArcaneEnsight7PostProcessorObject(const Arcane::ServiceBuildInfo& sbi)
    : PostProcessorWriterBase(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsEnsight7PostProcessor(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneEnsight7PostProcessorObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsEnsight7PostProcessor* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsEnsight7PostProcessor* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_ENSIGHT7POSTPROCESSOR(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

