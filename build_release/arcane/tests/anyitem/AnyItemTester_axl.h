/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:07
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ANYITEMTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_ANYITEMTESTER_H

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
class CaseOptionsAnyItemTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsAnyItemTester(Arcane::ICaseOptions* co)
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
// Arcane version 1.0 : 05/30/2024 13:55:07
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_ANYITEMTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_ANYITEMTESTER_H

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

class CaseOptionsAnyItemTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneAnyItemTesterObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("AnyItemTester_arcane_tests_anyitem");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("any-item-tester");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneAnyItemTesterObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
    , m_cell_variable(Arcane::VariableBuildInfo(sbi.meshHandle(), "CellVariable" ))
    , m_face_variable(Arcane::VariableBuildInfo(sbi.meshHandle(), "FaceVariable" ))
    , m_cell_variable_array(Arcane::VariableBuildInfo(sbi.meshHandle(), "CellVariableArray" ))
    , m_face_variable_array(Arcane::VariableBuildInfo(sbi.meshHandle(), "FaceVariableArray" ))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsAnyItemTester(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneAnyItemTesterObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsAnyItemTester* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsAnyItemTester* m_options;
      
protected:

  //! Variables du service
  Arcane::VariableCellReal m_cell_variable;
  Arcane::VariableFaceReal m_face_variable;
  Arcane::VariableCellArrayReal m_cell_variable_array;
  Arcane::VariableFaceArrayReal m_face_variable_array;
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

#define ARCANE_REGISTER_SERVICE_ANYITEMTESTER(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

