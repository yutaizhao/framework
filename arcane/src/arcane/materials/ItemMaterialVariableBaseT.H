﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2022 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* ItemMaterialVariableBaseT.h                                 (C) 2000-2022 */
/*                                                                           */
/* Implémentation de la classe de base des variables matériaux.              */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/Mutex.h"
#include "arcane/utils/ArgumentException.h"
#include "arcane/utils/FatalErrorException.h"

#include "arcane/Observer.h"
#include "arcane/IMesh.h"
#include "arcane/IVariable.h"
#include "arcane/IItemFamily.h"
#include "arcane/VariableInfo.h"
#include "arcane/core/internal/IDataInternal.h"

#include "arcane/materials/MeshMaterialVariableRef.h"
#include "arcane/materials/ComponentItemListBuilder.h"

#include "arcane/core/materials/MaterialVariableBuildInfo.h"
#include "arcane/core/materials/IMeshMaterialMng.h"
#include "arcane/core/materials/IMeshMaterialVariableFactoryMng.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::Materials
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits>
ItemMaterialVariableBase<Traits>::
ItemMaterialVariableBase(const MaterialVariableBuildInfo& v,
                         PrivatePartType* global_var,
                         VariableRef* global_var_ref,MatVarSpace mvs)
: MeshMaterialVariable(v,mvs)
, m_global_variable(global_var)
, m_global_variable_ref(global_var_ref)
{
}


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits>
ItemMaterialVariableBase<Traits>::
~ItemMaterialVariableBase()
{
  Integer nb_var = m_p->m_refs.size();
  delete m_global_variable_ref;
  for( Integer i=1; i<nb_var; ++i ){
    delete m_p->m_refs[i];
  }
  m_p->m_refs.clear();
  m_vars.clear();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> IVariable*
ItemMaterialVariableBase<Traits>::
globalVariable() const
{
  return m_global_variable;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_init(ArrayView<PrivatePartType*> vars)
{
  if (!m_vars.empty())
    ARCANE_FATAL("Internal error: _init() already called");
  m_vars.addRange(vars);
  Integer nb_var = m_vars.size();
  m_views.resize(nb_var);
  // Il faut maintenir une référence sur les variables qu'on possède pour
  // être sur qu'elles sont bien initialisées et qu'elles ne seront pas détruites
  // tant que cette instance existe.
  m_p->m_refs.resize(nb_var);
  for( Integer i=0; i<nb_var; ++i ){
    // m_vars[i] peut être nul si notre variable est une variable uniquement milieu.
    m_p->m_refs[i] = nullptr;
    m_views[i] = ContainerViewType();
    if (i==0){
      // Pour la variable globale, il s'agit d'une variable maillage.
      m_p->m_refs[i] = m_global_variable_ref;
    }
    else{
      // Pour les autres, il s'agit d'une variable tableau.
      if (m_vars[i])
        m_p->m_refs[i] = new VariableRefType(m_vars[i]);
    }
    // TODO: il faut pouvoir être notifié du changement de cette variable.
    // pour ensuite mettre à jour les vues (peut-être aussi faire un MyVariableRef).
    if (m_vars[i])
      m_views[i] = m_vars[i]->valueView();
    //std::cout << "INIT_VIEW: " << i << " v=" << m_views[i].size() << '\n';
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
buildFromManager(bool is_continue)
{
  IMeshMaterialMng* mat_mng = m_p->materialMng();

  // Il faut récupérer (ou créér) les autres variables.
  //ConstArrayView<IMeshMaterial*> materials = mat_mng->materials();
  ConstArrayView<MeshMaterialVariableIndexer*> indexers = mat_mng->variablesIndexer();
  Integer nb_indexer = indexers.size();
  UniqueArray<PrivatePartType*> all_vars(nb_indexer+1);
  all_vars[0] = m_global_variable;
  IMesh* mesh = m_global_variable->mesh();

  // Il faut attacher un observer sur la variable globale pour savoir quand elle change.
  // Pour les variables partielles, cela se fait automatiquement lorsque le matériau associé change.
  m_p->m_global_variable_changed_observer = new ObserverT<ThatClass>(this,&ThatClass::_syncFromGlobalVariable);
  m_global_variable->onSizeChangedObservable()->attachObserver(m_p->m_global_variable_changed_observer);

  m_p->m_modified_times.resize(nb_indexer);
  m_p->m_modified_times.fill(0);

  bool is_env_only = m_p->space()==MatVarSpace::Environment;
  //TODO: regarder s'il faut stocker les propriétés de cette variable
  // avant sa création
  int property = m_global_variable->property();
  for( Integer i=0; i<nb_indexer; ++i ){
    MeshMaterialVariableIndexer* indexer = indexers[i];
    // Ne fait rien si on est uniquement une variable milieu et que l'indexeur
    // n'est pas associé à un milieu.
    if (is_env_only && !indexer->isEnvironment()){
      all_vars[i+1] = nullptr;
      continue;
    }
    // Prend le nom spécifié pour le nom de la variable matériau s'il existe
    String var_name = indexer->wantedVariableName();
    bool is_compat = false;
    // Si un nom est spécifié, il s'agit du mode de compatibilité
    // avec Troll et dans ce cas la variable n'est pas associée
    // au maillage.
    if (var_name.null())
      var_name = String("Mat")+indexer->name()+"_"+this->name();
    else{
      var_name = var_name + "_" + this->name();
      is_compat = true;
    }

    
    //Note: Ces variables ne sont pas associées au maillage.
    // Il s'agit juste de variables tableau.
    IVariable* var = 0;
    if (is_compat){
      VariableBuildInfo vbi2(mesh->subDomain(),var_name,property);
      VariableInfo vi = VariableRefType::_internalVariableInfo(vbi2);
      var = PrivatePartType::getReference(vbi2,vi);
    }
    else{
      VariableBuildInfo vbi2(mesh,var_name,property);
      VariableInfo vi = VariableRefType::_internalVariableInfo(vbi2);
      var = PrivatePartType::getReference(vbi2,vi);
    }
    // Tag la variable pour les codes qui voudraient savoir qu'il
    // s'agit d'une variable matériau.
    var->addTag("Material","1");
    PrivatePartType* true_ptr = dynamic_cast<PrivatePartType*>(var);
    ARCANE_CHECK_POINTER(true_ptr);
    all_vars[i+1] = true_ptr;
    if (!is_continue){
      // TODO: regarder si setUsed() est nécessaire.
      true_ptr->setUsed(true);
      // Dimensionne la variable à la taille du tableau des valeurs mixtes.
      Traits::resizeWithReserve(true_ptr,indexer->maxIndexInMultipleArray());
    }
  }
  this->_init(all_vars);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_syncFromGlobalVariable()
{
  // Cette méthode est appelée lorsque la taille de la variable globale
  // change. Cette variable est la première variable de la liste.
  // Il faut ensuite notifier toutes les références de ce changement.
  m_views[0] = m_vars[0]->valueView();

  for( MeshMaterialVariableRef::Enumerator i(this); i.hasNext(); ++i ){
    MeshMaterialVariableRef* ref = *i;
    ref->updateFromInternal();
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
syncReferences()
{
  ConstArrayView<MeshMaterialVariableIndexer*> indexers = m_p->materialMng()->variablesIndexer();
  Integer nb_indexer = indexers.size();
  for( Integer i=0; i<nb_indexer; ++i ){
    MeshMaterialVariableIndexer* indexer = indexers[i];
    PrivatePartType* true_ptr = m_vars[i+1];
    if (true_ptr)
      Traits::resizeWithReserve(true_ptr,indexer->maxIndexInMultipleArray());
  }

  Integer nb_var = m_vars.size();
  for( Integer i=0; i<nb_var; ++i ){
    m_views[i] = ContainerViewType();
    if (m_vars[i])
      m_views[i] = m_vars[i]->valueView();
  }

  for( MeshMaterialVariableRef::Enumerator i(this); i.hasNext(); ++i ){
    MeshMaterialVariableRef* ref = *i;
    ref->updateFromInternal();
  }

  //TODO: mettre a jour les references
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> Ref<IData>
ItemMaterialVariableBase<Traits>::
_internalCreateSaveDataRef(Integer nb_value)
{
  Ref<IData> data = m_global_variable->data()->cloneEmptyRef();
  auto* true_data = dynamic_cast<ValueDataType*>(data.get());
  ARCANE_CHECK_POINTER(true_data);
  true_data->_internal()->reserve(nb_value);
  return data;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_saveData(IMeshComponent* component,IData* data)
{
  if (m_p->space()==MatVarSpace::Environment && !component->isEnvironment())
    ARCANE_FATAL("Can not save data on material for environment only variable");
  Traits::saveData(component,data,m_views);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_restoreData(IMeshComponent* component,IData* data,Integer data_index,
             Int32ConstArrayView ids,bool allow_null_id)
{
  if (m_p->space()==MatVarSpace::Environment && !component->isEnvironment())
    ARCANE_FATAL("Can not restore data on material for environment only variable");

  auto* true_data = dynamic_cast<ValueDataType*>(data);
  ARCANE_CHECK_POINTER(true_data);
  auto values = true_data->view();

  PrivatePartType* global_var = this->_trueGlobalVariable();

  // Tableau pour initialiser les valeurs soit à zéro, soit avec
  // la valeur de la variable globale.
  UniqueContainerType tmp_values;
  if (component->materialMng()->isDataInitialisationWithZero()){
    Integer max_id = m_global_variable->itemFamily()->maxLocalId();
    Traits::resizeAndFillWithDefault(true_data,tmp_values,max_id);
  }
  else
    tmp_values = global_var->constValueView();

  if (allow_null_id){
    for( Integer i=0, n=ids.size(); i<n; ++i ){
      if (ids[i]!=NULL_ITEM_ID){
         Traits::setValue(tmp_values[ids[i]],values[data_index+i]);
      }
    }
  }
  else{
    for( Integer i=0, n=ids.size(); i<n; ++i ){
      Traits::setValue(tmp_values[ids[i]] , values[data_index+i] );
    }
  }

  ENUMERATE_COMPONENTCELL(icell,component){
    ComponentCell ec = *icell;
    setValue(ec._varIndex(),tmp_values[ec.globalCell().localId()]);
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> bool
ItemMaterialVariableBase<Traits>::
_isValidAndUsedAndGlobalUsed(PrivatePartType* partial_var)
{
  if (!partial_var)
    return false;
  if (!m_global_variable->isUsed() || !partial_var->isUsed())
    return false;
  return true;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_copyGlobalToPartial(Int32 var_index,Int32ConstArrayView local_ids,
                     Int32ConstArrayView indexes_in_multiple)
{
  PrivatePartType* partial_var = m_vars[var_index+1];
  if (!_isValidAndUsedAndGlobalUsed(partial_var))
    return;

  {
    // Redimensionne le tableau des valeurs multiples si besoin.
    ConstArrayView<MeshMaterialVariableIndexer*> indexers = m_p->materialMng()->variablesIndexer();
    Traits::resizeWithReserve(partial_var,indexers[var_index]->maxIndexInMultipleArray());
    m_views[var_index+1] = partial_var->valueView();
  }

  ContainerConstViewType global_view = m_vars[0]->constValueView();
  ContainerViewType partial_view = partial_var->valueView();

  Traits::copyTo(global_view,local_ids,partial_view,indexes_in_multiple);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_copyPartialToGlobal(Int32 var_index,Int32ConstArrayView local_ids,
                     Int32ConstArrayView indexes_in_multiple)
{
  PrivatePartType* partial_var = m_vars[var_index+1];
  if (!_isValidAndUsedAndGlobalUsed(partial_var))
    return;

  ContainerViewType global_view = m_vars[0]->valueView();
  ContainerConstViewType partial_view = partial_var->constValueView();

  Traits::copyTo(partial_view,indexes_in_multiple,global_view,local_ids);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_initializeNewItems(const ComponentItemListBuilder& list_builder)
{
  MeshMaterialVariableIndexer* indexer = list_builder.indexer();
  Integer var_index = indexer->index();
  PrivatePartType* partial_var = m_vars[var_index+1];
  if (!_isValidAndUsedAndGlobalUsed(partial_var))
    return;

  // Redimensionne le tableau des valeurs multiples si besoin.
  Traits::resizeWithReserve(partial_var,indexer->maxIndexInMultipleArray());
  m_views[var_index+1] = partial_var->valueView();

  bool init_with_zero = m_p->materialMng()->isDataInitialisationWithZero();

  ContainerConstViewType global_view = m_vars[0]->valueView();

  ConstArrayView<MatVarIndex> partial_matvar = list_builder.partialMatVarIndexes();

  Integer nb_partial = partial_matvar.size();

  // TODO: regarder s'il faut initialiser les mailles pure avec zéro.
  // En effet, normalement il n'y a pas de maille pure si on ajoute un matériau
  // (sauf lors de l'init).
  DataType zero = DataType();

  if (init_with_zero){
    for( Integer i=0; i<nb_partial; ++i )
      this->setFillValue(partial_matvar[i],zero);
  }
  else{
    Int32ConstArrayView partial_local_ids = list_builder.partialLocalIds();
    for( Integer i=0; i<nb_partial; ++i ){
      setValue(partial_matvar[i], global_view[partial_local_ids[i]]);
    }
  }
}


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
fillPartialValuesWithGlobalValues()
{
  fillPartialValuesWithSuperValues(LEVEL_ALLENVIRONMENT);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
fillPartialValuesWithSuperValues(Int32 level)
{
  IMeshMaterialMng* mm = m_p->materialMng();
  if (level==LEVEL_MATERIAL)
    _fillPartialValuesWithSuperValues(mm->materialsAsComponents());
  else if (level==LEVEL_ENVIRONMENT){
    _fillPartialValuesWithSuperValues(mm->environmentsAsComponents());
  }
  else if (level==LEVEL_ALLENVIRONMENT){
    _fillPartialValuesWithSuperValues(mm->environmentsAsComponents());
    _fillPartialValuesWithSuperValues(mm->materialsAsComponents());
  }
  else
    throw ArgumentException(A_FUNCINFO,String::format("Invalid level={0}",level));
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename Traits> void
ItemMaterialVariableBase<Traits>::
_fillPartialValuesWithSuperValues(MeshComponentList components)
{
  MatVarSpace s = this->space();
  ENUMERATE_COMPONENT(ic,components){
    IMeshComponent* c = *ic;
    if (!c->hasSpace(s))
      continue;
    ENUMERATE_COMPONENTCELL(iccell,c){
      ComponentCell c = (*iccell).superCell();
      setValue(iccell._varIndex(),value(c._varIndex()));
    }
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Récupère ou construit une variable.
 *
 * Récupère ou construit une variable de type \a VariableTrueType dont
 * les caractéristiques sont données dans \a v.
 */
template<typename VariableTrueType> IMeshMaterialVariable*
MeshMaterialVariableCommonStaticImpl<VariableTrueType>::
getReference(const MaterialVariableBuildInfo& v,MatVarSpace mvs)
{
  typedef typename VariableTrueType::PrivatePartType PrivatePartType;
  typedef typename VariableTrueType::VariableRefType VariableRefType;

  MeshHandle mesh_handle = v.meshHandle();
  if (mesh_handle.isNull())
    ARCANE_FATAL("No mesh handle for material variable");

  IMeshMaterialMng* mat_mng = v.materialMng();

  //TODO: regarder si verrou necessaire
  if (!mat_mng)
    mat_mng = IMeshMaterialMng::getReference(mesh_handle,true);

  if (!mat_mng)
    ARCANE_FATAL("No IMaterialMng for mesh");

  if (!v.itemFamilyName().null())
    ARCANE_FATAL("Can not declare material variable for specific family");

  if (!v.itemGroupName().null())
    ARCANE_FATAL("Can not declare partial material variable");

  // Regarde si l'option qui force la création des variables matériaux
  // même si on est une variable milieu est active.

  if (VariableTrueType::TraitsType::dimension()==0)
    if (mat_mng->isAllocateScalarEnvironmentVariableAsMaterial())
      mvs = MatVarSpace::MaterialAndEnvironment;

  VariableBuildInfo gvar_bi(v);

  {
    Mutex::ScopedLock sl(mat_mng->variableLock());

    //! Récupère (ou créé) la variable globale associée.
    VariableInfo gvar_vi = VariableRefType::_internalVariableInfo(gvar_bi);
    IVariable* g_var = PrivatePartType::getReference(gvar_bi,gvar_vi);

    PrivatePartType* true_ptr = dynamic_cast<PrivatePartType*>(g_var);

    // TODO: regarder s'il faut mettre aussi le nom du m_material_mng.
    // Si on le fait, cela pose un problème avec la variable globale
    // associée. Si on ne le fait pas, on ne peut à priori n'avoir
    // qu'un seul IMeshMaterialMng.
    IMeshMaterialVariable* mat_var = mat_mng->checkVariable(g_var);
    VariableTrueType* true_mat_var = 0;
    // \a mat_var est non nul si la variable associée existe déjà.
    if (mat_var)
      true_mat_var = dynamic_cast<VariableTrueType*>(mat_var);
    else{
      VariableRefType* var_ref = new VariableRefType(true_ptr);
      MaterialVariableBuildInfo mvbi(mat_mng,v);
      true_mat_var = new VariableTrueType(mvbi,true_ptr,var_ref,mvs);
      mat_mng->addVariable(true_mat_var);
      // Le gestionnaire est déjà créé, on peut allouer toutes les infos
      if (!mat_mng->variablesIndexer().empty())
        true_mat_var->buildFromManager(false);
    }
    ARCANE_CHECK_POINTER(true_mat_var);
    if (mvs!=true_mat_var->space())
      ARCANE_FATAL("Incoherent space for variable '{0}' wanted_space={1} existing_space={2}.\n"
                   " Check all instances of the variables are of the same space\n"
                   " (i.e. all variables are MaterialVariable or EnvironmentVariable)",
                   true_mat_var->name(),(int)mvs,(int)true_mat_var->space());
    // Incrémente le compteur de référence.
    // Il faut le faire ici et pas dans addVariableRef() car en multithreading
    // il est possible de créer plusieurs références sur la même variable en même
    // temps et de détruire une des références avant que le addVariableRef() de l'autre
    // référence ne soit appelé ce qui provoque la destruction de true_mat_var.
    ++true_mat_var->m_p->m_nb_reference;
    return true_mat_var;
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template<typename TrueType> MeshMaterialVariableFactoryRegisterer
MeshMaterialVariableCommonStaticImpl<TrueType>::
m_auto_registerer1(_autoCreate1,TrueType::BuilderType::_buildVarTypeInfo(MatVarSpace::Environment));

template<typename TrueType> MeshMaterialVariableFactoryRegisterer
MeshMaterialVariableCommonStaticImpl<TrueType>::
m_auto_registerer2(_autoCreate2,TrueType::BuilderType::_buildVarTypeInfo(MatVarSpace::MaterialAndEnvironment));

template<typename TrueType> IMeshMaterialVariable*
MeshMaterialVariableCommonStaticImpl<TrueType>::
_autoCreate1(const MaterialVariableBuildInfo& v)
{
  return getReference(v,MatVarSpace::Environment);
}

template<typename TrueType> IMeshMaterialVariable*
MeshMaterialVariableCommonStaticImpl<TrueType>::
_autoCreate2(const MaterialVariableBuildInfo& v)
{
  return getReference(v,MatVarSpace::MaterialAndEnvironment);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane::Materials

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/