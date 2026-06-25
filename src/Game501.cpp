#include "Game501.h"
#include <iostream>

Game501::Game501() : GameMode("Pro 501", 501) {}

int Game501::processThrow(int currentScore, int pointsScored) const {
    if (currentScore - pointsScored < 0) return currentScore;
    return currentScore - pointsScored;
}

bool Game501::checkWinCondition(int currentScore) const {
    return currentScore == 0;
}

void Game501::printRules() const {
    GameMode::printRules();
    std::cout << "Rule: Pro standard. Must reach exactly 0.\n";
}

GameMode* Game501::clone() const {
    return new Game501(*this);
}