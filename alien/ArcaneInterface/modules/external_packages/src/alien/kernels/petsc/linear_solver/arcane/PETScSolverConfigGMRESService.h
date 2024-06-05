/* Author : havep at Fri Jun 27 21:10:51 2008
 * Generated by createNew
 */

#ifndef PETSCSOLVERCONFIGGMRESSERVICE_H
#define PETSCSOLVERCONFIGGMRESSERVICE_H

#include <alien/kernels/petsc/PETScPrecomp.h>
#include <alien/AlienExternalPackagesPrecomp.h>

#include <alien/kernels/petsc/linear_solver/IPETScKSP.h>
#include <alien/kernels/petsc/linear_solver/IPETScPC.h>
#include <alien/kernels/petsc/linear_solver/PETScConfig.h>
#include <alien/kernels/petsc/linear_solver/PETScInitType.h>

#include <ALIEN/axl/PETScSolverConfigGMRES_axl.h>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

namespace Alien {

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

class ALIEN_EXTERNAL_PACKAGES_EXPORT PETScSolverConfigGMRESService
    : public ArcanePETScSolverConfigGMRESObject,
      public PETScConfig
{
 public:
/** Constructeur de la classe */
#ifdef ALIEN_USE_ARCANE
  PETScSolverConfigGMRESService(const Arcane::ServiceBuildInfo& sbi);
#endif

  PETScSolverConfigGMRESService(Arccore::MessagePassing::IMessagePassingMng* parallel_mng,
      std::shared_ptr<IOptionsPETScSolverConfigGMRES> options);

  /** Destructeur de la classe */
  virtual ~PETScSolverConfigGMRESService() {}

 public:
  //! Initialisation
  void configure(KSP& ksp, const ISpace& space, const MatrixDistribution& distribution, ILogger* logger);
};

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

} // namespace Alien

#endif // PETSCSOLVERCONFIGGMRESSERVICE_H
