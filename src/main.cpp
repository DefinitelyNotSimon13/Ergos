#include <string>
#include <vector>

#include "CommandHandler.hpp"
#include "Logger.hpp"
#include "MenuHandler.hpp"
#include "Utils.hpp"

using namespace myLibs;
using namespace myClasses;

std::vector<std::string> projects = {"Temperatures", "project2", "example",
                                     "other"};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    Logger::getInstance().log("Program started with commands!", "Info");
    CommandHandler cmdHandler(argc, argv);
    Logger::getInstance().log("Program ended after CommandHandler execution!",
                              "Info");
    return 0;
  }

  Logger::getInstance().log("Program started without commands", "Info");
  MenuHandler menuHandler(argc, argv);
  menuHandler.anyToContinue("Hello there!");
  menuHandler.runStartMenu(projects);
  Logger::getInstance().log("Program ended after project execution!", "Info");
  return 0;
}
