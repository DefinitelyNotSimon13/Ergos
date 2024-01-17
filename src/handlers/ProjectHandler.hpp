#pragma once

#include <memory>

#include "DatabaseHandler.hpp"
#include "../entities/project.hpp"

using namespace myEntities;

namespace myClasses {
    class ProjectHandler {
    public:
        ProjectHandler();

        explicit ProjectHandler(std::shared_ptr<DatabaseHandler> newDbHandler);

        static std::shared_ptr<Project> createProjectInTerminal();

    private:
        std::shared_ptr<DatabaseHandler> dbHandler = nullptr;
    };
}  // namespace myClasses
