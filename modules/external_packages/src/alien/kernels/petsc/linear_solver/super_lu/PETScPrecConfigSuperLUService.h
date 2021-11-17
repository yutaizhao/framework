/* Author : havep at Mon Jun 30 17:55:25 2008
 * Generated by createNew
 */

#ifndef PETSCPRECCONFIGSUPERLUSERVICE_H
#define PETSCPRECCONFIGSUPERLUSERVICE_H

#include <alien/kernels/petsc/PETScPrecomp.h>
#include <alien/AlienExternalPackagesPrecomp.h>

#include <alien/utils/parameter_manager/BaseParameterManager.h>

#include <alien/kernels/petsc/linear_solver/IPETScPC.h>
#include <alien/kernels/petsc/linear_solver/IPETScKSP.h>
#include <alien/kernels/petsc/linear_solver/PETScConfig.h>

/* Pour debugger le ILU, utiliser l'option:
 * <cmd-line-param>-mat_superlu_printstat 1 </cmd-line-param>
 */

#include "petscversion.h"

/*---------------------------------------------------------------------------*/
#if ((PETSC_VERSION_MAJOR == 3 && PETSC_VERSION_MINOR >= 3) || (PETSC_VERSION_MAJOR > 3))
/*---------------------------------------------------------------------------*/

#include <ALIEN/axl/PETScPrecConfigSuperLU_axl.h>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
namespace Alien {

class ALIEN_EXTERNAL_PACKAGES_EXPORT PETScPrecConfigSuperLUService
    : public ArcanePETScPrecConfigSuperLUObject,
      public PETScConfig
{
 public:
/** Constructeur de la classe */
#ifdef ALIEN_USE_ARCANE
  PETScPrecConfigSuperLUService(const Arcane::ServiceBuildInfo& sbi);
#endif

  PETScPrecConfigSuperLUService(Arccore::MessagePassing::IMessagePassingMng* parallel_mng,
      std::shared_ptr<IOptionsPETScPrecConfigSuperLU> options);

  /** Destructeur de la classe */
  virtual ~PETScPrecConfigSuperLUService() {}

 public:
  //! Initialisation
  void configure(PC& pc, const ISpace& space, const MatrixDistribution& distribution);

  //! Check need of KSPSetUp before calling this PC configure
  virtual bool needPrematureKSPSetUp() const { return true; }
};

/*---------------------------------------------------------------------------*/

ARCANE_REGISTER_SERVICE_PETSCPRECCONFIGSUPERLU(SuperLU, PETScPrecConfigSuperLUService);

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
} // namespace Alien
/*---------------------------------------------------------------------------*/
#endif /* PETSC_VERSION */
/*---------------------------------------------------------------------------*/
#endif // PETSCPRECCONFIGSUPERLUSERVICE_H
