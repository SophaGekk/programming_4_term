#include "FileLogger.h"

FileLogger::FileLogger(const std::string& filename) : _fileStream(filename, std::ios_base::app) {
}

void FileLogger::Log(const std::string& message) {
    if (_fileStream.is_open()) {
        _fileStream << "[File] " << message << std::endl;
        _fileStream.flush(); // гарантирует, что лог-сообщения будут записаны в файл немедленно
    }
}
