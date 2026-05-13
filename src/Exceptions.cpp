#include "Exceptions.h"

DartsException::DartsException(const std::string& msg) : message(msg) {}
const char* DartsException::what() const noexcept { return message.c_str(); }

InvalidThrowException::InvalidThrowException(int points) 
    : DartsException("Invalid throw: " + std::to_string(points) + " is not possible!") {}

PlayerNotFoundException::PlayerNotFoundException(const std::string& name) 
    : DartsException("Player validation error: '" + name + "' is not a valid name!") {}

InvalidMatchConfigException::InvalidMatchConfigException(const std::string& reason) 
    : DartsException("Match Config error: " + reason) {}