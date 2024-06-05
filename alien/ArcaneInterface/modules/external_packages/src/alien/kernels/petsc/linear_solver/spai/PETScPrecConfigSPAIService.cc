/* Author : havep at Fri Jun 27 21:34:36 2008
 * Generated by createNew
 */

#include <alien/kernels/petsc/linear_solver/spai/PETScPrecConfigSPAIService.h>
#include <ALIEN/axl/PETScPrecConfigSPAI_StrongOptions.h>

#include <arccore/message_passing/IMessagePassingMng.h>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

// BEGIN_LINEARALGEBRA2SERVICE_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
namespace Alien {

/** Constructeur de la classe */
#ifdef ALIEN_USE_ARCANE
PETScPrecConfigSPAIService::PETScPrecConfigSPAIService(
    const Arcane::ServiceBuildInfo& sbi)
: ArcanePETScPrecConfigSPAIObject(sbi)
, PETScConfig(sbi.subDomain()->parallelMng()->isParallel())
{
  ;
}
#endif
PETScPrecConfigSPAIService::PETScPrecConfigSPAIService(
    Arccore::MessagePassing::IMessagePassingMng* parallel_mng,
    std::shared_ptr<IOptionsPETScPrecConfigSPAI> options)
: ArcanePETScPrecConfigSPAIObject(options)
, PETScConfig(parallel_mng->commSize() > 1)
{
}

void
PETScPrecConfigSPAIService::configure([[maybe_unused]] PC& pc,
                                      [[maybe_unused]] const ISpace& space,
                                      [[maybe_unused]] const MatrixDistribution& distribution, ILogger* logger)
{
  if(logger)
    logger->log("precond","spai");
  alien_fatal([&] { cout() << "configure SPAI not available need to be checked"; });
}

//  //! Initialisation
//  void configure(PC & pc, const IIndexManager * indexManager)
//  {
//    checkError("Set preconditioner",PCSetType(pc,PCSPAI));
//    double epsilon = options()->epsilon();
//    if (epsilon > 0 and epsilon < 1)
//      checkError("Set SPAI epsilon",PCSPAISetEpsilon(pc,epsilon));
//    else
//      traceMng()->fatal() << "SPAI epsilon must be in [0:1]";
//
//    double nonzero_max = options()->nonzeroMax();
//    if (nonzero_max >= 0)
//      checkError("Set SPAI epsilon",PCSPAISetMaxNew(pc,nonzero_max));
//    else
//      traceMng()->fatal() << "SPAI nonzero-max must be positive";
//  }
//
//
//  //! Check need of KSPSetUp before calling this PC configure

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

ARCANE_REGISTER_SERVICE_PETSCPRECCONFIGSPAI(SPAI, PETScPrecConfigSPAIService);

} // namespace Alien

REGISTER_STRONG_OPTIONS_PETSCPRECCONFIGSPAI();

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

// END_LINEARALGEBRA2SERVICE_NAMESPACE

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
