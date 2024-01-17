#include "TemperatureTask.hpp"  //;

#include <iostream>

#include "Utils.hpp"
#include "Logger.hpp"

using namespace myLibs;
namespace myTasks {
    Temperature::Temperature(bool run) {
        Logger::getInstance().log("Temperature constructor called.", "Info");
        if (run) {
            Temperature::run();
        }
    }

    int16_t Temperature::run() {
        Logger::getInstance().log("Temperature task called.", "Info");
        std::cout << "Welcome to the temperature programm!\n";
        std::cout << "This program has been written in the first lesson!";
        bool continueConversion = false;
        do {
            std::cout << "Do you want to convert from\n";
            std::cout << "1: Fahrenheit To Celsius\n";
            std::cout << "2: Celsius to Fahrenheit\n";
            int input = Utils::inputInt();
            switch (input) {
                case 1: {
                    std::cout << "Please enter a (point seperated) number:";
                    float inputTemperature = Utils::inputFloat();
                    float celsius = Temperature::convertToCelsius(
                            inputTemperature);
                    std::cout << inputTemperature << "°F is equal to "
                              << celsius << "°C!"
                              << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Please enter a (point seperated) number:";
                    float inputTemperature = Utils::inputFloat();
                    float fahrenheit = Temperature::convertToFahrenheit(
                            inputTemperature);
                    std::cout << inputTemperature << "°C is equal to "
                              << fahrenheit
                              << "°F!" << std::endl;
                    break;
                }
                default: {
                    std::cout << "This option does not exist!";
                    return 5002;
                }
            }
            std::cout << "Do you want to continue converting?(y/n)\n";
            continueConversion = Utils::inputYN();
        } while (continueConversion);
        return 1;
    }

    float Temperature::convertToFahrenheit(float celsius) {
        return celsius * Temperature::factor + (float) Temperature::offset;
    }

    float Temperature::convertToCelsius(float fahrenheit) {
        return (fahrenheit - (float) Temperature::offset) / Temperature::factor;
    }


}  // namespace myTasks
