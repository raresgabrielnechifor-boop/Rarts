#include "Game301.h"
#include <iostream>

Game301::Game301() : GameMode("Classic 301", 301) {}

int Game301::processThrow(int currentScore, int pointsScored) const {
    if (currentScore - pointsScored < 0) return currentScore;
    return currentScore - pointsScored;
}

bool Game301::checkWinCondition(int currentScore) const {
    return currentScore == 0;
}

void Game301::printRules() const {
    GameMode::printRules();
    std::cout << "Rule: Must reach exactly 0. Bust applies.\n";
}

GameMode* Game301::clone() const {
    return new Game301(*this);
}