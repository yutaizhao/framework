/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:53:41
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_CARTESIAN2DMESHGENERATOR_H
#define ARCANE_CASEOPTION_AXLSTAR_CARTESIAN2DMESHGENERATOR_H

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
class CaseOptionsCartesian2DMeshGenerator
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'x'
      // Generating multiple arity CaseOption for complex option value 'x'
  class CaseOptionPartInfoXValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionPartInfoXValue ThatClass;

    CaseOptionPartInfoXValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , n(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "n", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , length(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "length", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , progression(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "progression", _element(),
        /* default    */ "1.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsPartInfoX
  
    Arcane::Integer getN() { return n(); }
    Arcane::Real getLength() { return length(); }
    Arcane::Real getProgression() { return progression(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionInteger    n;
  Arcane::CaseOptionReal    length;
  Arcane::CaseOptionReal    progression;
  };

  // Generation for sub-option 'x'
  class CaseOptionPartInfoX
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionPartInfoXValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionPartInfoXValue * > BaseClass;

    typedef CaseOptionPartInfoXValue value_type;

  public:

    CaseOptionPartInfoX(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionPartInfoX()
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
  
  // Generation for option 'y'
      // Generating multiple arity CaseOption for complex option value 'y'
  class CaseOptionPartInfoYValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionPartInfoYValue ThatClass;

    CaseOptionPartInfoYValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , n(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "n", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , length(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "length", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , progression(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "progression", _element(),
        /* default    */ "1.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsPartInfoY
  
    Arcane::Integer getN() { return n(); }
    Arcane::Real getLength() { return length(); }
    Arcane::Real getProgression() { return progression(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionInteger    n;
  Arcane::CaseOptionReal    length;
  Arcane::CaseOptionReal    progression;
  };

  // Generation for sub-option 'y'
  class CaseOptionPartInfoY
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionPartInfoYValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionPartInfoYValue * > BaseClass;

    typedef CaseOptionPartInfoYValue value_type;

  public:

    CaseOptionPartInfoY(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionPartInfoY()
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
  
  CaseOptionsCartesian2DMeshGenerator(Arcane::ICaseOptions* co)
    : m_case_options(co)
      , origin(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "origin", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbPartX(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-part-x", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbPartY(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-part-y", _element(),
        /* default    */ "0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , generateSodGroups(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "generate-sod-groups", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , faceNumberingVersion(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "face-numbering-version", _element(),
        /* default    */ "4",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , x(_configList(),
        /* name       */ "x", _element())
      , y(_configList(),
        /* name       */ "y", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::Real2 getOrigin() { return origin(); }
    Arcane::Integer getNbPartX() { return nbPartX(); }
    Arcane::Integer getNbPartY() { return nbPartY(); }
    bool getGenerateSodGroups() { return generateSodGroups(); }
    Arcane::Integer getFaceNumberingVersion() { return faceNumberingVersion(); }
 
 
 
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

  
  Arcane::CaseOptionReal2    origin;
  Arcane::CaseOptionInteger    nbPartX;
  Arcane::CaseOptionInteger    nbPartY;
  Arcane::CaseOptionBool    generateSodGroups;
  Arcane::CaseOptionInteger    faceNumberingVersion;
  CaseOptionPartInfoX   x;
  CaseOptionPartInfoY   y;
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

#ifndef ARCANE_MODULE_AXLSTAR_CARTESIAN2DMESHGENERATOR_H
#define ARCANE_MODULE_AXLSTAR_CARTESIAN2DMESHGENERATOR_H

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

class CaseOptionsCartesian2DMeshGenerator;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Service
class ArcaneCartesian2DMeshGeneratorObject
  : public Arcane::BasicCaseOptionService
  , public Arcane::IMeshBuilder
{
public:
  // NOTE GG: attention code dupliqué avec 'ServiceT4CaseAndStrong'. Bien reporter les modifications
  template <typename ServiceClassType> static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("Cartesian2DMeshGenerator_arcane_std");
    si->setAxlVersion(0.0);
    si->setDefaultTagName("cartesian2-d-mesh-generator");
    si->setAxlContent(getAxlContent());
    Arcane::ServiceAllInterfaceRegisterer<ServiceClassType>::registerToServiceInfo(si
    ,ARCANE_SERVICE_INTERFACE(Arcane::IMeshBuilder)
);
  }
  
public:

  //! Constructeur
  ArcaneCartesian2DMeshGeneratorObject(const Arcane::ServiceBuildInfo& sbi)
    : Arcane::BasicCaseOptionService(sbi)
    , m_options(nullptr)
  {
    Arcane::ICaseOptions* co = sbi.caseOptions();
    if (co) {
      m_options = new CaseOptionsCartesian2DMeshGenerator(co);
    }
	
  }

  //! Destructeur
  virtual ~ArcaneCartesian2DMeshGeneratorObject()
  {
    delete m_options;
  }


public:

  //! Options du jeu de données du service
  CaseOptionsCartesian2DMeshGenerator* options() const { return m_options; }
 
private:
        
  //! Options du jeu de données du service
  CaseOptionsCartesian2DMeshGenerator* m_options;
      
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

#define ARCANE_REGISTER_SERVICE_CARTESIAN2DMESHGENERATOR(service_name,class_name) \
  ARCANE_REGISTER_AXL_SERVICE(class_name,Arcane::ServiceProperty(#service_name,Arcane::ST_CaseOption,\
   Arcane::SFP_None ))
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

