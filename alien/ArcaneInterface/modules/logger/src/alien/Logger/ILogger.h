#ifndef ALIEN_ILOGGER_H
#define ALIEN_ILOGGER_H

#include <vector>
#include <alien/utils/Precomp.h>
#include <alien/expression/solver/ILinearSolver.h>

namespace Alien {

  enum class eStep
  {
    init = 0,
    solve = 1
  };

  struct SolverInfos
  {
    typedef std::vector<Real>::size_type size_type;
    std::vector<SolverStatus> m_stats;
    std::vector<Real> m_solve_time;
    Real m_init_time;
  };


  class ILogger
  {
  public:
    ILogger()
    {
      ;
    }
    
    virtual ~ILogger()
    {
      ;
    }
  
    virtual void log(String key, String value) = 0;
    
    virtual void start(eStep Step) = 0;
    virtual void stop(eStep Step) = 0;
    virtual void stop(eStep Step, const SolverStatus& stats) = 0;

    virtual String package() const = 0;
    virtual String maxIt() const = 0;
    virtual String tolerance() const = 0;
    virtual String solver() const = 0;
    virtual String precond() const = 0;
    virtual const SolverInfos& solverInfos() const = 0;
    virtual void printValues() const = 0;
    virtual void report(String file = "") const = 0;
  };
};

#endif
