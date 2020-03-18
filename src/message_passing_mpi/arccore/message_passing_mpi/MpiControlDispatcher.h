﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
/*---------------------------------------------------------------------------*/
/* MpiControlDispatcher.h                                      (C) 2000-2020 */
/*                                                                           */
/* Manage Control/Utility parallel messages for MPI.                         */
/*---------------------------------------------------------------------------*/
#ifndef ARCCORE_MESSAGEPASSINGMPI_MPICONTROLDISPATCHER_H
#define ARCCORE_MESSAGEPASSINGMPI_MPICONTROLDISPATCHER_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arccore/message_passing_mpi/MessagePassingMpiGlobal.h"
#include "arccore/message_passing/IControlDispatcher.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arccore::MessagePassing::Mpi
{
class MpiControlDispatcher
: public IControlDispatcher
{
 public:
  MpiControlDispatcher(IMessagePassingMng* parallel_mng, MpiAdapter* adapter);

 public:
  void waitAllRequests(ArrayView<Request> requests) override;
  void waitSomeRequests(ArrayView<Request> requests, ArrayView<bool> indexes,
                        bool is_non_blocking) override;
  IMessagePassingMng* commSplit(bool keep) override;
  void barrier() override;
  Request probe(PointToPointMessageInfo& message) override;

 private:
  IMessagePassingMng* m_parallel_mng;
  MpiAdapter* m_adapter;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // namespace Arccore::MessagePassing::Mpi

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif
