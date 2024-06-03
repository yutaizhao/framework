#include "Logger.h"
#include <fstream>
#include <cstdlib>



namespace Alien {

  Logger::
  Logger(Arcane::IParallelMng* parallelMng) :
  m_parallel_mng(parallelMng)
  {
    m_is_master=m_parallel_mng->commRank()==0;
  }

  Logger::
  ~Logger()
  {
    ;
  }

  void
  Logger::
  log(String key, String value)
  {
    m_values[key].push_back(value);
  }

  void
  Logger::
  start(eStep step)
  {
    m_time[step].push_back(std::chrono::steady_clock::now());
  }

  void
  Logger::
  stop(eStep step)
  {
    auto stop = std::chrono::steady_clock::now();
    m_solver_infos.m_init_time = (std::chrono::duration_cast<std::chrono::microseconds>(stop - m_time[step].back()).count())/1000000.0;
    m_solver_infos.m_init_time = m_parallel_mng->reduce(Arcane::Parallel::ReduceMax, m_solver_infos.m_init_time);
  }

  void
  Logger::
  stop(eStep step, const SolverStatus& stat)
  {
    auto stop = std::chrono::steady_clock::now();
    Real time = (std::chrono::duration_cast<std::chrono::microseconds>(stop - m_time[step].back()).count())/1000000.0;
    time = m_parallel_mng->reduce(Arcane::Parallel::ReduceMax, time);
    SolverStatus status;
    status.succeeded = stat.succeeded;
    status.residual = stat.residual;
    status.iteration_count = stat.iteration_count;
    status.error = stat.error;
    m_solver_infos.m_stats.push_back(status);
    m_solver_infos.m_solve_time.push_back(time);
  }

  String
  Logger::
  package() const
  {
    auto it = m_values.find("package");
    if(it != m_values.end())
      return it->second.back();
    return String();
  }

  String 
  Logger::
  maxIt() const
  {
    auto it = m_values.find("max-it");
    if(it != m_values.end())
      return it->second.back();
    return String();
  }

  String
  Logger::
  tolerance() const
  {
    auto it = m_values.find("tol");
    if(it != m_values.end())
      return it->second.back();
    return String();
  }

  String
  Logger::
  solver() const
  {
    auto it = m_values.find("solver");
    if(it != m_values.end())
      return it->second.back();
    return String();
  }

  String 
  Logger::
  precond() const
  {
    auto it = m_values.find("precond");
    if(it != m_values.end())
      return it->second.back();
    return String();
  }

  const SolverInfos& 
  Logger::
  solverInfos() const
  {
    return m_solver_infos;
  }

  void
  Logger::
  printValues() const
  {
    if(m_is_master)
    {
      std::cout << "Package: " << m_values.at("package").back() << "\n";
      std::cout << "Max iteration: " << m_values.at("max-it").back() << "\n";
      std::cout << "Tolerance: " << m_values.at("tol").back() << "\n";
      std::cout << "Solver: " << m_values.at("solver").back() << "\n";
      std::cout << "Precond: " << m_values.at("precond").back() << "\n";
      std::cout << "Time for init: " << m_solver_infos.m_init_time << "\n";
      for(SolverInfos::size_type i=0;i<m_solver_infos.m_stats.size(); ++i)
      {
	std::cout << "Call #" << i << ", success: " << m_solver_infos.m_stats[i].succeeded << ", error: " << m_solver_infos.m_stats[i].error << ", residual: " << m_solver_infos.m_stats[i].residual << ", iteration_count: " << m_solver_infos.m_stats[i].iteration_count << ", time: " << m_solver_infos.m_solve_time[i] << "\n";
      }
    }
  }

  void
  Logger::
  report(String file) const 
  {
    if(m_is_master)
    {
      if(m_values.empty())
	return;
      String filename;
      if(!file.empty())
	filename = file;
      else
	filename = String(std::getenv("alien_solver_filename"));
      if (filename.empty())
	filename = "alienSolverResult.txt";
      std::ofstream myfile(filename.localstr());
      if (myfile.is_open())
      {
	myfile << "Package: " << m_values.at("package").back() << "\n";
	myfile << "Max iteration: " << m_values.at("max-it").back() << "\n";
	myfile << "Tolerance: " << m_values.at("tol").back() << "\n";
	myfile << "Solver: " << m_values.at("solver").back() << "\n";
	myfile << "Precond: " << m_values.at("precond").back() << "\n";
	myfile << "Time for init: " << m_solver_infos.m_init_time << "\n";
	for(SolverInfos::size_type i=0;i<m_solver_infos.m_stats.size(); ++i)
	{
	  myfile << "Call #" << i << ", success: " << m_solver_infos.m_stats[i].succeeded << ", error: " << m_solver_infos.m_stats[i].error << ", residual: " << m_solver_infos.m_stats[i].residual << ", iteration_count: " << m_solver_infos.m_stats[i].iteration_count << ", time: " << m_solver_infos.m_solve_time[i] << "\n";
	}
	myfile.close();
      }
      else std::cout << "Unable to open file";
    }
  }

  std::ostream& operator<<(std::ostream& os, eStep step)
  {
    switch(step)
    {
    case eStep::init:
      os << "Initialisation";
      break;
    case eStep::solve:
      os << "Solve";
      break;
    default:
      os << "Unknown step";
    }
    return os;
  }
};
