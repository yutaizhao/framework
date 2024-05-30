/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
// #WARNING#: This file has been generated automatically. Do not edit.
// Arcane version 1.0 : 05/30/2024 13:55:04
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#ifndef ARCANE_CASEOPTION_AXLSTAR_ARCANETEST__CUSTOMMESH_CUSTOMMESHTEST_H
#define ARCANE_CASEOPTION_AXLSTAR_ARCANETEST__CUSTOMMESH_CUSTOMMESHTEST_H

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/String.h"

#include "arcane/CaseOptions.h"
#include "arcane/CaseOptionsMulti.h"
#include "arcane/CaseOptionBuildInfo.h"
#include "arcane/XmlNodeList.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace ArcaneTest::CustomMesh {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Options
class CaseOptionsCustomMeshTest
{
public:

  /*-------------------------------------------------------------------------*/
  /*--------------------------- Complex Options -----------------------------*/
  /*-------------------------------------------------------------------------*/
  // Generation for option 'mesh-size'
      // Generating multiple arity CaseOption for complex option value 'mesh-size'
  class CaseOptionMeshSizeTypeValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionMeshSizeTypeValue ThatClass;

    CaseOptionMeshSizeTypeValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , nbCells(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-cells", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbFaces(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-faces", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbEdges(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-edges", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , nbNodes(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-nodes", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsMeshSizeType
  
    Arcane::Integer getNbCells() { return nbCells(); }
    Arcane::Integer getNbFaces() { return nbFaces(); }
    Arcane::Integer getNbEdges() { return nbEdges(); }
    Arcane::Integer getNbNodes() { return nbNodes(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionInteger    nbCells;
  Arcane::CaseOptionInteger    nbFaces;
  Arcane::CaseOptionInteger    nbEdges;
  Arcane::CaseOptionInteger    nbNodes;
  };

  // Generation for sub-option 'mesh-size'
  class CaseOptionMeshSizeType
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionMeshSizeTypeValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionMeshSizeTypeValue * > BaseClass;

    typedef CaseOptionMeshSizeTypeValue value_type;

  public:

    CaseOptionMeshSizeType(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,1) 
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

    ~CaseOptionMeshSizeType()
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
  
  // Generation for option 'coords'
      // Generating multiple arity CaseOption for complex option value 'coords'
  class CaseOptionCoordsTypeValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionCoordsTypeValue ThatClass;

    CaseOptionCoordsTypeValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , value(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "value", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsCoordsType
  
    Arcane::ConstArrayView<  Arcane::Real3 > getValue() { return value.values(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionMultiSimpleT< Arcane::Real3 >   value;
  };

  // Generation for sub-option 'coords'
  class CaseOptionCoordsType
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionCoordsTypeValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionCoordsTypeValue * > BaseClass;

    typedef CaseOptionCoordsTypeValue value_type;

  public:

    CaseOptionCoordsType(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,1) 
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

    ~CaseOptionCoordsType()
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
  
  // Generation for option 'mesh-coordinates'
      // Generating multiple arity CaseOption for complex option value 'mesh-coordinates'
  class CaseOptionMeshCoordinatesTypeValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionMeshCoordinatesTypeValue ThatClass;

    CaseOptionMeshCoordinatesTypeValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , doCheck(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "do-check", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , coords(_configList(),
        /* name       */ "coords", _element())

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsMeshCoordinatesType
  
    bool getDoCheck() { return doCheck(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionBool    doCheck;
  CaseOptionCoordsType   coords;
  };

  // Generation for sub-option 'mesh-coordinates'
  class CaseOptionMeshCoordinatesType
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionMeshCoordinatesTypeValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionMeshCoordinatesTypeValue * > BaseClass;

    typedef CaseOptionMeshCoordinatesTypeValue value_type;

  public:

    CaseOptionMeshCoordinatesType(Arcane::ICaseOptionList* icl,
              const Arcane::String& s, const Arcane::XmlNode& element)
      : Arcane::CaseOptionsMulti(icl,s,element,0,1) 
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

    ~CaseOptionMeshCoordinatesType()
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
  
  // Generation for option 'check-group'
      // Generating multiple arity CaseOption for complex option value 'check-group'
  class CaseOptionCheckGroupValue
  : public Arcane::CaseOptionComplexValue
  {
  public:

    typedef CaseOptionCheckGroupValue ThatClass;

    CaseOptionCheckGroupValue(Arcane::ICaseOptionsMulti* opt,Arcane::ICaseOptionList* icl, const Arcane::XmlNode& element)
    : Arcane::CaseOptionComplexValue(opt,icl,element)
      , name(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "name", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , size(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "size", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))

    {


    }
 public:
  // Interfaces for multi-arity class CaseOptionsCheckGroup
  
    Arcane::String getName() { return name(); }
    Arcane::Integer getSize() { return size(); }
 
 
 
   // Interfaces for complex options
  
  
  public:

    const ThatClass* operator->() const { return this; }

  public:
   
  Arcane::CaseOptionString    name;
  Arcane::CaseOptionInteger    size;
  };

  // Generation for sub-option 'check-group'
  class CaseOptionCheckGroup
    : public Arcane::CaseOptionsMulti
    , private Arcane::ArrayView< CaseOptionCheckGroupValue * >       
  {
  public:

    typedef Arcane::ArrayView< CaseOptionCheckGroupValue * > BaseClass;

    typedef CaseOptionCheckGroupValue value_type;

  public:

    CaseOptionCheckGroup(Arcane::ICaseOptionList* icl,
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

    ~CaseOptionCheckGroup()
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
  
  CaseOptionsCustomMeshTest(Arcane::ICaseMng* cm)
    : m_case_options(new Arcane::CaseOptions(cm,"custom-mesh-test"))
      , nbMeshGroup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "nb-mesh-group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 1,
        /* max-occurs */ 1,
        /* optional   */ false))
      , checkBoundaryFaceGroup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-boundary-face-group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkInternalFaceGroup(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-internal-face-group", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkCellVariableReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-cell-variable-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkCellVariableInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-cell-variable-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkCellVariableArrayReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-cell-variable-array-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkCellVariableArrayInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-cell-variable-array-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkNodeVariableReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-node-variable-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkNodeVariableInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-node-variable-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkNodeVariableArrayReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-node-variable-array-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkNodeVariableArrayInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-node-variable-array-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkFaceVariableReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-face-variable-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkFaceVariableInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-face-variable-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkFaceVariableArrayReal(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-face-variable-array-real", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , checkFaceVariableArrayInteger(Arcane::CaseOptionBuildInfo(_configList(),
        /* name       */ "check-face-variable-array-integer", _element(),
        /* default    */ Arcane::String(),
        /* min-occurs */ 0,
        /* max-occurs */ -1,
        /* optional   */ false))
      , meshSize(_configList(),
        /* name       */ "mesh-size", _element())
      , meshCoordinates(_configList(),
        /* name       */ "mesh-coordinates", _element())
      , checkGroup(_configList(),
        /* name       */ "check-group", _element())
  {

  }

public:
  // Interfaces for main CaseOptions
  
    Arcane::ConstArrayView<  Arcane::String > getCheckBoundaryFaceGroup() { return checkBoundaryFaceGroup.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckInternalFaceGroup() { return checkInternalFaceGroup.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckCellVariableReal() { return checkCellVariableReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckCellVariableInteger() { return checkCellVariableInteger.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckCellVariableArrayReal() { return checkCellVariableArrayReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckCellVariableArrayInteger() { return checkCellVariableArrayInteger.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckNodeVariableReal() { return checkNodeVariableReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckNodeVariableInteger() { return checkNodeVariableInteger.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckNodeVariableArrayReal() { return checkNodeVariableArrayReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckNodeVariableArrayInteger() { return checkNodeVariableArrayInteger.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckFaceVariableReal() { return checkFaceVariableReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckFaceVariableInteger() { return checkFaceVariableInteger.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckFaceVariableArrayReal() { return checkFaceVariableArrayReal.values(); }
    Arcane::ConstArrayView<  Arcane::String > getCheckFaceVariableArrayInteger() { return checkFaceVariableArrayInteger.values(); }
    Arcane::Integer getNbMeshGroup() { return nbMeshGroup(); }
 
 
 
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

  
  Arcane::CaseOptionInteger    nbMeshGroup;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkBoundaryFaceGroup;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkInternalFaceGroup;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkCellVariableReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkCellVariableInteger;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkCellVariableArrayReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkCellVariableArrayInteger;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkNodeVariableReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkNodeVariableInteger;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkNodeVariableArrayReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkNodeVariableArrayInteger;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkFaceVariableReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkFaceVariableInteger;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkFaceVariableArrayReal;
  Arcane::CaseOptionMultiSimpleT< Arcane::String >   checkFaceVariableArrayInteger;
  CaseOptionMeshSizeType   meshSize;
  CaseOptionMeshCoordinatesType   meshCoordinates;
  CaseOptionCheckGroup   checkGroup;
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

#ifndef ARCANE_MODULE_AXLSTAR_ARCANETEST__CUSTOMMESH_CUSTOMMESHTEST_H
#define ARCANE_MODULE_AXLSTAR_ARCANETEST__CUSTOMMESH_CUSTOMMESHTEST_H

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

namespace ArcaneTest::CustomMesh {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class CaseOptionsCustomMeshTest;

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

//! Generation de la classe de base du Module
class ArcaneCustomMeshTestObject
  : public Arcane::BasicModule
{
public:

  static void fillServiceInfo(Arcane::ServiceInfo* si)
  {
    si->setCaseOptionsFileName("CustomMeshTest_arcane_tests");
    si->setAxlVersion(1.0);
    si->setDefaultTagName(Arcane::String("custom-mesh-test"));
    si->setAxlContent(getAxlContent());
  }

public:

  ArcaneCustomMeshTestObject(const Arcane::ModuleBuildInfo& mb)
    : Arcane::BasicModule(mb)
    , m_options(nullptr)
    , m_cell_variable(Arcane::VariableBuildInfo(this, "CellVariable" ))
    , m_face_variable(Arcane::VariableBuildInfo(this, "FaceVariable" ))
    , m_node_variable(Arcane::VariableBuildInfo(this, "NodeVariable" ))
    , m_edge_variable(Arcane::VariableBuildInfo(this, "EdgeVariable" ))
  {
    m_options = new CaseOptionsCustomMeshTest(mb.subDomain()->caseMng());
    m_options->setCaseModule(this);
    addEntryPoint(this, "Init", 
                  &ArcaneCustomMeshTestObject::init,
                  Arcane::IEntryPoint::WInit,
                  Arcane::IEntryPoint::PNone);
  }

  virtual ~ArcaneCustomMeshTestObject()
  {
    delete m_options;
  }

public:

  //! points d'entrée
  virtual void init() = 0; // Init

  //! Options du jeu de données du module
  CaseOptionsCustomMeshTest* options() const { return m_options; }

private:

  //! Options du jeu de données du module
  CaseOptionsCustomMeshTest* m_options;

protected:

  //! Variables du module
  Arcane::VariableCellReal m_cell_variable;
  Arcane::VariableFaceReal m_face_variable;
  Arcane::VariableNodeReal m_node_variable;
  Arcane::VariableEdgeReal m_edge_variable;
    
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

#define ARCANE_REGISTER_MODULE_CUSTOMMESHTEST(class_name) \
  ARCANE_REGISTER_AXL_MODULE(class_name,Arcane::ModuleProperty("CustomMeshTest",false))

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

