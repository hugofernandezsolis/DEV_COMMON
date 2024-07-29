/**
 * @copyright Copyright (c) 2023
 * 
 * @author Hugo Fernandez Solis (hugofernandezsolis@gmail.com)
 * @date 02-12-2023
 * 
 * @file Logger.h
 * 
 * @brief Macros and functions to help creating logs.
 */


#include <stdexcept>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <Logger.h>


namespace hidden {

  Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
  }

  Logger::Logger() {
    boost::property_tree::ptree pt;
    std::string logFilePath;
    try {
        read_xml("../configs/Logger.xml", pt);
        logFilePath = pt.get<std::string>("Logger.file.path");
    } catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return;
    }
    file.open(logFilePath, std::ios::app);
    if (!file.is_open()) {
      std::cerr << "Failed to open log file";
      return;
    }
  }

  Logger::~Logger() {
    if (file.is_open()) {
      file.close();
    }
  }

}