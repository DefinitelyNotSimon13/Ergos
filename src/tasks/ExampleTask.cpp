#include "ExampleTask.hpp"

#include <iostream>

#include "Logger.hpp"
// #include "Utils.hpp"

using namespace myLibs;

namespace myTasks {

    ExampleTask::ExampleTask(bool run) {
        Logger::getInstance().log("ExampleTask constructor called.", "Info");
        if (run) {
            this->run();
        }
    }

    int ExampleTask::run() {
        Logger::getInstance().log("ExampleTask task called.", "Info");
        std::cout << "Hello World!\n";
        std::cout << "This is an example task, it can not do anything!\n";
        std::cout << "It is just here to be copied for new tasks :D\n";
        return 0;
    }
} // myTasks