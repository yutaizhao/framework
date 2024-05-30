/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_HYODAMIXEDCELLSUNITTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_HYODAMIXEDCELLSUNITTEST_H

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
class CaseOptionsHyodaMixedCellsUnitTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'material'
      // Generating multiple arity CaseOption for complex option value 'material'
  class CaseOptionMaterialValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionMaterialValue ThatClass;

    CaseOptionMaterialValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsMaterial
  
    Arcane::String getName() { return name(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  };

  // Generation for sub-option 'material'
  class CaseOptionMaterial
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionMaterialValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionMaterialValue * > BaseClass;

    typedef CaseOptionMaterialValue value_type;

  public:

    CaseOptionMaterial(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,1,-1) 
    {
    // Generating translations and default values.
        }

    BaseClass operator()() { return (*this); }

  protected:
    void multiAllocate(const Arcane::XmlNodeList& elist)
    {
      Arcane::Integer s = elist.size();
      value_type** v = 0;
      if (s!=0)
        v = new value_type*[s];
      _setArray(v,s);
      v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
      }
    }

  public:

    ~CaseOptionMaterial()
    {
      Arcane::Integer s = count();
      if (s==0) return;
      value_type** v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        delete v[i];
      }
      delete[] v;
    }

  public:

    const value_type& operator[](Arcane::Integer i) const
      { return *(BaseClass::operator[](i)); }
    value_type& operator[](Arcane::Integer i)
      { return *(BaseClass::operator[](i)); }
    Arcane::Integer count() const
      { return BaseClass::size(); }
    Arcane::Integer size() const
      { return BaseClass::size(); }

  };
  
  // Generation for option 'environment'
      // Generating multiple arity CaseOption for complex option value 'environment'
  class CaseOptionEnvironmentValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionEnvironmentValue ThatClass;

    CaseOptionEnvironmentValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , material(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "material", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ -1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsEnvironment
  
    Arcane::ConstArrayView<  Arcane::String > getMaterial() { return material.values(); }
    Arcane::String getName() { return name(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   material;
  };

  // Generation for sub-option 'environment'
  class CaseOptionEnvironment
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionEnvironmentValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionEnvironmentValue * > BaseClass;

    typedef CaseOptionEnvironmentValue value_type;

  public:

    CaseOptionEnvironment(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,1,-1) 
    {
    // Generating translations and default values.
        }

    BaseClass operator()() { return (*this); }

  protected:
    void multiAllocate(const Arcane::XmlNodeList& elist)
    {
      Arcane::Integer s = elist.size();
      value_type** v = 0;
      if (s!=0)
        v = new value_type*[s];
      _setArray(v,s);
      v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
      }
    }

  public:

    ~CaseOptionEnvironment()
    {
      Arcane::Integer s = count();
      if (s==0) return;
      value_type** v = _ptr();
      for( Arcane::Integer i=0; i<s; ++i ){
        delete v[i];
      }
      delete[] v;
    }

  public:

    const value_type& operator[](Arcane::Integer i) const
      { return *(BaseClass::operator[](i)); }
    value_type& operator[](Arcane::Integer i)
      { return *(BaseClass::operator[](i)); }
    Arcane::Integer count() const
      { return BaseClass::size(); }
    Arcane::Integer size() const
      { return BaseClass::size(); }

  };
  

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsHyodaMixedCellsUnitTest(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , iterations(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "iterations", _element(),
        /* default    */ "8",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , material(_configList(),
        /* name       */ "material", _element())
      , environment(_configList(),
        /* name       */ "environment", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Integer getIterations() { return iterations(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    iterations;
  CaseOptionMaterial   material;
  CaseOptionEnvironment   environment;
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
// Arcane version 1.0 : 05/30/2024 13:54:53
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_HYODAMIXEDCELLSUNITTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_HYODAMIXEDCELLSUNITTEST_H

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

class CaseOptionsHyodaMixedCellsUnitTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneHyodaMixedCellsUnitTestObject
  : public Arcane::BasicTimeLoopService
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("HyodaMixedCellsUnitTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName("hyoda-mixed-cells-unit-test");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::ITimeLoopService)
);
  }
  
public:

  //! Constructeur
  ArcaneHyodaMixedCellsUnitTestObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicTimeLoopService(sbi)
    , m_options(nullptr)
    , m_density(Arcane::VariableBuildInfo(sbi.meshHandle(), "density" ))
    , m_qedge(Arcane::VariableBuildInfo(sbi.meshHandle(), "qedge" ))
    , m_InterfaceNormal(Arcane::VariableBuildInfo(sbi.meshHandle(), "InterfaceNormal" , Arcane::IVariable::PNoDump))
    , m_InterfaceDistance(Arcane::VariableBuildInfo(sbi.meshHandle(), "InterfaceDistance" , Arcane::IVariable::PNoDump))
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsHyodaMixedCellsUnitTest(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneHyodaMixedCellsUnitTestObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsHyodaMixedCellsUnitTest* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsHyodaMixedCellsUnitTest* m_options;
      
protected:

  //! Variables du service
  Arcane::Materials::MaterialVariableCellReal m_density;
  Arcane::VariableFaceReal m_qedge;
  Arcane::VariableCellReal3 m_InterfaceNormal;
  Arcane::VariableCellArrayReal m_InterfaceDistance;
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

#define ARCANE_REGISTER_SERVICE_HYODAMIXEDCELLSUNITTEST(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

