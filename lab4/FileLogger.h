#ifndef FILELOGGER_H
#define FILELOGGER_H
#include "ILogger.h"
#include <fstream>

class FileLogger : public ILogger {
public:
    FileLogger(const std::string& filename);
    void Log(const std::string& message) override;

private:
    std::ofstream _fileStream;
};

#endif