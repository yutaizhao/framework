﻿// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2023 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* Scan.h                                                      (C) 2000-2023 */
/*                                                                           */
/* Gestion des opérations de scan pour les accélérateurs.                    */
/*---------------------------------------------------------------------------*/
#ifndef ARCANE_ACCELERATOR_SCAN_H
#define ARCANE_ACCELERATOR_SCAN_H
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include "arcane/utils/ArrayView.h"
#include "arcane/utils/FatalErrorException.h"

#include "arcane/accelerator/AcceleratorGlobal.h"
#include "arcane/accelerator/core/RunQueue.h"
#include "arcane/accelerator/CommonUtils.h"

#if defined(ARCANE_COMPILING_HIP)
#include "arcane/accelerator/hip/HipAccelerator.h"
#include <rocprim/rocprim.hpp>
#endif
#if defined(ARCANE_COMPILING_CUDA)
#include "arcane/accelerator/cuda/CudaAccelerator.h"
#include <cub/cub.cuh>
#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Arcane::Accelerator::impl
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

// Opérateur de Scan pour les sommes
template <typename DataType>
class ScannerSumOperator
{
 public:

  constexpr ARCCORE_HOST_DEVICE DataType operator()(const DataType& a, const DataType& b) const
  {
    return a + b;
  }
  static DataType initialValue() { return {}; }
};

// Opérateur de Scan pour le minimum
template <typename DataType>
class ScannerMinOperator
{
 public:

  constexpr ARCCORE_HOST_DEVICE DataType operator()(const DataType& a, const DataType& b) const
  {
    return (a < b) ? a : b;
  }
  static DataType initialValue() { return std::numeric_limits<DataType>::max(); }
};

// Opérateur de Scan pour le maximum
template <typename DataType>
class ScannerMaxOperator
{
 public:

  constexpr ARCCORE_HOST_DEVICE DataType operator()(const DataType& a, const DataType& b) const
  {
    return (a < b) ? b : a;
  }
  static DataType initialValue() { return std::numeric_limits<DataType>::lowest(); }
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*!
 * \brief Classe pour effectuer un scan exlusif ou inclusif.
 *
 * \a DataType est le type de donnée.
 */
template <typename DataType, typename Operator, bool IsExclusive>
class GenericScanner
{
  // TODO: Utiliser une classe pour gérer le malloc pour gérer les exceptions
  // TODO: Faire le malloc sur le device associé à la queue.
  //       et aussi regarder si on peut utiliser mallocAsync().

 public:

  explicit GenericScanner(RunQueue* queue)
  : m_queue(queue)
  {}

 public:

  void apply(SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    const Int32 nb_item = input.size();
    if (output.size() != nb_item)
      ARCANE_FATAL("Sizes are not equals: input={0} output={1}", nb_item, output.size());
    [[maybe_unused]] const DataType* input_data = input.data();
    [[maybe_unused]] DataType* output_data = output.data();
    eExecutionPolicy exec_policy = eExecutionPolicy::Sequential;
    if (m_queue)
      exec_policy = m_queue->executionPolicy();
    Operator op;
    DataType init_value = op.initialValue();
    switch (exec_policy) {
    case eExecutionPolicy::CUDA:
#if defined(ARCANE_COMPILING_CUDA)
    {
      size_t temp_storage_size = 0;
      void* temp_storage = nullptr;
      cudaStream_t stream = impl::CudaUtils::toNativeStream(m_queue);
      // Premier appel pour connaitre la taille pour l'allocation
      if constexpr (IsExclusive)
        ARCANE_CHECK_CUDA(::cub::DeviceScan::ExclusiveScan(temp_storage, temp_storage_size,
                                                           input_data, output_data, op, init_value, nb_item, stream));
      else
        ARCANE_CHECK_CUDA(::cub::DeviceScan::InclusiveScan(temp_storage, temp_storage_size,
                                                           input_data, output_data, op, nb_item, stream));

      ARCANE_CHECK_CUDA(cudaMalloc(&temp_storage, temp_storage_size));
      if constexpr (IsExclusive)
        ARCANE_CHECK_CUDA(::cub::DeviceScan::ExclusiveScan(temp_storage, temp_storage_size,
                                                           input_data, output_data, op, init_value, nb_item, stream));
      else
        ARCANE_CHECK_CUDA(::cub::DeviceScan::InclusiveScan(temp_storage, temp_storage_size,
                                                           input_data, output_data, op, nb_item, stream));
      ARCANE_CHECK_CUDA(::cudaFree(temp_storage));
    } break;
#else
      ARCANE_FATAL_NO_CUDA_COMPILATION();
#endif
    case eExecutionPolicy::HIP:
#if defined(ARCANE_COMPILING_HIP)
    {
      size_t temp_storage_size = 0;
      void* temp_storage = nullptr;
      // Premier appel pour connaitre la taille pour l'allocation
      hipStream_t stream = impl::HipUtils::toNativeStream(m_queue);
      if constexpr (IsExclusive)
        ARCANE_CHECK_HIP(rocprim::exclusive_scan(temp_storage, temp_storage_size, input_data, output_data,
                                                 init_value, nb_item, op, stream));
      else
        ARCANE_CHECK_HIP(rocprim::inclusive_scan(temp_storage, temp_storage_size, input_data, output_data,
                                                 nb_item, op, stream));

      ARCANE_CHECK_HIP(hipMalloc(&temp_storage, temp_storage_size));

      if constexpr (IsExclusive)
        ARCANE_CHECK_HIP(rocprim::exclusive_scan(temp_storage, temp_storage_size, input_data, output_data,
                                                 init_value, nb_item, op, stream));
      else
        ARCANE_CHECK_HIP(rocprim::inclusive_scan(temp_storage, temp_storage_size, input_data, output_data,
                                                 nb_item, op, stream));

      ARCANE_CHECK_HIP(hipFree(temp_storage));
    }
#else
      ARCANE_FATAL_NO_HIP_COMPILATION();
#endif
    case eExecutionPolicy::Thread:
      // Pas encore implémenté en multi-thread
    case eExecutionPolicy::Sequential: {
      DataType sum = init_value;
      for (Int32 i = 0; i < nb_item; ++i) {
        if constexpr (IsExclusive) {
          output[i] = sum;
          sum = op(input[i], sum);
        }
        else {
          sum = op(input[i], sum);
          output[i] = sum;
        }
      }
    } break;
    default:
      ARCANE_FATAL("Invalid execution policy '{0}'", exec_policy);
    }
  }

 private:

  RunQueue* m_queue = nullptr;
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

}

namespace Arcane::Accelerator
{

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

template <typename DataType>
class Scanner
{
 public:

  void exclusiveSum(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerSumOperator<DataType>, true>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }
  void exclusiveMin(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerMinOperator<DataType>, true>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }
  void exclusiveMax(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerMaxOperator<DataType>, true>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }
  void inclusiveSum(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerSumOperator<DataType>, false>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }
  void inclusiveMin(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerMinOperator<DataType>, false>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }
  void inclusiveMax(RunQueue* queue, SmallSpan<const DataType> input, SmallSpan<DataType> output)
  {
    using ScannerType = impl::GenericScanner<DataType, impl::ScannerMaxOperator<DataType>, false>;
    ScannerType scanner(queue);
    scanner.apply(input, output);
  }

 private:
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // namespace Arcane::Accelerator

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/