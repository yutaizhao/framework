/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CASEOPTIONSTESTER_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST_CASEOPTIONSTESTER_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"
#include "arcane/ItemGroup.h"
#include "arcane/CaseOptionService.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_BEGIN_NAMESPACE
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::CellGroup &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::FaceGroup &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   ArcaneTest::TestRealInt &);
extern "C++" bool 
_caseOptionConvert(const Arcane::CaseOptionBase&,
                   const Arcane::String&,
                   Arcane::CellGroup &);
ARCANE_END_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsCaseOptionsTester
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'complex1-sub'
      // Generating simple arity CaseOption for option 'complex1-sub'
  class CaseOptionComplex1Sub
    : public Arcane::CaseOptions
    , private IComplex1SubInterface
  {
  public:

    CaseOptionComplex1Sub(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , subTest1(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "sub-test1", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , subTest2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "sub-test2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
    {

    }
        
    const CaseOptionComplex1Sub& operator()() const { return *this; }

  public:

    IComplex1SubInterface* _interface() { return this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::RealConstArrayView getSubTest1() { return subTest1(); }
    Arcane::Real3x3 getSubTest2() { return subTest2(); }
 
 
 
   // Interfaces for complex options
      bool hasSubTest1() const
      { return subTest1.isPresent(); }
      bool hasSubTest2() const
      { return subTest2.isPresent(); }
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionRealArray    subTest1;
  Arcane::CaseOptionReal3x3    subTest2;

  };
  // Generation for option 'complex1'
      // Generating simple arity CaseOption for option 'complex1'
  class CaseOptionComplex1
    : public Arcane::CaseOptions
    , private IComplex1Interface
  {
  public:

    CaseOptionComplex1(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , simpleReal2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , simpleReal2Multi(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-2-multi", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ -1,
        /* optional   */ false))
      , simpleInteger2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal32(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real3-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
     , simpleEnum2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
      , extendedRealInt2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int-2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* type       */ "ArcaneTest::TestRealInt")
      , complex1Sub(_configList(),
        /* name       */ "complex1-sub", _element(),
        /* optional   */ true)
      , complex1Subref(_configList(),
        /* name       */ "complex1-subref", _element())
    {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnum2.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnum2.addEnumValue(x,false);
      }
    }
        
    const CaseOptionComplex1& operator()() const { return *this; }

  public:

    IComplex1Interface* _interface() { return this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::ConstArrayView<  Arcane::Real > getSimpleReal2Multi() { return simpleReal2Multi.values(); }
    Arcane::Real getSimpleReal2() { return simpleReal2(); }
    Arcane::Integer getSimpleInteger2() { return simpleInteger2(); }
    Arcane::Real3 getSimpleReal32() { return simpleReal32(); }
 
 
    ArcaneTest::TestRealInt getExtendedRealInt2() { return extendedRealInt2(); }
     TypesCaseOptionsTester::eSimpleEnum getSimpleEnum2() { return simpleEnum2(); }
 
   // Interfaces for complex options
    IComplex1SubInterface* getComplex1Sub() { return complex1Sub._interface(); }
          IComplex1SubInterface* getComplex1Subref() { return complex1Subref._interface(); }
         bool hasSimpleReal2() const
      { return simpleReal2.isPresent(); }
      bool hasExtendedRealInt2() const
      { return extendedRealInt2.isPresent(); }
      bool hasSimpleEnum2() const
      { return simpleEnum2.isPresent(); }
      bool hasComplex1Sub() const
      { return complex1Sub.isPresent(); }
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionReal    simpleReal2;
  Arcane::CaseOptionMultiSimpleT< Arcane::Real >   simpleReal2Multi;
  Arcane::CaseOptionInteger    simpleInteger2;
  Arcane::CaseOptionReal3    simpleReal32;
  Arcane::CaseOptionEnumT< TypesCaseOptionsTester::eSimpleEnum >   simpleEnum2;
  Arcane::CaseOptionExtendedT< ArcaneTest::TestRealInt >   extendedRealInt2;
  CaseOptionComplex1Sub   complex1Sub;
  CaseOptionComplex1Sub   complex1Subref;

  };
  // Generation for option 'complex3'
      // Generating multiple arity CaseOption for complex option value 'complex3'
  class CaseOptionComplex3Value
  : public Arcane::CaseOptionComplexValue
    , private IComplex3Interface
  {
  public:

    typedef CaseOptionComplex3Value ThatClass;

    CaseOptionComplex3Value(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , simpleRealC3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-c3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , simpleIntegerC3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-c3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , timeloopTester(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "timeloop-tester", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
     , simpleEnumC3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum-c3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
      , extendedRealIntC3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int-c3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "ArcaneTest::TestRealInt")

    {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnumC3.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnumC3.addEnumValue(x,false);
      }

    }
 public:
  // Interfaces for multi-arity class CaseOptionsComplex3
  
    Arcane::ConstArrayView<  Arcane::Real > getSimpleRealC3() { return simpleRealC3.values(); }
    Arcane::ConstArrayView<  Arcane::Integer > getSimpleIntegerC3() { return simpleIntegerC3.values(); }
 
    Arcane::ConstArrayView<  ArcaneTest::TestRealInt > getExtendedRealIntC3() { return extendedRealIntC3; }
 
    Arcane::ConstArrayView<  TypesCaseOptionsTester::eSimpleEnum > getSimpleEnumC3() { return simpleEnumC3; }
 
     Arcane::ITimeLoopService* getTimeloopTester() { return timeloopTester(); }
  // Interfaces for complex options
  
  
    IComplex3Interface* _interface() { return this; }
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionMultiSimpleT< Arcane::Real >   simpleRealC3;
  Arcane::CaseOptionMultiSimpleT< Arcane::Integer >   simpleIntegerC3;
  Arcane::CaseOptionServiceT< Arcane::ITimeLoopService >   timeloopTester;
  Arcane::CaseOptionMultiEnumT< TypesCaseOptionsTester::eSimpleEnum  >   simpleEnumC3;
  Arcane::CaseOptionMultiExtendedT< ArcaneTest::TestRealInt  >   extendedRealIntC3;
  };

  // Generation for sub-option 'complex3'
  class CaseOptionComplex3
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionComplex3Value * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionComplex3Value * > BaseClass;

    typedef CaseOptionComplex3Value value_type;

  public:

    CaseOptionComplex3(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
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
      m_interfaces.resize(s);
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
        m_interfaces[i] = v[i]->_interface();
      }
    }

  public:

    ~CaseOptionComplex3()
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

  public: 

    Arcane::ConstArrayView< IComplex3Interface* > _interface()
      { return m_interfaces; }

  private: 

    Arcane::UniqueArray< IComplex3Interface* > m_interfaces;
  };
  
  // Generation for option 'complex2'
      // Generating multiple arity CaseOption for complex option value 'complex2'
  class CaseOptionComplex2Value
  : public Arcane::CaseOptionComplexValue
    , private IComplex2Interface
  {
  public:

    typedef CaseOptionComplex2Value ThatClass;

    CaseOptionComplex2Value(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , simpleRealC2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-c2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleBoolC2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-bool-c2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleIntegerC2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-c2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleIntegerC2WithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-c2-with-default", _element(),
        /* default    */ "35",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
     , simpleEnumC2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum-c2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
      , extendedRealIntC2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int-c2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "ArcaneTest::TestRealInt")
      , complex3Ref(_configList(),
        /* name       */ "complex3Ref", _element())
      , complex3(_configList(),
        /* name       */ "complex3", _element())

    {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnumC2.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnumC2.addEnumValue(x,false);
      }

    }
 public:
  // Interfaces for multi-arity class CaseOptionsComplex2
  
    Arcane::Real getSimpleRealC2() { return simpleRealC2(); }
    bool getSimpleBoolC2() { return simpleBoolC2(); }
    Arcane::Integer getSimpleIntegerC2() { return simpleIntegerC2(); }
    Arcane::Integer getSimpleIntegerC2WithDefault() { return simpleIntegerC2WithDefault(); }
 
 
    ArcaneTest::TestRealInt getExtendedRealIntC2() { return extendedRealIntC2(); }
     TypesCaseOptionsTester::eSimpleEnum getSimpleEnumC2() { return simpleEnumC2(); }
 
   // Interfaces for complex options
   Arcane::ConstArrayView<  IComplex3Interface* > getComplex3() { return complex3._interface(); }
    Arcane::ConstArrayView<  IComplex3Interface* > getComplex3Ref() { return complex3Ref._interface(); }
        
  
    IComplex2Interface* _interface() { return this; }
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionReal    simpleRealC2;
  Arcane::CaseOptionBool    simpleBoolC2;
  Arcane::CaseOptionInteger    simpleIntegerC2;
  Arcane::CaseOptionInteger    simpleIntegerC2WithDefault;
  Arcane::CaseOptionEnumT< TypesCaseOptionsTester::eSimpleEnum >   simpleEnumC2;
  Arcane::CaseOptionExtendedT< ArcaneTest::TestRealInt >   extendedRealIntC2;
  CaseOptionComplex3   complex3Ref;
  CaseOptionComplex3   complex3;
  };

  // Generation for sub-option 'complex2'
  class CaseOptionComplex2
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionComplex2Value * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionComplex2Value * > BaseClass;

    typedef CaseOptionComplex2Value value_type;

  public:

    CaseOptionComplex2(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,1,2) 
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
      m_interfaces.resize(s);
      for( Arcane::Integer i=0; i<s; ++i ){
        v[i] = new value_type(this,configList(),elist[i]);
        m_interfaces[i] = v[i]->_interface();
      }
    }

  public:

    ~CaseOptionComplex2()
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

  public: 

    Arcane::ConstArrayView< IComplex2Interface* > _interface()
      { return m_interfaces; }

  private: 

    Arcane::UniqueArray< IComplex2Interface* > m_interfaces;
  };
  
  // Generation for option 'complex4'
      // Generating simple arity CaseOption for option 'complex4'
  class CaseOptionComplex4
    : public Arcane::CaseOptions
    , private IComplex4Interface
  {
  public:

    CaseOptionComplex4(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , simpleReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
    {

    }
        
    const CaseOptionComplex4& operator()() const { return *this; }

  public:

    IComplex4Interface* _interface() { return this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::Real getSimpleReal() { return simpleReal(); }
 
 
 
   // Interfaces for complex options
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionReal    simpleReal;

  };
  // Generation for option 'complex6'
      // Generating simple arity CaseOption for option 'complex6'
  class CaseOptionComplex6
    : public Arcane::CaseOptions
  {
  public:

    CaseOptionComplex6(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , simpleReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
    {

    }
        
    const CaseOptionComplex6& operator()() const { return *this; }

 public:
  // Interfaces for simple arity CaseOptions
  
    Arcane::Real getSimpleReal() { return simpleReal(); }
 
 
 
   // Interfaces for complex options
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  Arcane::CaseOptionReal    simpleReal;

  };
  // Generation for option 'complex8'
      // Generating multiple arity CaseOption for complex option value 'complex8'
  class CaseOptionComplex8Value
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionComplex8Value ThatClass;

    CaseOptionComplex8Value(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , group(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* type       */ "Arcane::CellGroup")

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsComplex8
  
 
    Arcane::ConstArrayView<  Arcane::CellGroup > getGroup() { return group; }
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionMultiExtendedT< Arcane::CellGroup  >   group;
  };

  // Generation for sub-option 'complex8'
  class CaseOptionComplex8
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionComplex8Value * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionComplex8Value * > BaseClass;

    typedef CaseOptionComplex8Value value_type;

  public:

    CaseOptionComplex8(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,-1) 
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

    ~CaseOptionComplex8()
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
  
  // Generation for option 'complex7'
      // Generating simple arity CaseOption for option 'complex7'
  class CaseOptionComplex7
    : public Arcane::CaseOptions
  {
  public:

    CaseOptionComplex7(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element, bool is_optional=false)
      : Arcane::CaseOptions(icl,s,element,is_optional)
      , complex8(_configList(),
        /* name       */ "complex8", _element())
    {

    }
        
    const CaseOptionComplex7& operator()() const { return *this; }

 public:
  // Interfaces for simple arity CaseOptions
  
 
 
 
   // Interfaces for complex options
  
  
  private:
    // Méthodes pour unifier la construction des options.
    Arcane::ICaseOptionList* _configList() { return configList(); }
    Arcane::XmlNode _element() { return Arcane::XmlNode(); }

  public:
  
  CaseOptionComplex8   complex8;

  };

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Non Complex Options -------------------------*/
  /*-------------------------------------------------------------------------*/
  
  CaseOptionsCaseOptionsTester(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"case-options-tester"))
      , testId(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-id", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , hasMultipleMesh(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "has-multiple-mesh", _element(),
        /* default    */ "false",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , maxIteration(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "max-iteration", _element(),
        /* default    */ "10",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealOptional(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-optional", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true))
      , simpleReal2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal2x2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real2x2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal3x3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real3x3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleInt32(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-int32", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleInt64(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-int64", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleBool(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-bool", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleString(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-string", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleStringMultiple(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-string-multiple", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , simpleRealArray(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealArrayMulti(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-array-multi", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 5,
        /* optional   */ false))
      , simpleIntegerArray(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleInt32Array(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-int32-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleInt64Array(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-int64-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleBoolArray(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-bool-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleStringArray(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-string-array", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealUnit(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-unit", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* unit       */ "m")

      , simpleRealUnit2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-unit2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* unit       */ "m")

      , simpleRealarrayUnit(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-realarray-unit", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* unit       */ "cm")

      , simpleWithStandardFunction(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-with-standard-function", _element(),
        /* default    */ "0.5",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealWithDynamicDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-with-dynamic-default", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real-with-default", _element(),
        /* default    */ "1.0",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleRealarrayWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-realarray-with-default", _element(),
        /* default    */ "1.0 3.5",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleReal3WithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-real3-with-default", _element(),
        /* default    */ "1.0 3.5 4.6",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleIntegerWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-integer-with-default", _element(),
        /* default    */ "5",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleBoolWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-bool-with-default", _element(),
        /* default    */ "true",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , simpleStringWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-string-with-default", _element(),
        /* default    */ "foo",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , infinityReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "infinity-real", _element(),
        /* default    */ "infinity",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
    , postProcessor1(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "post-processor1", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* allow-null */ false)
    , postProcessor2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "post-processor2", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false),
        /* allow-null */ false)
      , postProcessor3(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "post-processor3", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , postProcessor4(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "post-processor4", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , testServiceWithDynamicDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "test-service-with-dynamic-default", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , serviceInstanceTest1(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "service-instance-test1", _element(),
        /* default    */ "ServiceTestImpl4",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
      , serviceInstanceTest2(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "service-instance-test2", _element(),
        /* default    */ "ServiceInterface5Impl",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* allow-null */ false,
        /* optional   */ false)
     , simpleEnum(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
     , simpleEnumFunction(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum-function", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
     , simpleEnumWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "simple-enum-with-default", _element(),
        /* default    */ "enum2",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "TypesCaseOptionsTester::eSimpleEnum")
      , extendedRealInt(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "ArcaneTest::TestRealInt")
      , extendedRealIntOptional(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int-optional", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ true),
        /* type       */ "ArcaneTest::TestRealInt")
      , cellGroupWithDynamicDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "cell-group-with-dynamic-default", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::CellGroup")
      , faceGroupWithDynamicDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "face-group-with-dynamic-default", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "Arcane::FaceGroup")
      , extendedRealIntWithDefault(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "extended-real-int-with-default", _element(),
        /* default    */ "2. 3",
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false),
        /* type       */ "ArcaneTest::TestRealInt")
      , complex1(_configList(),
        /* name       */ "complex1", _element())
      , complex2(_configList(),
        /* name       */ "complex2", _element())
      , complex4(_configList(),
        /* name       */ "complex4", _element())
      , complex5(_configList(),
        /* name       */ "complex5", _element())
      , complex6(_configList(),
        /* name       */ "complex6", _element(),
        /* optional   */ true)
      , complex7(_configList(),
        /* name       */ "complex7", _element())
  {

      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnum.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnum.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnumFunction.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnumFunction.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum1"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum1));
        simpleEnumWithDefault.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum2"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum2));
        simpleEnumWithDefault.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum3"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum3));
        simpleEnumWithDefault.addEnumValue(x,false);
      }
      {
        auto x = new Arcane::CaseOptionEnumValue(
          /* enum value name */ Arcane::String("enum4"),
          /* enum object     */ (int)(TypesCaseOptionsTester::SEEnum4));
        simpleEnumWithDefault.addEnumValue(x,false);
      }
      simpleReal.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("25.3"));
            simpleReal3.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("25.1 12.3 1.0"));
            simpleReal3.addDefaultValue(
          /* category         */ Arcane::String("X2"),
          /* default value    */ Arcane::String("3.5 2.3 -1.0e3"));
            simpleReal3.addDefaultValue(
          /* category         */ Arcane::String("X3"),
          /* default value    */ Arcane::String("-2.1 -1.5 +1.0e5"));
            simpleInt32Array.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("3 -4 5 -6 7"));
            simpleInt32Array.addDefaultValue(
          /* category         */ Arcane::String("X3"),
          /* default value    */ Arcane::String("-1 0 23 42"));
            simpleEnum.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("enum2"));
            simpleEnum.addDefaultValue(
          /* category         */ Arcane::String("X3"),
          /* default value    */ Arcane::String("enum1"));
      simpleEnumWithDefault.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("simple-enum-avec-defaut"));
      simpleEnumWithDefault.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("enum3"));
            simpleEnumWithDefault.addDefaultValue(
          /* category         */ Arcane::String("X2"),
          /* default value    */ Arcane::String("enum4"));
            simpleEnumWithDefault.addDefaultValue(
          /* category         */ Arcane::String("X3"),
          /* default value    */ Arcane::String("enum4"));
      postProcessor1.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("post-processor1-fr"));
postProcessor3.addAlternativeNodeName(
          /* language         */ Arcane::String("fr"),
          /* alternative name */ Arcane::String("post-processor3-fr"));
      serviceInstanceTest1.addDefaultValue(
          /* category         */ Arcane::String("X1"),
          /* default value    */ Arcane::String("ServiceTestImpl2"));
            serviceInstanceTest1.addDefaultValue(
          /* category         */ Arcane::String("X2"),
          /* default value    */ Arcane::String("ServiceTestImpl3"));
               postProcessor3.setMeshName(Arcane::String("Mesh1"));
         serviceInstanceTest1.setMeshName(Arcane::String("Mesh1"));
         serviceInstanceTest2.setMeshName(Arcane::String("Mesh1"));
  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::ConstArrayView<  Arcane::String > getSimpleStringMultiple() { return simpleStringMultiple.values(); }
    Arcane::ConstArrayView<  Arcane::RealArray > getSimpleRealArrayMulti() { return simpleRealArrayMulti.values(); }
    Arcane::Integer getTestId() { return testId(); }
    bool getHasMultipleMesh() { return hasMultipleMesh(); }
    Arcane::Integer getMaxIteration() { return maxIteration(); }
    Arcane::Real getSimpleReal() { return simpleReal(); }
    Arcane::Real getSimpleRealOptional() { return simpleRealOptional(); }
    Arcane::Real2 getSimpleReal2() { return simpleReal2(); }
    Arcane::Real3 getSimpleReal3() { return simpleReal3(); }
    Arcane::Real2x2 getSimpleReal2x2() { return simpleReal2x2(); }
    Arcane::Real3x3 getSimpleReal3x3() { return simpleReal3x3(); }
    Arcane::Integer getSimpleInteger() { return simpleInteger(); }
    Arcane::Int32 getSimpleInt32() { return simpleInt32(); }
    Arcane::Int64 getSimpleInt64() { return simpleInt64(); }
    bool getSimpleBool() { return simpleBool(); }
    Arcane::String getSimpleString() { return simpleString(); }
    Arcane::RealConstArrayView getSimpleRealArray() { return simpleRealArray(); }
    Arcane::IntegerConstArrayView getSimpleIntegerArray() { return simpleIntegerArray(); }
    Arcane::Int32ConstArrayView getSimpleInt32Array() { return simpleInt32Array(); }
    Arcane::Int64ConstArrayView getSimpleInt64Array() { return simpleInt64Array(); }
    Arcane::BoolConstArrayView getSimpleBoolArray() { return simpleBoolArray(); }
    Arcane::StringConstArrayView getSimpleStringArray() { return simpleStringArray(); }
    Arcane::Real getSimpleRealUnit() { return simpleRealUnit(); }
    Arcane::Real getSimpleRealUnit2() { return simpleRealUnit2(); }
    Arcane::RealConstArrayView getSimpleRealarrayUnit() { return simpleRealarrayUnit(); }
    Arcane::Real getSimpleWithStandardFunction() { return simpleWithStandardFunction(); }
    Arcane::Real getSimpleRealWithDynamicDefault() { return simpleRealWithDynamicDefault(); }
    Arcane::Real getSimpleRealWithDefault() { return simpleRealWithDefault(); }
    Arcane::RealConstArrayView getSimpleRealarrayWithDefault() { return simpleRealarrayWithDefault(); }
    Arcane::Real3 getSimpleReal3WithDefault() { return simpleReal3WithDefault(); }
    Arcane::Integer getSimpleIntegerWithDefault() { return simpleIntegerWithDefault(); }
    bool getSimpleBoolWithDefault() { return simpleBoolWithDefault(); }
    Arcane::String getSimpleStringWithDefault() { return simpleStringWithDefault(); }
    Arcane::Real getInfinityReal() { return infinityReal(); }
 
 
    ArcaneTest::TestRealInt getExtendedRealInt() { return extendedRealInt(); }
    ArcaneTest::TestRealInt getExtendedRealIntOptional() { return extendedRealIntOptional(); }
    Arcane::CellGroup getCellGroupWithDynamicDefault() { return cellGroupWithDynamicDefault(); }
    Arcane::FaceGroup getFaceGroupWithDynamicDefault() { return faceGroupWithDynamicDefault(); }
    ArcaneTest::TestRealInt getExtendedRealIntWithDefault() { return extendedRealIntWithDefault(); }
     TypesCaseOptionsTester::eSimpleEnum getSimpleEnum() { return simpleEnum(); }
     TypesCaseOptionsTester::eSimpleEnum getSimpleEnumFunction() { return simpleEnumFunction(); }
     TypesCaseOptionsTester::eSimpleEnum getSimpleEnumWithDefault() { return simpleEnumWithDefault(); }
 
   Arcane::ConstArrayView< Arcane::IPostProcessorWriter* > getPostProcessor1() { return postProcessor1; }
   Arcane::ConstArrayView< Arcane::IPostProcessorWriter* > getPostProcessor2() { return postProcessor2; }
     Arcane::IPostProcessorWriter* getPostProcessor3() { return postProcessor3(); }
    Arcane::IPostProcessorWriter* getPostProcessor4() { return postProcessor4(); }
    ArcaneTest::IServiceInterface1* getTestServiceWithDynamicDefault() { return testServiceWithDynamicDefault(); }
    ArcaneTest::IServiceInterface1* getServiceInstanceTest1() { return serviceInstanceTest1(); }
    ArcaneTest::IServiceInterface1* getServiceInstanceTest2() { return serviceInstanceTest2(); }
  // Interfaces for complex options
   Arcane::ConstArrayView<  IComplex2Interface* > getComplex2() { return complex2._interface(); }
    IComplex1Interface* getComplex1() { return complex1._interface(); }
   IComplex4Interface* getComplex4() { return complex4._interface(); }
          IComplex4Interface* getComplex5() { return complex5._interface(); }
         bool hasSimpleRealOptional() const
      { return simpleRealOptional.isPresent(); }
      bool hasExtendedRealIntOptional() const
      { return extendedRealIntOptional.isPresent(); }
      bool hasComplex6() const
      { return complex6.isPresent(); }
  
  
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

  
  Arcane::CaseOptionInteger    testId;
  Arcane::CaseOptionBool    hasMultipleMesh;
  Arcane::CaseOptionInteger    maxIteration;
  Arcane::CaseOptionReal    simpleReal;
  Arcane::CaseOptionReal    simpleRealOptional;
  Arcane::CaseOptionReal2    simpleReal2;
  Arcane::CaseOptionReal3    simpleReal3;
  Arcane::CaseOptionReal2x2    simpleReal2x2;
  Arcane::CaseOptionReal3x3    simpleReal3x3;
  Arcane::CaseOptionInteger    simpleInteger;
  Arcane::CaseOptionInt32    simpleInt32;
  Arcane::CaseOptionInt64    simpleInt64;
  Arcane::CaseOptionBool    simpleBool;
  Arcane::CaseOptionString    simpleString;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   simpleStringMultiple;
  Arcane::CaseOptionRealArray    simpleRealArray;
  Arcane::CaseOptionMultiSimpleT< Arcane::RealArray >   simpleRealArrayMulti;
  Arcane::CaseOptionIntegerArray    simpleIntegerArray;
  Arcane::CaseOptionInt32Array    simpleInt32Array;
  Arcane::CaseOptionInt64Array    simpleInt64Array;
  Arcane::CaseOptionBoolArray    simpleBoolArray;
  Arcane::CaseOptionStringArray    simpleStringArray;
  Arcane::CaseOptionReal    simpleRealUnit;
  Arcane::CaseOptionReal    simpleRealUnit2;
  Arcane::CaseOptionRealArray    simpleRealarrayUnit;
  Arcane::CaseOptionReal    simpleWithStandardFunction;
  Arcane::CaseOptionReal    simpleRealWithDynamicDefault;
  Arcane::CaseOptionReal    simpleRealWithDefault;
  Arcane::CaseOptionRealArray    simpleRealarrayWithDefault;
  Arcane::CaseOptionReal3    simpleReal3WithDefault;
  Arcane::CaseOptionInteger    simpleIntegerWithDefault;
  Arcane::CaseOptionBool    simpleBoolWithDefault;
  Arcane::CaseOptionString    simpleStringWithDefault;
  Arcane::CaseOptionReal    infinityReal;
  Arcane::CaseOptionMultiServiceT< Arcane::IPostProcessorWriter  >   postProcessor1;
  Arcane::CaseOptionMultiServiceT< Arcane::IPostProcessorWriter  >   postProcessor2;
  Arcane::CaseOptionServiceT< Arcane::IPostProcessorWriter >   postProcessor3;
  Arcane::CaseOptionServiceT< Arcane::IPostProcessorWriter >   postProcessor4;
  Arcane::CaseOptionServiceT< ArcaneTest::IServiceInterface1 >   testServiceWithDynamicDefault;
  Arcane::CaseOptionServiceT< ArcaneTest::IServiceInterface1 >   serviceInstanceTest1;
  Arcane::CaseOptionServiceT< ArcaneTest::IServiceInterface1 >   serviceInstanceTest2;
  Arcane::CaseOptionEnumT< TypesCaseOptionsTester::eSimpleEnum >   simpleEnum;
  Arcane::CaseOptionEnumT< TypesCaseOptionsTester::eSimpleEnum >   simpleEnumFunction;
  Arcane::CaseOptionEnumT< TypesCaseOptionsTester::eSimpleEnum >   simpleEnumWithDefault;
  Arcane::CaseOptionExtendedT< ArcaneTest::TestRealInt >   extendedRealInt;
  Arcane::CaseOptionExtendedT< ArcaneTest::TestRealInt >   extendedRealIntOptional;
  Arcane::CaseOptionExtendedT< Arcane::CellGroup >   cellGroupWithDynamicDefault;
  Arcane::CaseOptionExtendedT< Arcane::FaceGroup >   faceGroupWithDynamicDefault;
  Arcane::CaseOptionExtendedT< ArcaneTest::TestRealInt >   extendedRealIntWithDefault;
  CaseOptionComplex1   complex1;
  CaseOptionComplex2   complex2;
  CaseOptionComplex4   complex4;
  CaseOptionComplex4   complex5;
  CaseOptionComplex6   complex6;
  CaseOptionComplex7   complex7;
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
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST_CASEOPTIONSTESTER_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST_CASEOPTIONSTESTER_H

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

namespace ArcaneTest {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsCaseOptionsTester;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneCaseOptionsTesterObject
  : public Arcane::BasicModule
  , public ArcaneTest::ICaseOptionTestInterface
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("CaseOptionsTester_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("case-options-tester"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneCaseOptionsTesterObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
  {
    m_options = new CaseOptionsCaseOptionsTester(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
  }

  virtual ~ArcaneCaseOptionsTesterObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée

  //! Options du jeu de données du module
  CaseOptionsCaseOptionsTester* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsCaseOptionsTester* m_options;

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

#define ARCANE_REGISTER_MODULE_CASEOPTIONSTESTER(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("CaseOptionsTester",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

