﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2022 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* Observable.cc                                               (C) 2000-2021 */
/*                                                                           */
/* Observateur.                                                              */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/Observable.h"
#include "arcane/utils/Observer.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

Observable::
~Observable()
{
  if (arcaneIsCheck()){
    if (!m_observers.empty())
      cout << "** WARNING: Observable p=" << this
           << " is destroyed but has n="
           << m_observers.size() << " observer(s) attached\n";
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
attachObserver(IObserver* obs)
{
  // Vérifie que l'observeur n'est pas dans la liste.
  if (m_observers.contains(obs))
    return;
  obs->attachToObservable(this);
  m_observers.add(obs);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
detachObserver(IObserver* obs)
{
  //std::cout << "DETACH OB this=" << this << " o=" << obs
  //          << " destroyed=" << m_is_destroyed << '\n';
  if (m_is_destroyed)
    return;
  for( Integer i=0, n=m_observers.size(); i<n; ++i ){
    if (m_observers[i]==obs){
      m_observers.remove(i);
      return;
    }
  }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
notifyAllObservers()
{
  if (m_observers.empty())
    return;
  for( Integer i=0, n=m_observers.size(); i<n; ++i )
    m_observers[i]->observerUpdate(this);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

bool Observable::
hasObservers() const
{
  return (!m_observers.empty());
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

bool Observable::
isDestroyed() const
{
  return m_is_destroyed;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
destroy()
{
  if (m_is_destroyed)
    return;
  m_is_destroyed = true;
  detachAllObservers();
  m_observers.clear();
  delete this;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
_detachAllObservers()
{
  //std::cout << "DESTROY this=" << this << '\n';
  for( Integer i=0, n=m_observers.size(); i<n; ++i ){
    IObserver* o = m_observers[i];
    //std::cout << "DETACH o=" << o << '\n';
    o->detach();
  }
  m_observers.clear();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void Observable::
detachAllObservers()
{
  _detachAllObservers();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

IObservable* IObservable::
createDefault()
{
  return new Observable();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

AutoDetachObservable::
~AutoDetachObservable()
{
  _detachAllObservers();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
