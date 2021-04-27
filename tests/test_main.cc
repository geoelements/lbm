#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_RUNNER

#include <iostream>

#include "catch.hpp"

int main(int argc, char** argv) {
  try {
    Catch::Session session;
    // Let Catch (using Clara) parse the command line
    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0)  // Indicates a command line error
      return returnCode;
    int result = session.run();
    return result;
  } catch (std::exception& exception) {
    std::cerr << "Test: " << exception.what() << std::endl;
  }
}
