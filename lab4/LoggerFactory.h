#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <memory>
#include <string>
#include "ILogger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"


class LoggerFactory {
    public:
        static ILogger* CreateLogger(int type, const std::string& filename = "");
};

#endif