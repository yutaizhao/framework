/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MDVARIABLEUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_MDVARIABLEUNITTEST_H

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
class CaseOptionsMDVariableUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsMDVariableUnitTest(Arcane::ICaseOptions* co)
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
// Arcane version 1.0 : 05/30/2024 13:55:05
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_MDVARIABLEUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_MDVARIABLEUNITTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/ServiceInfo.h"
#include "arcane/ISubDomain.h"
#include "arcane/ServiceBuildInfo.h"
#include "arcane/ServiceFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicService.h"
#include "arcane/MeshMDVariableRef.h"

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

class CaseOptionsMDVariableUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneMDVariableUnitTestObject
  : public Arcane::BasicUnitTest
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("MDVariableUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("m-d-variable-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IUnitTest)
);
  }
  
public:

  //! Constructeur
  ArcaneMDVariableUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicUnitTest(sbi)
    , m_options(nullptr)
    , m_scalar_var0d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var1d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var2d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVar2D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var2d_as_3d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVar2D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_vector_var0d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVectorVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_vector_var1d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomVectorVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var0d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomMatrixVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var1d(Arcane::VariableBuildInfo(sbi.meshHandle(), "TestCustomMatrixVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var0d_real(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var1d_real(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var2d_real(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVar2D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_scalar_var2d_as_3d_real(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVar2D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_vector_var0d_real2(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVectorVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_vector_var1d_real3(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVectorVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_vector_var2d_real4(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomVectorVar2D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var0d_real2x2(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomMatrixVar0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var1d_real3x3(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomMatrixVar1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var1d_real2x6(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomMatrix2x6Var1D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
    , m_matrix_var0d_real3x2(Arcane::VariableBuildInfo(sbi.meshHandle(), "Test2CustomMatrix2x6Var0D" , Arcane::IVariable::PNoDump| Arcane::IVariable::PNoNeedSync))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsMDVariableUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneMDVariableUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsMDVariableUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsMDVariableUnitTest* m_options;
      
protected:

  //! Variables du service
  Arcane::MeshMDVariableRefT < Arcane::Cell, Arcane::Real, Arcane::MDDim0 > m_scalar_var0d;
  Arcane::MeshMDVariableRefT < Arcane::Cell, Arcane::Real, Arcane::MDDim1 > m_scalar_var1d;
  Arcane::MeshMDVariableRefT < Arcane::Cell, Arcane::Real, Arcane::MDDim2 > m_scalar_var2d;
  Arcane::MeshMDVariableRefT < Arcane::Cell, Arcane::Real, Arcane::MDDim3 > m_scalar_var2d_as_3d;
  Arcane::MeshVectorMDVariableRefT < Arcane::Cell, Arcane::Real, 3, Arcane::MDDim0 > m_vector_var0d;
  Arcane::MeshVectorMDVariableRefT < Arcane::Cell, Arcane::Real, 3, Arcane::MDDim1 > m_vector_var1d;
  Arcane::MeshMatrixMDVariableRefT < Arcane::Cell, Arcane::Real, 2, 2, Arcane::MDDim0 > m_matrix_var0d;
  Arcane::MeshMatrixMDVariableRefT < Arcane::Cell, Arcane::Real, 2, 2, Arcane::MDDim1 > m_matrix_var1d;
  Arcane::MeshMDVariableRefT<Arcane::Cell,Arcane::Real,Arcane::MDDim0> m_scalar_var0d_real;
  Arcane::MeshMDVariableRefT<Arcane::Cell,Arcane::Real,Arcane::MDDim1> m_scalar_var1d_real;
  Arcane::MeshMDVariableRefT<Arcane::Cell,Arcane::Real,Arcane::MDDim2> m_scalar_var2d_real;
  Arcane::MeshMDVariableRefT<Arcane::Cell,Arcane::Real,Arcane::MDDim3> m_scalar_var2d_as_3d_real;
  Arcane::MeshVectorMDVariableRefT<Arcane::Cell,Arcane::Real,2,Arcane::MDDim0> m_vector_var0d_real2;
  Arcane::MeshVectorMDVariableRefT<Arcane::Face,Arcane::Real,3,Arcane::MDDim1> m_vector_var1d_real3;
  Arcane::MeshVectorMDVariableRefT<Arcane::Face,Arcane::Real,4,Arcane::MDDim2> m_vector_var2d_real4;
  Arcane::MeshMatrixMDVariableRefT<Arcane::Node,Arcane::Real,2,2,Arcane::MDDim0> m_matrix_var0d_real2x2;
  Arcane::MeshMatrixMDVariableRefT<Arcane::Cell,Arcane::Real,3,3,Arcane::MDDim1> m_matrix_var1d_real3x3;
  Arcane::MeshMatrixMDVariableRefT<Arcane::Cell,Arcane::Real,2,6,Arcane::MDDim1> m_matrix_var1d_real2x6;
  Arcane::MeshMatrixMDVariableRefT<Arcane::Cell,Arcane::Real,3,2,Arcane::MDDim0> m_matrix_var0d_real3x2;
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

#define ARCANE_REGISTER_SERVICE_MDVARIABLEUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

