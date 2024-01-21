#pragma once

#include <cstdint>

namespace myClasses {
    class DatabaseHandler {
    public:
        DatabaseHandler() = default;

        explicit DatabaseHandler(const char *filename);

        ~DatabaseHandler();

    private:
    };
}  // namespace myClasses
