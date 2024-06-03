#include <arcane/IIOMng.h>
#include <arcane/ISubDomain.h>
#include <arcane/IRessourceMng.h>
#include <arcane/IXmlDocumentHolder.h>

#include "alien/Logger/ILogger.h"
#include "alien/Logger/Logger.h"
#include <alien/axl/SolverLogger_StrongOptions.h>
#include <alien/axl/SolverLogger_axl.h>

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

BEGIN_NAMESPACE(Alien)

using namespace Arcane;

class ALIEN_EXPORT SolverLogger
  : public ArcaneSolverLoggerObject
  , public ILogger
{
public:
  SolverLogger(const Arcane::ServiceBuildInfo & sbi);
  virtual ~SolverLogger();

  void log(String key, String value);
  void start(eStep Step);
  void stop(eStep Step);
  void stop(eStep Step, const SolverStatus& stats);

  String package() const;
  String maxIt() const;
  String tolerance() const;
  String solver() const;
  String precond() const;
  const SolverInfos& solverInfos() const;
  void printValues() const;
  void report(String file = "") const;
private:
  std::unique_ptr<ILogger> m_logger;
  Arcane::String m_out_filename;
  Arcane::IParallelMng* m_parallel_mng;
  bool m_is_master;
  String m_case_name;
  std::unique_ptr<Arcane::ICaseOptions> m_case_options;
};

SolverLogger::
SolverLogger(const ServiceBuildInfo & sbi)
  : ArcaneSolverLoggerObject(sbi)
  , m_logger(new Logger(sbi.subDomain()->parallelMng()))
  , m_out_filename("")
  , m_parallel_mng(sbi.subDomain()->parallelMng())
  , m_case_options(sbi.caseOptions())
{
  m_is_master = m_parallel_mng->commRank()==0;
  m_case_name = sbi.subDomain()->caseFullFileName();
}

SolverLogger::
~SolverLogger()
{
  ;
}

void
SolverLogger::
log(String key, String value)
{
  m_logger->log(key,value);
}

void
SolverLogger::
start(eStep Step)
{
  m_logger->start(Step);
}

void
SolverLogger::
stop(eStep Step)
{
  m_logger->stop(Step);
}

void
SolverLogger::
stop(eStep Step, const SolverStatus& stats)
{
  m_logger->stop(Step, stats);
}

String
SolverLogger::
package() const
{
  return m_logger->package();
}

String
SolverLogger::
maxIt() const
{
  return m_logger->maxIt();
}

String
SolverLogger::
tolerance() const
{
  return m_logger->tolerance();
}

String
SolverLogger::
solver() const
{
  return m_logger->solver();
}
  
String
SolverLogger::
precond() const
{
  return m_logger->precond();
}

const SolverInfos&
SolverLogger::
solverInfos() const
{
  return m_logger->solverInfos();
}

void
SolverLogger::
printValues() const
{
  m_logger->printValues();
}

void
SolverLogger::
report(String file) const
{
  if(m_is_master)
  {
    std::unique_ptr<Arcane::IXmlDocumentHolder> xml_doc(serviceParent()->ressourceMng()->createXmlDocument());
    XmlNode out_doc = xml_doc->documentNode();
    XmlElement root(out_doc,"case");
    XmlElement xml_name(root,"input-file", m_case_name);
    XmlElement xml_numproc(root,"nb-proc", String::format("{0}",m_parallel_mng->commSize()));
    XmlElement xml_solver(root, "solver");
    XmlElement xml_solver_name(xml_solver, "name", m_case_options->configList()->parentElement().name());
    XmlElement xml_package(xml_solver, "package", m_logger->package());
    XmlElement xml_max_it(xml_solver, "max-it", m_logger->maxIt());
    XmlElement xml_tol(xml_solver, "tol", m_logger->tolerance());
    XmlElement xml_solver_algo(xml_solver,"solver-algo", m_logger->solver());
    XmlElement xml_precond_algo(xml_solver,"precond-algo", m_logger->precond());
    const SolverInfos& solver_infos = m_logger->solverInfos();
    XmlElement xml_init_time(xml_solver, "initialisation-time", String::format("{0}",solver_infos.m_init_time));
    int numberOfCalls = 0;
    int success = 1;
    int error = 0;
    int nbIteration = 0;
    double solveTime = 0;
    for(SolverInfos::size_type i=0;i<solver_infos.m_stats.size(); ++i)
    {
      ++numberOfCalls;
      success = success && solver_infos.m_stats[i].succeeded;
      error = solver_infos.m_stats[i].error;
      nbIteration += solver_infos.m_stats[i].iteration_count;
      solveTime += solver_infos.m_solve_time[i];
    }
    XmlElement xml_solve(xml_solver,"solve");
    XmlElement xml_call(xml_solve,"call", String::format("{0}",numberOfCalls));
    XmlElement xml_success(xml_solve,"success", String::format("{0}",success));
    XmlElement xml_error_code(xml_solve,"error", String::format("{0}",error));
    XmlElement xml_num_it(xml_solve,"iterations", String::format("{0}",nbIteration));
    XmlElement xml_time(xml_solve,"elapsed-time", String::format("{0}",solveTime));
    XmlElement xml_total_time(xml_solver, "total-time", String::format("{0}",solver_infos.m_init_time + solveTime));
    m_parallel_mng->ioMng()->writeXmlFile(xml_doc.get(),options()->outFilename(),true);
  }
}

/*---------------------------------------------------------------------------*/

ARCANE_REGISTER_SERVICE_SOLVERLOGGER(SolverLogger,SolverLogger);

END_NAMESPACE

REGISTER_STRONG_OPTIONS_SOLVERLOGGER();
