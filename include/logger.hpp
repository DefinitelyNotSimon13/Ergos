#pragma once

#include <fstream>

namespace myLibs {

    class logger {
    public:
        static logger& getInstance();
        void log(const std::string& message, const std::string& filename, const int& line, const std::string& function, const std::string& type = "INFO");
        void log(const std::string& message, const std::string& type = "INFO");

        logger(const logger&)= delete;
        logger& operator=(const logger&)= delete;
    private:
        logger();
        ~logger();
        static std::string getTimestamp();
        std::ofstream logFile;
    };

} // myUtils
