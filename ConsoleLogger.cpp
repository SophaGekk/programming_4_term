#include "ConsoleLogger.h"

void ConsoleLogger::Log(const std::string& message) {
    std::cout << "[Console] " << message << std::endl;
}
