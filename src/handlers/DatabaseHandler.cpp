#include "DatabaseHandler.hpp"

namespace myClasses {
    DatabaseHandler::DatabaseHandler(const char *filename) {
        int statusCode = sqlite3_open(filename, &this->db);
    }

    DatabaseHandler::~DatabaseHandler() {
        sqlite3_close(db);
    }

    const sqlite3 *DatabaseHandler::getDatabase() const { return this->db; }

    int16_t DatabaseHandler::executeCommand(const char *command) const {
        return (int16_t) sqlite3_exec(this->db, command, nullptr, nullptr,
                                      nullptr);
    }
}  // namespace myClasses
