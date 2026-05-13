#pragma once
#include <exception>
#include <string>

class DartsException : public std::exception {
protected:
    std::string message;
public:
    explicit DartsException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidThrowException : public DartsException {
public:
    explicit InvalidThrowException(int points) 
        : DartsException("Invalid throw: " + std::to_string(points) + " is not possible with one dart!") {}
};

class PlayerNotFoundException : public DartsException {
public:
    explicit PlayerNotFoundException(const std::string& name) 
        : DartsException("Player not found: " + name) {}
};

class InvalidMatchConfigException : public DartsException {
public:
    explicit InvalidMatchConfigException(const std::string& reason) 
        : DartsException("Invalid Match Config: " + reason) {}
};