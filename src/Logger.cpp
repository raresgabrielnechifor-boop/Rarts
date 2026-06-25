#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    logCount++;
    std::cout << "[MATCH LOG " << logCount << "]: " << message << "\n";
}