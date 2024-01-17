#include <iostream>
#include <string>
#include <vector>

#include "TemperatureTask.hpp"
#include "Utils.hpp"
#include "Logger.hpp"
#include "CommandHandler.hpp"

using namespace myLibs;
using namespace myClasses;

std::vector<std::string> projects = {"Temperatures", "project2"};

int main(int argc, char *argv[]) {
    if(argc > 1) {
        Logger::getInstance().log("Program started with commands!", "Info");
        CommandHandler cmdHandler(argc, argv);
        Logger::getInstance().log("Program ended after CommandHandler execution!", "Info");
        return 0;
    }

    Logger::getInstance().log("Program started without commands", "Info");
    std::cout << "Hello there!\nPress any button to continue!\n";
    std::cin.ignore();
    std::cout << "Which project do you want to open?\n";

    int i = 1;
    for (const std::string &project: projects) {
        std::cout << i << " - " << project << "\n";
        ++i;
    }
    Logger::getInstance().log("Waiting for user input!", "Debug");
    int inputInt = Utils::inputInt();
    switch (inputInt) {
        case 1: {
            myTasks::Temperature(true);
            break;
        }
        case 2: {
            break;
        }
        default: {
            std::cout << "This project does not exist!\n";
        }
    }
    Logger::getInstance().log("Program ended after project execution!", "Info");
    return 0;
}
