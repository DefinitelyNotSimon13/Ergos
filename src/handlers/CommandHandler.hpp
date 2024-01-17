#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace myClasses {

    class CommandHandler {
    public:
        CommandHandler() = default;
        CommandHandler(int argc, char* argv[]);
        ~CommandHandler() = default;
        void processCommands(int argc, char* argv[]);
        void processCommand(const std::string& command);
        void help();
        void create();
        void delete_();
        void edit();
        void list();
        void temperature();
        void exit();
    private:
         std::unordered_map<std::string, void (CommandHandler::*)()> commandMap = {
            {"help", &CommandHandler::help},
            {"create", &CommandHandler::create},
            {"delete", &CommandHandler::delete_},
            {"edit", &CommandHandler::edit},
            {"list", &CommandHandler::list},
            {"temperature", &CommandHandler::temperature},
            {"exit", &CommandHandler::exit}
        };
    };

} // myClasses
