﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2022 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* VariableCollection.cc                                       (C) 2000-2019 */
/*                                                                           */
/* Classe de base d'un élément du maillage.                                  */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/VariableCollection.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableCollection::
VariableCollection()
: m_p(new Impl())
{
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableCollection::
VariableCollection(const Enumerator& rhs)
: m_p(new Impl())
{
  _values().copy(rhs.m_collection);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void VariableCollection::
sortByName(bool is_ascendent)
{
  Array<IVariable*>& v = _values();
  auto sort_func = [](IVariable* v1,IVariable* v2){
    return v1->fullName() < v2->fullName();
  };

  if (is_ascendent)
    std::sort(v.begin(),v.end(),sort_func);
  else
    std::sort(v.rbegin(),v.rend(),sort_func);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

VariableCollectionEnumerator::
VariableCollectionEnumerator(const VariableCollection& col)
: m_index(-1)
, m_collection(col._values())
{
  m_count = m_collection.size();
}
  
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/