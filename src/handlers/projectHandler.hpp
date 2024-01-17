#include <memory>

#include "databaseHandler.hpp"
#include "../entities/project.hpp"
using namespace myClasses;
using namespace myProjects;

namespace myProjectHandler {
class ProjectHandler {
 public:
  ProjectHandler();
  ProjectHandler(std::shared_ptr<DatabaseHandler> newDbHandler);
  std::shared_ptr<Project> createProjectInTerminal();

 private:
  std::shared_ptr<DatabaseHandler> dbHandler = nullptr;
};
}  // namespace myProjectHandler
