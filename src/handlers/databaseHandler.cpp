#include "databaseHandler.hpp"
#include <cstddef>
namespace myClasses {
DatabaseHandler::DatabaseHandler(const char* filename) {
  int statusCode = sqlite3_open(filename, &this->db);
}
DatabaseHandler::~DatabaseHandler(){
  //sqlite3_close(db);
}
const sqlite3* DatabaseHandler::getDatabase() const { return this->db; }
const int16_t DatabaseHandler::executeCommand(const char* command) const {
  return sqlite3_exec(this->db, command, NULL, NULL, NULL);
}
}  // namespace myClasses
