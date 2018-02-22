#include <mc_tasks/CoMTask.h>

#include <mc_tasks/MetaTaskLoader.h>

namespace mc_tasks
{

CoMTask::CoMTask(const mc_rbdyn::Robots & robots, unsigned int robotIndex,
                 double stiffness, double weight)
: TrajectoryTaskGeneric<tasks::qp::CoMTask>(robots, robotIndex, stiffness, weight),
  robot_index_(robotIndex),
  cur_com_(Eigen::Vector3d::Zero())
{
  const mc_rbdyn::Robot & robot = robots.robot(robotIndex);

  cur_com_ = rbd::computeCoM(robot.mb(), robot.mbc());

  finalize(robots.mbs(), static_cast<int>(robotIndex), cur_com_);
  type_ = "com";
  name_ = "com_" + robots.robot(robot_index_).name();
}

void CoMTask::reset()
{
  const mc_rbdyn::Robot & robot = robots.robot(rIndex);
  cur_com_ = rbd::computeCoM(robot.mb(), robot.mbc());
  errorT->com(cur_com_);
}

void CoMTask::move_com(const Eigen::Vector3d & com)
{
  cur_com_ += com;
  errorT->com(cur_com_);
}

void CoMTask::com(const Eigen::Vector3d & com)
{
  cur_com_ = com;
  errorT->com(com);
}

Eigen::Vector3d CoMTask::com()
{
  return errorT->com();
}

void CoMTask::addToLogger(mc_rtc::Logger & logger)
{
  logger.addLogEntry(name_ + "_damping",
                     [this]()
                     {
                     return damping();
                     });
  logger.addLogEntry(name_ + "_stiffness",
                     [this]()
                     {
                     return stiffness();
                     });
  logger.addLogEntry(name_ + "_target",
                     [this]() -> const Eigen::Vector3d &
                     {
                     return cur_com_;
                     });
  logger.addLogEntry(name_,
                     [this]() -> Eigen::Vector3d
                     {
                     return cur_com_ - eval();
                     });
}

void CoMTask::removeFromLogger(mc_rtc::Logger & logger)
{
  logger.removeLogEntry(name_ + "_damping");
  logger.removeLogEntry(name_ + "_stiffness");
  logger.removeLogEntry(name_ + "_target");
  logger.removeLogEntry(name_);
}

void CoMTask::addToGUI(mc_rtc::gui::StateBuilder & gui)
{
  TrajectoryTaskGeneric<tasks::qp::CoMTask>::addToGUI(gui);
  //gui.addElement(
  //  mc_rtc::gui::Element<Eigen::Vector3d>{
  //    {"Tasks", name_, "com_target"},
  //    [this]() { return this->com(); },
  //    [this](const Eigen::Vector3d & com) { this->com(com); }
  //  },
  //  mc_rtc::gui::Point3D{}
  //);
  //gui.addElement(
  //  mc_rtc::gui::Element<Eigen::Vector3d>{
  //    {"Tasks", name_, "com"},
  //    std::function<Eigen::Vector3d()>{
  //      [this]() { return (this->com() - eval()).eval(); }
  //    }
  //  },
  //  mc_rtc::gui::Point3D{}
  //);
}

}

namespace
{

static bool registered = mc_tasks::MetaTaskLoader::register_load_function("com",
  [](mc_solver::QPSolver & solver,
     const mc_rtc::Configuration & config)
  {
    auto t = std::make_shared<mc_tasks::CoMTask>(solver.robots(), config("robotIndex"));
    if(config.has("com"))
    {
      t->com(config("com"));
    }
    if(config.has("move_com"))
    {
      t->move_com(config("move_com"));
    }
    if(config.has("above"))
    {
      std::vector<std::string> surfaces = config("above");
      auto com = t->com();
      Eigen::Vector3d target = Eigen::Vector3d::Zero();
      auto & robot = solver.robot(config("robotIndex"));
      for(const auto & s : surfaces)
      {
        target += robot.surface(s).X_0_s(robot).translation();
      }
      target /= surfaces.size();
      t->com({target.x(), target.y(), com.z()});
    }
    t->load(solver, config);
    return t;
  }
);

}
