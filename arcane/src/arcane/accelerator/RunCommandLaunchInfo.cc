﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2021 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* RunCommandLaunchInfo.cc                                     (C) 2000-2021 */
/*                                                                           */
/* Informations pour l'exécution d'une 'RunCommand'.                         */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/accelerator/RunQueueInternal.h"
#include "arcane/accelerator/RunQueue.h"
#include "arcane/accelerator/IRunQueueStream.h"

#include "arcane/utils/CheckedConvert.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::Accelerator::impl
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

RunCommandLaunchInfo::
RunCommandLaunchInfo(RunCommand& command)
: m_command(command)
{
  _begin();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

RunCommandLaunchInfo::
~RunCommandLaunchInfo() ARCANE_NOEXCEPT_FALSE
{
  // Normalement ce test est toujours faux sauf s'il y a eu une exception
  // pendant le lancement du noyau de calcul.
  if (!m_is_notify_end_kernel_done)
    m_queue_stream->notifyEndKernel(m_command);
  _checkHasExecBegun();
  m_command.resetInfos();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void RunCommandLaunchInfo::
_begin()
{
  RunQueue& queue = m_command._internalQueue();
  m_exec_policy = queue.executionPolicy();
  m_queue_stream = queue._internalStream();
  m_runtime = queue._internalRuntime();
  m_queue_stream->notifyBeginKernel(m_command);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void RunCommandLaunchInfo::
endExecute()
{
  _checkHasExecBegun();
  m_is_notify_end_kernel_done = true;
  m_queue_stream->notifyEndKernel(m_command);
  RunQueue& queue = m_command._internalQueue();
  if (!queue.isAsync())
    m_queue_stream->barrier();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void RunCommandLaunchInfo::
_checkHasExecBegun()
{
  // Envoie un fatal si aucune exécution n'a eu lieu (ce qui
  // signifie que le runtime demandé n'est pas disponible)
  if (!m_has_exec_begun)
    ARCANE_FATAL("No runtime available for execution policy {0}",(int)m_exec_policy);
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

void* RunCommandLaunchInfo::
_internalStreamImpl()
{
  return m_queue_stream->_internalImpl();
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

auto RunCommandLaunchInfo::
computeThreadBlockInfo(Int64 full_size) const -> ThreadBlockInfo
{
  int threads_per_block = 256;
  Int64 big_b = (full_size + threads_per_block - 1) / threads_per_block;
  int blocks_per_grid = CheckedConvert::toInt32(big_b);
  return { blocks_per_grid, threads_per_block };
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // End namespace Arcane::Accelerator

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/