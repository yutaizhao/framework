﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2022 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* NumArray.h                                                  (C) 2000-2022 */
/*                                                                           */
/* Tableaux multi-dimensionnel pour les types numériques.                    */
/*---------------------------------------------------------------------------*/
#ifndef ARCANE_UTILS_NUMARRAY_H
#define ARCANE_UTILS_NUMARRAY_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/Array.h"
#include "arcane/utils/PlatformUtils.h"
#include "arcane/utils/MemoryRessource.h"
#include "arcane/utils/MDSpan.h"

#include "arccore/base/Span2.h"

/*
 * ATTENTION:
 *
 * Toutes les classes de ce fichier sont expérimentales et l'API n'est pas
 * figée. A NE PAS UTILISER EN DEHORS DE ARCANE.
 */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{

template <typename DataType, int Rank, typename Extents, typename LayoutPolicy>
class NumArrayIntermediate;

}

namespace Arcane::impl
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Implémentation commune à pour NumArray.
 */
class ARCANE_UTILS_EXPORT NumArrayBaseCommon
{
 protected:

  static IMemoryAllocator* _getDefaultAllocator();
  static IMemoryAllocator* _getDefaultAllocator(eMemoryRessource r);
  static void _checkHost(eMemoryRessource r);
  static void _copy(Span<const std::byte> from, eMemoryRessource from_mem,
                    Span<std::byte> to, eMemoryRessource to_mem);
};

// Wrapper de Arccore::Array pour la classe NumArray
template <typename DataType>
class NumArrayContainer
: private Arccore::Array<DataType>
{
 private:

  using BaseClass = Arccore::Array<DataType>;
  using ThatClass = NumArrayContainer<DataType>;

 public:

  using BaseClass::capacity;
  using BaseClass::fill;

 public:

  explicit NumArrayContainer(IMemoryAllocator* a)
  {
    this->_initFromAllocator(a, 0);
  }
  NumArrayContainer(const ThatClass& rhs)
  : BaseClass()
  {
    this->_initFromSpan(rhs.to1DSpan());
  }
  NumArrayContainer(ThatClass&& rhs)
  : BaseClass(std::move(rhs))
  {
  }
  ThatClass& operator=(const ThatClass& rhs)
  {
    if (this != &rhs) {
      BaseClass::_copy(rhs.data());
    }
    return (*this);
  }
  ThatClass& operator=(ThatClass&& rhs)
  {
    this->_move(rhs);
    return (*this);
  }

 public:

  void resize(Int64 new_size) { BaseClass::_resizeNoInit(new_size); }
  Span<DataType> to1DSpan() { return BaseClass::span(); }
  Span<const DataType> to1DSpan() const { return BaseClass::constSpan(); }
  Span<std::byte> bytes() { return asWritableBytes(BaseClass::span()); }
  Span<const std::byte> bytes() const { return asBytes(BaseClass::constSpan()); }
  void swap(NumArrayContainer<DataType>& rhs) { BaseClass::_swap(rhs); }
  void copy(Span<const DataType> rhs) { BaseClass::_copy(rhs.data()); }
  void copyInitializerList(std::initializer_list<DataType> alist)
  {
    Span<DataType> s = to1DSpan();
    Int64 s1 = s.size();
    Int32 index = 0;
    for (auto x : alist) {
      s[index] = x;
      ++index;
      // S'assure qu'on ne déborde pas
      if (index >= s1)
        break;
    }
  }
};

} // namespace Arcane::impl

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Classe de base des tableaux multi-dimensionnels pour les types
 * numériques sur accélérateur.
 *
 * \warning API en cours de définition.
 *
 * Il ne faut pas utiliser cette classe directement mais utiliser la classe NumArray.
 *
 * Cette classe contient un nombre minimal de méthodes. Notamment, l'accès aux
 * valeurs du tableau se fait normalement via des vues (MDSpanBase).
 * Afin de faciliter l'utilisation sur CPU, l'opérateur 'operator()'
 * permet de retourner la valeur en lecture d'un élément. Pour modifier un élément,
 * il faut utiliser la méthode s().
 */
template <typename DataType, typename Extents, typename LayoutPolicy>
class NumArrayBase
: public impl::NumArrayBaseCommon
{
 public:

  using ConstSpanType = MDSpan<const DataType, Extents, LayoutPolicy>;
  using SpanType = MDSpan<DataType, Extents, LayoutPolicy>;
  using ArrayWrapper = impl::NumArrayContainer<DataType>;
  using ArrayBoundsIndexType = typename SpanType::ArrayBoundsIndexType;
  using ThatClass = NumArrayBase<DataType, Extents, LayoutPolicy>;
  using ExtentsType = Extents;
  using DimsType = typename ExtentsType::DimsType;
  static constexpr int rank() { return Extents::rank(); }

 public:

  //! Nombre total d'éléments du tableau
  Int64 totalNbElement() const { return m_total_nb_element; }

  /*!
   * \brief Modifie la taille du tableau.
   *
   * Seules les dimensions dynamiques doivent être spécifiées.
   *
   * \warning Les valeurs actuelles ne sont pas conservées lors de cette opération.
   */
  void resize(const DimsType& dims)
  {
    m_span.m_extents = dims;
    _resize();
  }

 protected:

  NumArrayBase()
  : m_data(_getDefaultAllocator())
  {
    _resizeInit();
  }
  explicit NumArrayBase(eMemoryRessource r)
  : m_data(_getDefaultAllocator(r))
  , m_memory_ressource(r)
  {
    _resizeInit();
  }
  explicit NumArrayBase(const DimsType& extents)
  : m_data(_getDefaultAllocator())
  {
    resize(extents);
  }
  NumArrayBase(const DimsType& extents, eMemoryRessource r)
  : m_data(_getDefaultAllocator(r))
  , m_memory_ressource(r)
  {
    resize(extents);
  }

  NumArrayBase(const ThatClass&) = default;
  NumArrayBase(ThatClass&&) = default;
  ThatClass& operator=(ThatClass&&) = default;
  ThatClass& operator=(const ThatClass&) = default;

 private:

  void _resize()
  {
    m_total_nb_element = m_span.extents().totalNbElement();
    m_data.resize(m_total_nb_element);
    m_span.m_ptr = m_data.to1DSpan().data();
  }
  /*!
   * \brief Allocation éventuelle lors de l'initialisation.
   *
   * Il y a besoin de faire une allocation lors de l'initialisation
   * avec le constructeur par défaut dans le cas où toutes les
   * dimensions sont statiques.
   */
  void _resizeInit()
  {
    if constexpr (ExtentsType::nb_dynamic == 0) {
      resize(DimsType());
    }
  }

 public:

  void fill(const DataType& v) { m_data.fill(v); }
  static constexpr Int32 nbDimension() { return Extents::rank(); }
  ArrayExtents<Extents> extents() const { return m_span.extents(); }
  ArrayExtentsWithOffset<Extents, LayoutPolicy> extentsWithOffset() const
  {
    return m_span.extentsWithOffset();
  }

 public:

  SpanType span() { return m_span; }
  ConstSpanType span() const { return m_span.constSpan(); }
  ConstSpanType constSpan() const { return m_span.constSpan(); }

 public:

  Span<const DataType> to1DSpan() const { return m_span.to1DSpan(); }
  Span<DataType> to1DSpan() { return m_span.to1DSpan(); }
  void copy(ConstSpanType rhs)
  {
    _checkHost(m_memory_ressource);
    m_data.copy(rhs.to1DSpan());
  }
  void copy(const NumArrayBase<DataType, Extents, LayoutPolicy>& rhs)
  {
    this->resize(rhs.extents().dynamicExtents());
    _copy(asBytes(rhs.to1DSpan()), rhs.m_memory_ressource,
          asWritableBytes(to1DSpan()), m_memory_ressource);
  }
  const DataType& operator()(ArrayBoundsIndexType idx) const
  {
    return m_span(idx);
  }
  DataType& operator()(ArrayBoundsIndexType idx)
  {
    return m_span(idx);
  }
  DataType& s(ArrayBoundsIndexType idx)
  {
    return m_span(idx);
  }
  void swap(NumArrayBase<DataType, Extents>& rhs)
  {
    m_data.swap(rhs.m_data);
    std::swap(m_span, rhs.m_span);
    std::swap(m_total_nb_element, rhs.m_total_nb_element);
    std::swap(m_memory_ressource, rhs.m_memory_ressource);
  }
  Int64 capacity() const { return m_data.capacity(); }
  eMemoryRessource memoryRessource() const { return m_memory_ressource; }
  Span<std::byte> bytes() { return asWritableBytes(to1DSpan()); }
  Span<const std::byte> bytes() const { return asBytes(to1DSpan()); }

 public:

  //! \internal
  DataType* _internalData() { return m_span._internalData(); }

 protected:

  SpanType m_span;
  ArrayWrapper m_data;
  Int64 m_total_nb_element = 0;
  eMemoryRessource m_memory_ressource = eMemoryRessource::UnifiedMemory;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Spécialisation pour les tableaux à 1 dimension.
 *
 * Les tableaux à une dimension possèdent l'opérateur 'operator[]' pour
 * compatibilité avec les tableaux classiques du C++.
 */
template <typename DataType, typename ExtentType, typename LayoutPolicy>
class NumArrayIntermediate<DataType, 1, ExtentType, LayoutPolicy>
: public NumArrayBase<DataType, ExtentType, LayoutPolicy>
{
 public:

  using BaseClass = NumArrayBase<DataType, ExtentType, LayoutPolicy>;
  using DimsType = typename ExtentType::DimsType;
  using BaseClass::resize;
  using BaseClass::operator();
  using BaseClass::s;
  using ConstSpanType = MDSpan<const DataType, ExtentType, LayoutPolicy>;
  using SpanType = MDSpan<DataType, ExtentType, LayoutPolicy>;

 protected:

  using BaseClass::m_span;

 protected:

  //! Construit un tableau vide
  NumArrayIntermediate() = default;
  explicit NumArrayIntermediate(const DimsType& extents)
  : BaseClass(extents)
  {}
  NumArrayIntermediate(const DimsType& extents, eMemoryRessource r)
  : BaseClass(extents, r)
  {
  }
  explicit NumArrayIntermediate(eMemoryRessource r)
  : BaseClass(r)
  {}

 public:

  //! Valeur de la première dimension
  constexpr Int32 dim1Size() const { return m_span.extent0(); }

  //! Valeur de la première dimension
  constexpr Int32 extent0() const { return m_span.extent0(); }

 public:

  //! Valeur pour l'élément \a i
  DataType operator()(Int32 i) const { return m_span(i); }
  //! Positionne la valeur pour l'élément \a i
  DataType& operator()(Int32 i) { return m_span(i); }
  //! Positionne la valeur pour l'élément \a i
  DataType& s(Int32 i) { return m_span(i); }
  //! Récupère une référence pour l'élément \a i
  DataType& operator[](Int32 i) { return m_span(i); }
  //! Valeur pour l'élément \a i
  DataType operator[](Int32 i) const { return m_span(i); }

 public:

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename SubConstType = typename NumericTraitsT<X>::SubscriptConstType>
  SubConstType operator()(Int32 i, Int32 a) const { return m_span(i, a); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename SubType = typename NumericTraitsT<X>::SubscriptType>
  SubType operator()(Int32 i, Int32 a) { return m_span(i, a); }

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename Sub2ConstType = typename NumericTraitsT<X>::Subscript2ConstType>
  Sub2ConstType operator()(Int32 i, Int32 a, Int32 b) const { return m_span(i, a, b); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename Sub2Type = typename NumericTraitsT<X>::Subscript2Type>
  Sub2Type operator()(Int32 i, Int32 a, Int32 b) { return m_span(i, a, b); }

 public:

  constexpr operator SpanType() { return this->span(); }
  constexpr operator ConstSpanType() const { return this->constSpan(); }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Spécialisation pour les tableaux à 2 dimensions.
 */
template <typename DataType, typename ExtentType, typename LayoutPolicy>
class NumArrayIntermediate<DataType, 2, ExtentType, LayoutPolicy>
: public NumArrayBase<DataType, ExtentType, LayoutPolicy>
{
 public:

  using BaseClass = NumArrayBase<DataType, ExtentType, LayoutPolicy>;
  using DimsType = typename ExtentType::DimsType;
  using BaseClass::resize;
  using BaseClass::operator();
  using BaseClass::s;

 protected:

  using BaseClass::m_span;

 protected:

  //! Construit un tableau vide
  NumArrayIntermediate() = default;
  explicit NumArrayIntermediate(const DimsType& extents)
  : BaseClass(extents)
  {}
  NumArrayIntermediate(const DimsType& extents, eMemoryRessource r)
  : BaseClass(extents, r)
  {
  }
  explicit NumArrayIntermediate(eMemoryRessource r)
  : BaseClass(r)
  {}

 public:

  //! Valeur de la première dimension
  constexpr Int32 dim1Size() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 dim2Size() const { return m_span.extent1(); }

  //! Valeur de la première dimension
  constexpr Int32 extent0() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 extent1() const { return m_span.extent1(); }

 public:

  //! Valeur pour l'élément \a i,j
  DataType operator()(Int32 i, Int32 j) const
  {
    return m_span(i, j);
  }
  //! Positionne la valeur pour l'élément \a i,j
  DataType& operator()(Int32 i, Int32 j)
  {
    return m_span(i, j);
  }
  //! Positionne la valeur pour l'élément \a i,j
  DataType& s(Int32 i, Int32 j)
  {
    return m_span(i, j);
  }

 public:

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename SubConstType = typename NumericTraitsT<X>::SubscriptConstType>
  SubConstType operator()(Int32 i, Int32 j, Int32 a) const { return m_span(i, j, a); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename SubType = typename NumericTraitsT<X>::SubscriptType>
  SubType operator()(Int32 i, Int32 j, Int32 a) { return m_span(i, j, a); }

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename Sub2ConstType = typename NumericTraitsT<X>::Subscript2ConstType>
  Sub2ConstType operator()(Int32 i, Int32 j, Int32 a, Int32 b) const { return m_span(i, j, a, b); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename Sub2Type = typename NumericTraitsT<X>::Subscript2Type>
  Sub2Type operator()(Int32 i, Int32 j, Int32 a, Int32 b) { return m_span(i, j, a, b); }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Spécialisation pour les tableaux à 3 dimensions.
 */
template <typename DataType, typename ExtentType, typename LayoutPolicy>
class NumArrayIntermediate<DataType, 3, ExtentType, LayoutPolicy>
: public NumArrayBase<DataType, ExtentType, LayoutPolicy>
{
 public:

  using BaseClass = NumArrayBase<DataType, ExtentType, LayoutPolicy>;
  using DimsType = typename ExtentType::DimsType;
  using BaseClass::resize;
  using BaseClass::operator();
  using BaseClass::s;

 protected:

  using BaseClass::m_span;

 protected:

  //! Construit un tableau vide
  NumArrayIntermediate() = default;
  explicit NumArrayIntermediate(const DimsType& extents)
  : BaseClass(extents)
  {}
  NumArrayIntermediate(const DimsType& extents, eMemoryRessource r)
  : BaseClass(extents, r)
  {
  }
  explicit NumArrayIntermediate(eMemoryRessource r)
  : BaseClass(r)
  {}

 public:

  //! Valeur de la première dimension
  constexpr Int32 dim1Size() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 dim2Size() const { return m_span.extent1(); }
  //! Valeur de la troisième dimension
  constexpr Int32 dim3Size() const { return m_span.extent2(); }

  //! Valeur de la première dimension
  constexpr Int32 extent0() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 extent1() const { return m_span.extent1(); }
  //! Valeur de la troisième dimension
  constexpr Int32 extent2() const { return m_span.extent2(); }

 public:

  //! Valeur pour l'élément \a i,j,k
  DataType operator()(Int32 i, Int32 j, Int32 k) const
  {
    return m_span(i, j, k);
  }
  //! Positionne la valeur pour l'élément \a i,j,k
  DataType& operator()(Int32 i, Int32 j, Int32 k)
  {
    return m_span(i, j, k);
  }
  //! Positionne la valeur pour l'élément \a i,j,k
  DataType& s(Int32 i, Int32 j, Int32 k)
  {
    return m_span(i, j, k);
  }

 public:

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename SubConstType = typename NumericTraitsT<X>::SubscriptConstType>
  SubConstType operator()(Int32 i, Int32 j, Int32 k, Int32 a) const { return m_span(i, j, k, a); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename SubType = typename NumericTraitsT<X>::SubscriptType>
  SubType operator()(Int32 i, Int32 j, Int32 k, Int32 a) { return m_span(i, j, k, a); }

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename Sub2ConstType = typename NumericTraitsT<X>::Subscript2ConstType>
  Sub2ConstType operator()(Int32 i, Int32 j, Int32 k, Int32 a, Int32 b) const { return m_span(i, j, k, a, b); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename Sub2Type = typename NumericTraitsT<X>::Subscript2Type>
  Sub2Type operator()(Int32 i, Int32 j, Int32 k, Int32 a, Int32 b) { return m_span(i, j, k, a, b); }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Spécialisation pour les tableaux à 4 dimensions.
 */
template <typename DataType, typename Extents, typename LayoutPolicy>
class NumArrayIntermediate<DataType, 4, Extents, LayoutPolicy>
: public NumArrayBase<DataType, Extents, LayoutPolicy>
{
 public:

  using BaseClass = NumArrayBase<DataType, Extents, LayoutPolicy>;
  using DimsType = typename Extents::DimsType;
  using BaseClass::resize;
  using BaseClass::operator();
  using BaseClass::s;

 protected:

  using BaseClass::m_span;

 protected:

  //! Construit un tableau vide
  NumArrayIntermediate() = default;
  explicit NumArrayIntermediate(const DimsType& extents)
  : BaseClass(extents)
  {}
  NumArrayIntermediate(const DimsType& extents, eMemoryRessource r)
  : BaseClass(extents, r)
  {
  }
  explicit NumArrayIntermediate(eMemoryRessource r)
  : BaseClass(r)
  {}

 public:

  //! Valeur de la première dimension
  constexpr Int32 dim1Size() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 dim2Size() const { return m_span.extent1(); }
  //! Valeur de la troisième dimension
  constexpr Int32 dim3Size() const { return m_span.extent2(); }
  //! Valeur de la quatrième dimension
  constexpr Int32 dim4Size() const { return m_span.extent3(); }

  //! Valeur de la première dimension
  constexpr Int32 extent0() const { return m_span.extent0(); }
  //! Valeur de la deuxième dimension
  constexpr Int32 extent1() const { return m_span.extent1(); }
  //! Valeur de la troisième dimension
  constexpr Int32 extent2() const { return m_span.extent2(); }
  //! Valeur de la quatrième dimension
  constexpr Int32 extent3() const { return m_span.extent3(); }

 public:

  //! Valeur pour l'élément \a i,j,k,l
  DataType operator()(Int32 i, Int32 j, Int32 k, Int32 l) const
  {
    return m_span(i, j, k, l);
  }
  //! Positionne la valeur pour l'élément \a i,j,k,l
  DataType& operator()(Int32 i, Int32 j, Int32 k, Int32 l)
  {
    return m_span(i, j, k, l);
  }
  // TODO: rendre obsolète
  //! Positionne la valeur pour l'élément \a i,j,k,l
  DataType& s(Int32 i, Int32 j, Int32 k, Int32 l)
  {
    return m_span(i, j, k, l);
  }

 public:

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename SubConstType = typename NumericTraitsT<X>::SubscriptConstType>
  SubConstType operator()(Int32 i, Int32 j, Int32 k, Int32 l, Int32 a) const { return m_span(i, j, k, l, a); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename SubType = typename NumericTraitsT<X>::SubscriptType>
  SubType operator()(Int32 i, Int32 j, Int32 k, Int32 l, Int32 a) { return m_span(i, j, k, l, a); }

  //! Valeur pour l'élément \a i et la composante \a a
  template <typename X = DataType, typename Sub2ConstType = typename NumericTraitsT<X>::Subscript2ConstType>
  Sub2ConstType operator()(Int32 i, Int32 j, Int32 k, Int32 l, Int32 a, Int32 b) const { return m_span(i, j, k, l, a, b); }
  //! Valeur pour l'élément \a i et la composante \a [a][b]
  template <typename X = DataType, typename Sub2Type = typename NumericTraitsT<X>::Subscript2Type>
  Sub2Type operator()(Int32 i, Int32 j, Int32 k, Int32 l, Int32 a, Int32 b) { return m_span(i, j, k, l, a, b); }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Tableaux multi-dimensionnels pour les types numériques accessible
 * sur accélérateurs.
 *
 * \warning API en cours de définition.
 *
 * L'implémentation actuelle supporte des tableaux jusqu'à 4 dimensions. L'accès
 * aux éléments se fait via l'opérateur 'operator()'. Ces opérateurs d'accès spécifiques
 * dépendent du rang et sont fournis par les spécialisations de la classe NumArrayIntermediate.
 *
 * \warning Le redimensionnement via resize() ne conserve pas les valeurs existantes
 *
 * \warning Cette classe utilise par défaut un allocateur spécifique qui permet de
 * rendre accessible ces valeurs à la fois sur l'hôte (CPU) et l'accélérateur.
 * Néanmoins, il faut pour cela que le runtime associé à l'accélérateur ait été
 * initialisé (\ref arcanedoc_parallel_accelerator). C'est pourquoi il ne faut pas
 * utiliser de variables globales de cette classe ou d'une classe dérivée.
 *
 * \sa NumArrayIntermediate
 * \sa NumArrayBase
 */
template <typename DataType, typename Extents, typename LayoutPolicy>
class NumArray
: public NumArrayIntermediate<DataType, Extents::rank(), Extents, LayoutPolicy>
{
 public:

  using ExtentsType = Extents;
  using BaseClass = NumArrayIntermediate<DataType, Extents::rank(), Extents, LayoutPolicy>;
  using BaseClass::resize;
  using BaseClass::operator();
  using BaseClass::s;
  using ThatClass = NumArray<DataType, Extents, LayoutPolicy>;
  using DimsType = typename ExtentsType::DimsType;

 private:

  using BaseClass::m_span;

  //! Vrai s'il y a un seul rang et qu'il est dynamique
  template <typename X>
  using is_full_dynamic_and_rank1 = std::enable_if_t<X::is_full_dynamic() && (X::rank() == 1), int>;

  //! Vrai s'il y a deux rangs et qu'ils sont dynamiques
  template <typename X>
  using is_full_dynamic_and_rank2 = std::enable_if_t<X::is_full_dynamic() && (X::rank() == 2), int>;

 public:

  //! Construit un tableau vide
  NumArray() = default;

  //! Construit un tableau en spécifiant directement la liste des dimensions
  explicit NumArray(DimsType extents)
  : BaseClass(extents)
  {}

  //! Construit un tableau en spécifiant directement la liste des dimensions
  NumArray(const DimsType& extents, eMemoryRessource r)
  : BaseClass(extents, r)
  {
  }
  explicit NumArray(eMemoryRessource r)
  : BaseClass(r)
  {}

  //! Construit un tableau avec 4 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 4, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size,
           Int32 dim3_size, Int32 dim4_size)
  : BaseClass(DimsType(dim1_size, dim2_size, dim3_size, dim4_size))
  {
  }

  //! Construit un tableau avec 4 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 4, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size,
           Int32 dim3_size, Int32 dim4_size, eMemoryRessource r)
  : BaseClass(DimsType(dim1_size, dim2_size, dim3_size, dim4_size), r)
  {
  }

  //! Construit un tableau avec 3 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 3, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size, Int32 dim3_size)
  : BaseClass(DimsType(dim1_size, dim2_size, dim3_size))
  {
  }
  //! Construit un tableau avec 3 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 3, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size, Int32 dim3_size, eMemoryRessource r)
  : BaseClass(DimsType(dim1_size, dim2_size, dim3_size), r)
  {
  }

  //! Construit un tableau avec 2 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 2, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size)
  : BaseClass(DimsType(dim1_size, dim2_size))
  {
  }
  //! Construit un tableau avec 2 valeurs dynamiques
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 2, void>>
  NumArray(Int32 dim1_size, Int32 dim2_size, eMemoryRessource r)
  : BaseClass(DimsType(dim1_size, dim2_size), r)
  {
  }

  //! Construit un tableau avec 1 valeur dynamique
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 1, void>>
  explicit NumArray(Int32 dim1_size)
  : BaseClass(DimsType(dim1_size))
  {
  }
  //! Construit un tableau avec 1 valeur dynamique
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 1, void>>
  NumArray(Int32 dim1_size, eMemoryRessource r)
  : BaseClass(DimsType(dim1_size), r)
  {
  }

  /*!
   * \brief Construit un tableau à partir de valeurs prédéfinies (tableaux 2D dynamiques).
   *
   * Les valeurs sont rangées de manière contigues en mémoire donc
   * la liste \a alist doit avoir un layout qui correspond à celui de cette classe.
   */
  template <typename X = ExtentsType, typename = is_full_dynamic_and_rank2<X>>
  NumArray(Int32 dim1_size, Int32 dim2_size, std::initializer_list<DataType> alist)
  : NumArray(dim1_size, dim2_size)
  {
    this->m_data.copyInitializerList(alist);
  }

  //! Construit un tableau à partir de valeurs prédéfinies (uniquement tableaux 1D dynamiques)
  template <typename X = ExtentsType, typename = is_full_dynamic_and_rank1<X>>
  NumArray(Int32 dim1_size, std::initializer_list<DataType> alist)
  : NumArray(dim1_size)
  {
    this->m_data.copyInitializerList(alist);
  }

  //! Construit une instance à partir d'une vue (uniquement tableaux 1D dynamiques)
  template <typename X = ExtentsType, typename = is_full_dynamic_and_rank1<X>>
  NumArray(SmallSpan<const DataType> v)
  : NumArray(v.size())
  {
    this->m_data.copy(v);
  }

  //! Construit une instance à partir d'une vue (uniquement tableaux 1D dynamiques)
  template <typename X = ExtentsType, typename = is_full_dynamic_and_rank1<X>>
  NumArray(Span<const DataType> v)
  : NumArray(arcaneCheckArraySize(v.size()))
  {
    this->m_data.copy(v);
  }

 public:

  NumArray(const ThatClass&) = default;
  NumArray(ThatClass&&) = default;
  ThatClass& operator=(ThatClass&&) = default;
  ThatClass& operator=(const ThatClass&) = default;

 public:

  /*!
   * \brief Modifie la taille du tableau.
   * \warning Les valeurs actuelles ne sont pas conservées lors de cette opération
   * et les nouvelles valeurs ne sont pas initialisées.
   */
  //@{
  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 4, void>>
  void resize(Int32 dim1_size, Int32 dim2_size, Int32 dim3_size, Int32 dim4_size)
  {
    this->resize(DimsType(dim1_size, dim2_size, dim3_size, dim4_size));
  }

  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 3, void>>
  void resize(Int32 dim1_size, Int32 dim2_size, Int32 dim3_size)
  {
    this->resize(DimsType(dim1_size, dim2_size, dim3_size));
  }

  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 2, void>>
  void resize(Int32 dim1_size, Int32 dim2_size)
  {
    this->resize(DimsType(dim1_size, dim2_size));
  }

  template <typename X = ExtentsType, typename = std::enable_if_t<X::nb_dynamic == 1, void>>
  void resize(Int32 dim1_size)
  {
    this->resize(DimsType(dim1_size));
  }
  //@}
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
