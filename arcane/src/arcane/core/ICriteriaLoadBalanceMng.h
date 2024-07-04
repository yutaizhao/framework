﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2024 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* ICriteriaLoadBalanceMng.h                                   (C) 2000-2024 */
/*                                                                           */
/* Interface pour un gestionnaire des critères d'équilibre de charge des     */
/* maillages.                                                                */
/*---------------------------------------------------------------------------*/
#ifndef ARCANE_CORE_ICRITERIALOADBALANCEMNG_H
#define ARCANE_CORE_ICRITERIALOADBALANCEMNG_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/core/ArcaneTypes.h"
#include "arcane/core/VariableTypes.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Interface de classe permettant d'ajouter des critères pour ajuster
 *        l'équilibre de charge.
 */
class ICriteriaLoadBalanceMng
{
 public:

  virtual ~ICriteriaLoadBalanceMng() = default; //!< Libère les ressources.

 public:

  /*!
   * \brief Méthode permettant d'ajouter un critère pour chaque maille.
   *
   * \param count Une variable aux mailles avec un poids par maille.
   */
  virtual void addCriterion(VariableCellInt32& count) =0;

  /*!
   * \brief Méthode permettant d'ajouter un critère pour chaque maille.
   *
   * \param count Une variable aux mailles avec un poids par maille.
   */
  virtual void addCriterion(VariableCellReal& count) =0;

  // TODO Comprendre comment fonctionne PartitionerMemoryInfo
  /*!
   * \brief Méthode permettant d'ajouter un critère pour chaque maille.
   *
   * \param count Une variable aux mailles avec un poids par maille.
   * \param entity Le type d'entité lié à ce critère.
   */
  virtual void addMass(VariableCellInt32& count, const String& entity) = 0;

  /*!
   * \brief Méthode permettant d'ajouter un critère pour chaque face.
   *
   * \param count Une variable aux faces avec un poids par face.
   * \param entity Le type d'entité lié à ce critère.
   */
  virtual void addCommCost(VariableFaceInt32& count, const String& entity) = 0;

  /*!
   * \brief Méthode permettant d'effacer les critères déjà ajoutés.
   */
  virtual void reset() =0;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
