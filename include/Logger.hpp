#pragma once

#include <fstream>

namespace myLibs {

    /**
     * @class Logger
     *
     * @brief The Logger class provides a simple logging functionality.
     *
     * The Logger class allows logging messages with various details such as message content,
     * logging type, file name, line number, and function name. It also generates and appends
     * timestamps to the log messages. The Logger class is a singleton class, meaning that
     * only one instance can be created, and it can be accessed through the getInstance() method.
     *
     * The Logger class uses ofstream to write log messages to a log file. The log file is
     * created using the current date in the format "logs/log_YYYY-MM-DD.txt" and is appended
     * with new log entries.
     */
    class Logger {
    public:
        /**
         * @brief Gets the instance of the Logger class.
         *
         * @return Logger& A reference to the Logger instance.
         */
        static Logger &getInstance();

        /**
         * @brief Logs a message with the specified details.
         *
         * @param message The message to be logged.
         * @param filename The file name where the log message occurred.
         * @param line The line number where the log message occurred.
         * @param function The function name where the log message occurred.
         * @param type The log type. Default value is "INFO".
         */
        void log(const std::string &message, const std::string &filename,
                 const int &line, const std::string &function,
                 const std::string &type = "INFO");

        /**
         * @brief Logs a message with the specified details.
         *
         * @param message The message to be logged.
         * @param type The log type. Default value is "INFO".
         */
        void log(const std::string &message, const std::string &type = "INFO");

        Logger(const Logger &) = delete;

        Logger &operator=(const Logger &) = delete;

    private:
        Logger();

        ~Logger();

        /**
         * @brief Returns the current timestamp in the format "HH:MM:SS | ".
         *
         * @return std::string The formatted timestamp.
         */
        static std::string getTimestamp();

        std::ofstream logFile;
    };

} // myUtils
