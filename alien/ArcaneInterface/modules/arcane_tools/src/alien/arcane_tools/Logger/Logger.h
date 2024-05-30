#ifndef ALIEN_LOGGER_H
#define ALIEN_LOGGER_H

#include <map>
#include <vector>
#include <chrono>
#include "ILogger.h"
#include "alien/AlienArcaneToolsPrecomp.h"
#include <alien/expression/solver/ILinearSolver.h>

namespace Alien {

class Logger : public ILogger
  {
  public:
    Logger(IParallelMng* parallelMng);
    
    virtual ~Logger();

    void log(String key, String value);

    void start(eStep Step);
    void stop(eStep Step);
    void stop(eStep Step, const SolverStatus& stats);

    void printValues() const;
    void report(String file = "") const;

    String package() const;
    String maxIt() const;
    String tolerance() const;
    String solver() const;
    String precond() const;
    const SolverInfos& solverInfos() const;
    
  private:
    std::map<String, std::vector<String> > m_values;
    std::map<eStep, std::vector<std::chrono::steady_clock::time_point> > m_time;
    IParallelMng* m_parallel_mng;
    bool m_is_master;
    SolverInfos m_solver_infos;
  };

 std::ostream& operator<<(std::ostream& os, eStep step);
};

#endif

