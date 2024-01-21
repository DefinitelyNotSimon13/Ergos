#include "Logger.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

namespace myLibs {

    //! TODO - Use getTimestamp() function
    Logger::Logger() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::tm timeInfo{};
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&timeInfo, &time);
#else
        localtime_r(&time, &timeInfo);
#endif
        std::stringstream filename;
        filename << std::string(SOURCE_DIR) << "/log/log_"
                 << std::put_time(&timeInfo, "%Y-%m-%d")
                 << ".txt";
        Logger::logFile.open(filename.str(), std::ios::app);
    }

    Logger::~Logger() {
        try{
        Logger::logFile.close();
        } catch(...) {
            std::exit(-1);
        }
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
        std::tm timeInfo{};
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&timeInfo, &time);
#else
        localtime_r(&time, &timeInfo);
#endif
        std::stringstream ss;
        ss << std::put_time(&timeInfo, "%H:%M:%S") << " | ";
        return ss.str();
    }
} // myUtils

