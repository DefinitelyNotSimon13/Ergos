#pragma once

#include <memory>

#include "DatabaseHandler.hpp"
#include "../entities/project.hpp"
using namespace myEntities;

namespace myClasses {
class ProjectHandler {
 public:
  ProjectHandler();
  ProjectHandler(std::shared_ptr<DatabaseHandler> newDbHandler);
  std::shared_ptr<Project> createProjectInTerminal();

 private:
  std::shared_ptr<DatabaseHandler> dbHandler = nullptr;
};
}  // namespace myClasses
