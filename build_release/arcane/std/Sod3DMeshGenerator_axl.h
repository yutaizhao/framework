/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:43
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_SOD3DMESHGENERATOR_H
#define ARCANE_CASEOPTION_AXLSTAR_SOD3DMESHGENERATOR_H

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
class CaseOptionsSod3DMeshGenerator
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsSod3DMeshGenerator(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , x(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "x", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , y(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "y", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , z(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "z", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getX() { return x(); }
    Arcane::Integer getY() { return y(); }
    Arcane::Integer getZ() { return z(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    x;
  Arcane::CaseOptionInteger    y;
  Arcane::CaseOptionInteger    z;
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
// Arcane version 1.0 : 05/30/2024 13:53:43
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_SOD3DMESHGENERATOR_H
#define ARCANE_MODULE_AXLSTAR_SOD3DMESHGENERATOR_H

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

class CaseOptionsSod3DMeshGenerator;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneSod3DMeshGeneratorObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::IMeshBuilder
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("Sod3DMeshGenerator_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("sod3-d-mesh-generator");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshBuilder)
);
  }
  
public:

  //! Constructeur
  ArcaneSod3DMeshGeneratorObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsSod3DMeshGenerator(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneSod3DMeshGeneratorObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsSod3DMeshGenerator* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsSod3DMeshGenerator* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_SOD3DMESHGENERATOR(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

