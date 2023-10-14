/* Author : havep at Wed Jul 18 15:00:05 2012
 * Generated by createNew
 */
#include "PETScInternal.h"

/*---------------------------------------------------------------------------*/

namespace Alien::PETScInternal {

/*---------------------------------------------------------------------------*/

VectorInternal::VectorInternal(const int local_size, const int local_offset,
    const int global_size, const bool parallel, MPI_Comm comm)
: m_offset(local_offset)
, m_parallel(parallel)
{
  int ierr = 0;
  if (m_parallel) { // Use parallel structures
    // -- B Vector --
    ierr += VecCreateMPI(comm, local_size, global_size, &m_internal);
  } else { // Use sequential structures
    // -- B Vector --
    ierr += VecCreateSeq(PETSC_COMM_SELF, local_size, &m_internal);
  }
  int low;
  ierr += VecGetOwnershipRange(m_internal, &low, nullptr);

  if (low != local_offset)
    throw Arccore::FatalErrorException(A_FUNCINFO, "Ill placed parallel vector");
}

/*---------------------------------------------------------------------------*/

VectorInternal::~VectorInternal()
{
#ifndef PETSC_DESTROY_NEW
  VecDestroy(m_internal);
#else /* PETSC_DESTROY_NEW */
  VecDestroy(&m_internal);
#endif /* PETSC_DESTROY_NEW */
}

/*---------------------------------------------------------------------------*/

} // namespace Alien::PETScInternal

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
