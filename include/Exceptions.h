#pragma once
#include <exception>
#include <string>

class DartsException : public std::exception {
protected:
    std::string message;
public:
    explicit DartsException(const std::string& msg);
    const char* what() const noexcept override;
};

class InvalidThrowException : public DartsException {
public:
    explicit InvalidThrowException(int points);
};

class PlayerNotFoundException : public DartsException {
public:
    explicit PlayerNotFoundException(const std::string& name);
};

class InvalidMatchConfigException : public DartsException {
public:
    explicit InvalidMatchConfigException(const std::string& reason);
};