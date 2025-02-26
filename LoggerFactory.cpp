#include "LoggerFactory.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

ILogger* LoggerFactory::CreateLogger(int type, const std::string& filename) {
    switch (type) {
        case 1: // ConsoleLogger
            return new ConsoleLogger();
        case 2: // FileLogger
            return new FileLogger(filename);
        default:
            return nullptr; // Если тип некорректен
    }
}
