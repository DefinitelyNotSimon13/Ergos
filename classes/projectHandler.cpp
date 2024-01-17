#include "../include/projectHandler.hpp"
namespace myProjectHandler {
ProjectHandler::ProjectHandler() {
  DatabaseHandler *dbHandler = new DatabaseHandler("database.db");
  std::shared_ptr<DatabaseHandler> ptrDbHandler =
      std::make_shared<DatabaseHandler>(dbHandler);
}
ProjectHandler::ProjectHandler(std::shared_ptr<DatabaseHandler> newDbHandler){
  this->dbHandler = newDbHandler;
}
std::shared_ptr<Project> ProjectHandler::createProjectInTerminal(){
  std::shared_ptr<Project> ptrProject = std::make_shared<Project>(new Project());

  return ptrProject;
}
}  // namespace myProjectHandler
