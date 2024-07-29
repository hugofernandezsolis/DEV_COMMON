/**
 * @copyright Copyright (c) 2024
 * 
 * @author Hugo Fernandez Solis (hugofernandezsolis@gmail.com)
 * @date 28-07-2024
 * 
 * @file logs_tests.cpp
 * 
 * @brief Tests the correct functionality of the logging tool
 */


#include <iostream>

#include <Logger.h>


class Aux {
  public:
  void auxiliary(void) {
    LOG_INFO << "Info message";
    LOG_ERROR << "Error message";
    LOG_WARNING << "Warning message";
  }
};

// Usage example (this should be in your main or other appropriate location)
int main() {
  Aux a;
  a.auxiliary();
  LOG_INFO << "Info message";
  LOG_ERROR << "Error message";
  LOG_WARNING << "Warning message";

  return 0;
}
