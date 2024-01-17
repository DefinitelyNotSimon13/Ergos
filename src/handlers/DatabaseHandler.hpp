#pragma once

#include <cstdint>
#include "sqlite3.h"

namespace myClasses {
class DatabaseHandler {
 public:
  DatabaseHandler()= default;
  DatabaseHandler(const char* filename);
  const sqlite3* getDatabase() const;
  const int16_t executeCommand(const char* command) const;
  ~DatabaseHandler();
 private:
  sqlite3* db{};
};
}  // namespace myClasses
