﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
/*---------------------------------------------------------------------------*/
/* IControlDispatcher.h                                        (C) 2000-2020 */
/*                                                                           */
/* Manage Control/Utility parallel messages.                                 */
/*---------------------------------------------------------------------------*/
#ifndef ARCCORE_MESSAGEPASSING_ICONTROLDISPATCHER_H
#define ARCCORE_MESSAGEPASSING_ICONTROLDISPATCHER_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arccore/message_passing/MessagePassingGlobal.h"
#include "arccore/collections/CollectionsGlobal.h"
#include "arccore/base/BaseTypes.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arccore::MessagePassing
{
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \internal
 * \brief Manage control streams for parallel messages.
 */
class IControlDispatcher
{
 public:
  virtual ~IControlDispatcher() = default;

 public:
  virtual void waitAllRequests(ArrayView<Request> requests) =0;

  virtual void waitSomeRequests(ArrayView<Request> requests,
                                ArrayView<bool> indexes, bool is_non_blocking) =0;

  virtual IMessagePassingMng* commSplit(bool keep) =0;

  virtual void barrier() =0;

  virtual Request probe(PointToPointMessageInfo& message) =0;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arccore::MessagePassing

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
