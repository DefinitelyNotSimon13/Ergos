#include "MenuHandler.hpp"

#include <iostream>
#include <vector>

#include "ExampleTask.hpp"
#include "Logger.hpp"
#include "TemperatureTask.hpp"
#include "Utils.hpp"

using namespace myLibs;

namespace myClasses {
MenuHandler::MenuHandler(int argc, char* argv[]) {
  this->ptrCmdHandler = std::make_shared<CommandHandler>(argc, argv);
  Logger::getInstance().log("MenuHandler initiliasied!", "Debug");
}

void MenuHandler::anyToContinue(const std::string& message) {
  std::cout << message << "\nPress any button to continue!";
  std::cin.ignore();
}

void MenuHandler::displayMenu(const std::vector<std::string>& menuItems) {
  Logger::getInstance().log("Displaying a menu!", "Info");
  uint16_t i = 1;
  for (const std::string& item : menuItems) {
    std::cout << i << " - " << item << "\n";
    ++i;
  }
}
void MenuHandler::runStartMenu(const std::vector<std::string>& menuItems) {
  Logger::getInstance().log("Running start menu!", "Info");
  std::cout << "Start Menu:\n";
  std::cout << "What do you want to do?\n";
  this->displayMenu(menuItems);
  Logger::getInstance().log("Waiting for user input!", "Debug");
  uint16_t inputInt = Utils::inputInt();
  switch (inputInt) {
    case 1: {
      Logger::getInstance().log("1. Temperature task chosen!", "Info");
      myTasks::Temperature(true);
      break;
    }
    case 2: {
      Logger::getInstance().log("2. Unimplemented task chosen!", "Info");
      std::cout << "Not yet implemented\n";
      break;
    }
    case 3: {
      Logger::getInstance().log("3. Example task chosen!", "Info");
      myTasks::ExampleTask(true);
    }
    default: {
      Logger::getInstance().log("Undefined task chosen!", "Info");
      std::cout << "This project does not exist!\n";
    }
  }
}
}  // namespace myClasses
