#pragma once

#include <cstdint>
#include "sqlite3.h"

namespace myClasses {
    class DatabaseHandler {
    public:
        DatabaseHandler() = default;

        explicit DatabaseHandler(const char *filename);

        [[nodiscard]] const sqlite3 *getDatabase() const;

        int16_t executeCommand(const char *command) const;

        ~DatabaseHandler();

    private:
        sqlite3 *db{};
    };
}  // namespace myClasses
