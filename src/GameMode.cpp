#include "GameMode.h"

GameMode::GameMode(const std::string& name, int score) : modeName(name), startingScore(score) {}

void GameMode::printDetails(std::ostream& os) const {
    os << "Playing: " << modeName << " | Start Score/Target: " << startingScore;
}

void GameMode::printRules() const {
    std::cout << *this << "\n";
}

int GameMode::getStartingScore() const {
    return startingScore;
}

const std::string& GameMode::getName() const {
    return modeName;
}

std::ostream& operator<<(std::ostream& os, const GameMode& gm) {
    gm.printDetails(os);
    return os;
}