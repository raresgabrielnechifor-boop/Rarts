#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) const {
    std::cout << "[MATCH LOG]: " << message << "\n";
}