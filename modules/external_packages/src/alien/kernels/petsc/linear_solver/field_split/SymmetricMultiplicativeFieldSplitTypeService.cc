// -*- C++ -*-
/* Author : havep at Tue Aug 21 10:46:20 2012
 * Generated by createNew
 */

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include <alien/kernels/petsc/linear_solver/field_split/SymmetricMultiplicativeFieldSplitTypeService.h>

#include <ALIEN/axl/SymmetricMultiplicativeFieldSplitType_StrongOptions.h>

#include <arccore/message_passing/IMessagePassingMng.h>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

// using namespace Arcane;
namespace Alien {

#ifdef ALIEN_USE_ARCANE
SymmetricMultiplicativeFieldSplitTypeService::
    SymmetricMultiplicativeFieldSplitTypeService(const Arcane::ServiceBuildInfo& sbi)
: ArcaneSymmetricMultiplicativeFieldSplitTypeObject(sbi)
, PETScConfig(sbi.subDomain()->parallelMng()->isParallel())
{
}
#endif

SymmetricMultiplicativeFieldSplitTypeService::
    SymmetricMultiplicativeFieldSplitTypeService(
        Arccore::MessagePassing::IMessagePassingMng* parallel_mng,
        std::shared_ptr<IOptionsSymmetricMultiplicativeFieldSplitType> options)
: ArcaneSymmetricMultiplicativeFieldSplitTypeObject(options)
, PETScConfig(parallel_mng->commSize() > 1)
{
}

//! Configure FieldSplit type

Arccore::Integer
SymmetricMultiplicativeFieldSplitTypeService::configure(
    PC& pc, const Arccore::Integer nbField)
{
  alien_debug([&] {
    cout() << "configure PETSc symmetric multiplicative FlieldSplit preconditioner";
  });
  Arccore::Integer code = PCFieldSplitSetType(pc, PC_COMPOSITE_SYMMETRIC_MULTIPLICATIVE);
  return code;
}
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_REGISTER_SERVICE_SYMMETRICMULTIPLICATIVEFIELDSPLITTYPE(
    SymmetricMultiplicative, SymmetricMultiplicativeFieldSplitTypeService);
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // namespace Alien

REGISTER_STRONG_OPTIONS_SYMMETRICMULTIPLICATIVEFIELDSPLITTYPE();

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
