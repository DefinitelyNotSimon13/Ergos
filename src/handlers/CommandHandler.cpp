#include <iostream>
#include "CommandHandler.hpp"
#include "Logger.hpp"
#include "TemperatureTask.hpp"

using namespace myLibs;

namespace myClasses {
    CommandHandler::CommandHandler(int argc, char **argv) {
        Logger::getInstance().log("CommandHandler started!", "Debug");
        if(argc == 1) {
            return;
        }
        this->processCommands(argc, argv);
    }

    void CommandHandler::processCommands(int argc, char **argv) {
        Logger::getInstance().log("Processing commands!", "Debug");
        for(int i = 1; i < argc; i++) {
            this->processCommand(argv[i]);
        }
    }

    void CommandHandler::processCommand(const std::string& command) {
        Logger::getInstance().log("Processing command: " + command, "Info");
        auto it = this->commandMap.find(command);
        if(it != this->commandMap.end()) {
            Logger::getInstance().log("Command found – executing", "Info");
            (this->*(it->second))();
        } else {
            Logger::getInstance().log("Command can't be found!", "Error");
            std::cout << "Command can't be found!\nExiting...\n";
        }
    }

    void CommandHandler::help() {
        Logger::getInstance().log("Executing help command!", "Info");
        std::cout << "help - TBD\n";
    }

    void CommandHandler::create() {
        Logger::getInstance().log("Executing create command!", "Info");
        std::cout << "create - TBD\n";
    }

    void CommandHandler::delete_() {
        Logger::getInstance().log("Executing delete command!", "Info");
        std::cout << "delete - TBD\n";
    }

    void CommandHandler::edit() {
        Logger::getInstance().log("Executing edit command!", "Info");
        std::cout << "edit - TBD\n";
    }

    void CommandHandler::list() {
        Logger::getInstance().log("Executing list command!", "Info");
        std::cout << "list - TBD\n";
    }

    void CommandHandler::temperature() {
        Logger::getInstance().log("Executing temperature command!", "Info");
        std::cout << "Starting temperature programm...\n";
        myTasks::Temperature(true);
    }

    void CommandHandler::exit() {
        Logger::getInstance().log("Executing exit command!", "Info");
        std::cout << "exit - TBD\n";
    }

} // myClasses