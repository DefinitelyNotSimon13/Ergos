#include <memory>

#include "databaseHandler.hpp"
#include "project.hpp"
using namespace myDatabaseHandler;
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
