/**
 * @file Logger.h
 * @author Hugo Fernández Solís (hugofernandezsolis@gmail.com)
 * @date 2025-01-17
 * 
 * @brief 
 * 
 * @copyright Copyright (c) 2025
**/


#pragma once

#include <filesystem>
#include <fstream>
#include <mutex>


namespace _priv_logger_ {


#ifndef LOG_FILE_PATH
  #define LOG_FILE_PATH "/tmp/logs/default.log"
#endif


/*
 * Logger types
 */
enum class LogLevel {
  INFO,
  WARNING,
  ERROR,
  DEBUG
};


/**
 * @class Logger
 * 
 * @brief 
 */
class Logger {
public:
//// PUBLIC ///////////////////////////////////      CONSTRUCTORS       ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PUBLIC ///////////////////////////////////    GETTERS & SETTERS    ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PUBLIC ///////////////////////////////////      CLASS METHODS      ////////////////////////////////////////////////
  /**
   * @brief
   * 
   * @return
   */
  static Logger& Instance(void);

  /**
   * @brief
   * 
   * @param iFilename
   */
  void set_log_file(const std::filesystem::path& iFilename);
  
  /**
   * @brief
   * 
   * @param iLevel
   * @param iFile
   * @param iLine
   * @param iFunc
   * @param iMessage
   */
  void log(const LogLevel& iLevel, const std::string& iFile, const std::string& iFunc, const std::string& iMessage);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PUBLIC ///////////////////////////////////        OPERATORS        ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PUBLIC ///////////////////////////////////       DESTRUCTORS       ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

protected:
//// PROTECTED ////////////////////////////////      CONSTRUCTORS       ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PROTECTED ////////////////////////////////    SETTERS & GETTERS    ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PROTECTED ////////////////////////////////      CLASS METHODS      ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PROTECTED ////////////////////////////////        OPERATORS        ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PROTECTED ////////////////////////////////       DESTRUCTORS       ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

private:
//// PRIVATE //////////////////////////////////      CONSTRUCTORS       ////////////////////////////////////////////////
  /**
   * @brief
   */
  Logger(void);

  /**
   * @brief
   * 
   * @param iOther
   */
  Logger (const Logger& iOther) = delete;

  /**
   * @brief
   * 
   * @param iOther
   */
  Logger(Logger&& iOther) noexcept = delete;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PRIVATE //////////////////////////////////    SETTERS & GETTERS    ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// PRIVATE //////////////////////////////////      CLASS METHODS      ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PRIVATE //////////////////////////////////        OPERATORS        ////////////////////////////////////////////////
  /**
   * @brief
   * 
   * @param iOther
   * 
   * @return
   */
  Logger& operator=(const Logger& iOther) = delete;

  /**
   * @brief
   * 
   * @param iOther
   * 
   * @return
   */
  Logger& operator=(Logger&& iOther) noexcept = delete;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//// PRIVATE //////////////////////////////////       DESTRUCTORS       ////////////////////////////////////////////////
  /**
   * @brief
   */
  ~Logger();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

private:
  std::ofstream logFile_;
  std::mutex mutex_;

  std::filesystem::path logFilePath_ = LOG_FILE_PATH;
};


} // namespace _priv_logger_