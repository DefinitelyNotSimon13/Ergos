#include "logger.hpp"
#include <chrono>
#include <iomanip>

namespace myLibs {

    logger::logger() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream filename;
        filename << std::string(SOURCE_DIR) << "/logs/log_" << std::put_time(std::localtime(&time), "%Y-%m-%d")
                 << ".txt";
        logger::logFile.open(filename.str(), std::ios::app);
    }

    logger::~logger() {
        logger::logFile.close();
    }

    logger &logger::getInstance() {
        static logger instance;
        return instance;
    }

    void
    logger::log(const std::string &message, const std::string &filename, const int &line, const std::string &function,
                const std::string &type) {
        logger::logFile << getTimestamp() << type << " - " << filename << ":" << line << " " << function << " "
                        << message << std::endl;
    }

    void logger::log(const std::string &message, const std::string &type) {
        logger::logFile << getTimestamp() << type << " - " << message << std::endl;
    }

    std::string logger::getTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%H:%M:%S") << " | ";
        return ss.str();
    }
} // myUtils

