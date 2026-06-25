#include "PracticeMode.h"
#include <iostream>

PracticeMode::PracticeMode() : GameMode("Practice", 0) {}

int PracticeMode::processThrow(int currentScore, int pointsScored) const {
    return currentScore + pointsScored;
}

bool PracticeMode::checkWinCondition(int) const {
    return false;
}

void PracticeMode::printRules() const {
    GameMode::printRules();
    std::cout << "Rule: Just throw and accumulate points.\n";
}

GameMode* PracticeMode::clone() const {
    return new PracticeMode(*this);
}