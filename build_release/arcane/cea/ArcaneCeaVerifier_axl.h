/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:54:45
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANECEAVERIFIER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANECEAVERIFIER_H

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
class CaseOptionsArcaneCeaVerifier
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'trace'
      // Generating multiple arity CaseOption for complex option value 'trace'
  class CaseOptionTraceValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionTraceValue ThatClass;

    CaseOptionTraceValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , variableName(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "variable-name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , uniqueId(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "unique-id", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))

    {

variableName.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("nom-variable"));
uniqueId.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("unique-id"));

    }
 public:
  // Interfaces for multi-arity class CaseOptionsTrace
  
    Arcane::ConstArrayView<  Arcane::Integer > getUniqueId() { return uniqueId.values(); }
    Arcane::String getVariableName() { return variableName(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    variableName;
  Arcane::CaseOptionMultiSimpleT< Arcane::Integer >   uniqueId;
  };

  // Generation for sub-option 'trace'
  class CaseOptionTrace
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionTraceValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionTraceValue * > BaseClass;

    typedef CaseOptionTraceValue value_type;

  public:

    CaseOptionTrace(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
    {
    // Generating translations and default values.
    addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("trace"));
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

    ~CaseOptionTrace()
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
  
  CaseOptionsArcaneCeaVerifier(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"arcane-cea-verifier"))
      , verify(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "verify", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , generate(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "generate", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , referenceFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "reference-file", _element(),
        /* default    */ "verif",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , compareParallelSequential(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "compare-parallel-sequential", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , resultFile(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "result-file", _element(),
        /* default    */ "compare.xml",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , verifierServiceName(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "verifier-service-name", _element(),
        /* default    */ "ArcaneBasicVerifier2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , trace(_configList(),
        /* name       */ "trace", _element())
  {

verify.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("verification-active"));
generate.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("generation"));
referenceFile.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("fichier-reference"));
compareParallelSequential.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("comparaison-parallele-sequentiel"));
resultFile.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("fichier-resultat"));
trace.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("trace"));
addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("verificateur"));
  }

public:
  // Interfaces for main CaseOptions
  
    bool getVerify() { return verify(); }
    bool getGenerate() { return generate(); }
    Arcane::String getReferenceFile() { return referenceFile(); }
    bool getCompareParallelSequential() { return compareParallelSequential(); }
    Arcane::String getResultFile() { return resultFile(); }
    Arcane::String getVerifierServiceName() { return verifierServiceName(); }
 
 
 
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

  
  Arcane::CaseOptionBool    verify;
  Arcane::CaseOptionBool    generate;
  Arcane::CaseOptionString    referenceFile;
  Arcane::CaseOptionBool    compareParallelSequential;
  Arcane::CaseOptionString    resultFile;
  Arcane::CaseOptionString    verifierServiceName;
  CaseOptionTrace   trace;
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
// Arcane version 1.0 : 05/30/2024 13:54:45
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANECEAVERIFIER_H
#define ARCANE_MODULE_AXLSTAR_ARCANECEAVERIFIER_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableTypes.h"
#include "arcane/EntryPoint.h"
#include "arcane/ISubDomain.h"
#include "arcane/ModuleBuildInfo.h"
#include "arcane/ModuleFactory.h"
#include "arcane/ServiceRegisterer.h"
#include "arcane/BasicModule.h"
#include "arcane/ServiceInfo.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{
class ISubDomain;
class IModule;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsArcaneCeaVerifier;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneArcaneCeaVerifierObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("ArcaneCeaVerifier_arcane_cea");
    si->setAxlVersion(0.0);
    si->setDefaultTagName(Arcane::String("arcane-cea-verifier"));
    si->setAxlContent(getAxlContent());
    si->setTagName(Arcane::String("verificateur"),Arcane::String("fr"));
  }

public:

  ArcaneArcaneCeaVerifierObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsArcaneCeaVerifier(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "VerifierOnExit", 
                  &ArcaneArcaneCeaVerifierObject::onExit,
                  Arcane::IEntryPoint::WExit,
                  Arcane::IEntryPoint::PAutoLoadEnd);
    addEntryPoint(this, "VerifierOnInit", 
                  &ArcaneArcaneCeaVerifierObject::onInit,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PAutoLoadBegin);
  }

  virtual ~ArcaneArcaneCeaVerifierObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void onExit() = 0; // OnExit
  virtual void onInit() = 0; // OnInit

  //! Options du jeu de données du module
  CaseOptionsArcaneCeaVerifier* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsArcaneCeaVerifier* m_options;

protected:

  //! Variables du module
    
private:
 static Arcane::FileContent getAxlContent()
 {
   const char* str_content = "";
   const Arcane::Byte* content = (const Arcane::Byte*)(str_content);
   Arcane::Span<const Arcane::Byte> bytes(content,0);
   int file_version = 1;
   return Arcane::FileContent(bytes,file_version,"");
 }

};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#define ARCANE_REGISTER_MODULE_ARCANECEAVERIFIER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("ArcaneCeaVerifier",true))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane
 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

