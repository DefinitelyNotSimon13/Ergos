#include "Logger.hpp"
#include <chrono>
#include <iomanip>

namespace myLibs {

    Logger::Logger() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream filename;
        filename << std::string(SOURCE_DIR) << "/logs/log_"
                 << std::put_time(std::localtime(&time), "%Y-%m-%d")
                 << ".txt";
        Logger::logFile.open(filename.str(), std::ios::app);
    }

    Logger::~Logger() {
        Logger::logFile.close();
    }

    Logger &Logger::getInstance() {
        static Logger instance;
        return instance;
    }

    void
    Logger::log(const std::string &message, const std::string &filename,
                const int &line, const std::string &function,
                const std::string &type) {
        Logger::logFile << getTimestamp() << type << " - " << filename << ":"
                        << line << " " << function << " "
                        << message << std::endl;
    }

    void Logger::log(const std::string &message, const std::string &type) {
        Logger::logFile << getTimestamp() << type << " - " << message
                        << std::endl;
    }

    std::string Logger::getTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%H:%M:%S") << " | ";
        return ss.str();
    }
} // myUtils

