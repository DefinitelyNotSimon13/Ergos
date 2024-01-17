#include "ProjectHandler.hpp"
#include <fstream>
#include <string>
#include <utility>
#include <iostream>

namespace myClasses {
    ProjectHandler::ProjectHandler() {
        std::string database = "projects.db";
        const char *test = database.c_str();
        std::shared_ptr<DatabaseHandler> ptrDbHandler =
                std::make_shared<DatabaseHandler>(test);
    }

    ProjectHandler::ProjectHandler(
            std::shared_ptr<DatabaseHandler> newDbHandler) {
        this->dbHandler = std::move(newDbHandler);
    }

    std::shared_ptr<Project> ProjectHandler::createProjectInTerminal() {
        std::shared_ptr<Project> ptrProject = std::make_shared<Project>();
        return ptrProject;
    }
}  // namespace myClasses
