/**
 * @copyright Copyright (c) 2023
 * 
 * @author Hugo Fernandez Solis (hugofernandezsolis@gmail.com)
 * @date 02-12-2023
 * 
 * @file Logs.h
 * 
 * @brief Macros and functions to help creating logs.
 */


#ifndef LOGGER_H
#define LOGGER_H

#include <cstring>
#include <fstream>
#include <mutex>
#include <string>
#include <iostream>


namespace hidden {
  // Define the ANSI color codes
  #define RESET       "\033[0m"
  #define RED         "\033[31m"
  #define YELLOW      "\033[33m"
  #define WHITE       "\033[37m"


/**
 * @brief 
 * 
 */
class Logger {
  public:
    static Logger& getInstance();

    template<typename T>
    Logger& operator<<(const T& msg);

    Logger& operator<<(std::ostream& (*pf)(std::ostream&));

    Logger(const Logger&) = delete;
    Logger(Logger&&)      = delete;

    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&)      = delete;

  private:
    Logger();
    ~Logger();

    std::ofstream file;
    std::mutex mu;
};

#include <Logger.tpp>

}

#define LOG_INFO    hidden::Logger::getInstance() << "\n[INFO]"    << " | " << __DATE__ << " - " << __TIME__ << " | " << __FILE__ << ":" << __LINE__ << " | " << strchr(__PRETTY_FUNCTION__, ' ') + 1 << "\n  >> "
#define LOG_ERROR   hidden::Logger::getInstance() << "\n[ERROR]"   << " | " << __DATE__ << " - " << __TIME__ << " | " << __FILE__ << ":" << __LINE__ << " | " << strchr(__PRETTY_FUNCTION__, ' ') + 1 << "\n  >> "
#define LOG_WARNING hidden::Logger::getInstance() << "\n[WARNING]" << " | " << __DATE__ << " - " << __TIME__ << " | " << __FILE__ << ":" << __LINE__ << " | " << strchr(__PRETTY_FUNCTION__, ' ') + 1 << "\n  >> "


#endif // LOGGER_H