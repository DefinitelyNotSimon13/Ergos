#include <sqlite3.h>

#include <iostream>
#include <string>
#include <vector>

#include "temperature.hpp"
#include "utils.hpp"
#include "projectHandler.hpp"

using namespace myUtils;
using namespace myDatabaseHandler;
using namespace myProjectHandler;

int main(int argc, char *argv[]) {
    std::vector<std::string> projects = {"Temperatures", "project2"};
    std::cout << "Hello there!\nPress any button to continue!\n";
    std::cin.ignore();
    std::cout << "Which project do you want to open?\n";
    int i = 1;
    for (const std::string &project: projects) {
        std::cout << i << " - " << project << "\n";
        ++i;
    }
    std::string input = "";
    bool correctInput = false;
    int inputInt = Utils::inputInt();
    switch (inputInt) {
        case 1: {
            myTemperature::Temperature temperatureProject =
                    myTemperature::Temperature(true);
            break;
        }
        case 2: {
            break;
        }
        default: {
            std::cout << "This project does not exist!\n";
        }
    }
    return 0;
}
