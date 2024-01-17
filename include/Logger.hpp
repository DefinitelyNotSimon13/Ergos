#pragma once

#include <fstream>

namespace myLibs {

    class Logger {
    public:
        static Logger& getInstance();
        void log(const std::string& message, const std::string& filename, const int& line, const std::string& function, const std::string& type = "INFO");
        void log(const std::string& message, const std::string& type = "INFO");

        Logger(const Logger&)= delete;
        Logger& operator=(const Logger&)= delete;
    private:
        Logger();
        ~Logger();
        static std::string getTimestamp();
        std::ofstream logFile;
    };

} // myUtils
