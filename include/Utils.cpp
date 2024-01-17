#include "Utils.hpp"

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

namespace myLibs {

    int Utils::inputInt() {
        bool correctInput = false;
        std::string input = "";
        int inputInt = -1;
        do {
            std::cin >> input;
            try {
                inputInt = std::stoi(input);
            } catch (...) {
                std::cout << "Please input a number: ";
                continue;
            }
            correctInput = true;
        } while (!correctInput);
        if (inputInt == -1) {
            std::cout << "Error: Something went wrong! | 5001";
            std::exit(1001);
        }
        return inputInt;
    }

    float Utils::inputFloat() {
        bool correctInput = false;
        std::string input = "";
        float inputFloat = -1.0f;
        do {
            std::cin >> input;
            try {
                inputFloat = std::stof(input);
            } catch (...) {
                std::cout << "Please input a number: ";
                continue;
            }
            correctInput = true;
        } while (!correctInput);
        if (inputFloat < 0) {
            std::cout << "Error: Something went wrong! | 5001";
            std::exit(1001);
        }
        return inputFloat;
    }

    bool Utils::inputYN() {
        bool correctInput = false;
        std::string input = "";
        do {
            std::cin >> input;
            if (input.length() != 1) {
                std::cout << "Please enter y/n:";
                continue;
            }
            if (input != "y" && input != "n") {
                std::cout << "Please enter y/n:";
                continue;
            }
            correctInput = true;
        } while (!correctInput);
        return input == "y" ? true : false;
    }
}  // namespace myLibs
