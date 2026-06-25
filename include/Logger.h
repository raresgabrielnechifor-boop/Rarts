#pragma once
#include <string>
#include <iostream>

class Logger {
private:
    int logCount = 0;
    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();

    void log(const std::string& message);
};