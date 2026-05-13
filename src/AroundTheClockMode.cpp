#include "AroundTheClockMode.h"

AroundTheClockMode::AroundTheClockMode() : GameMode("Around The Clock", 1) {}
int AroundTheClockMode::processThrow(int currentScore, int pointsScored) const { return (pointsScored == currentScore) ? currentScore + 1 : currentScore; }
bool AroundTheClockMode::checkWinCondition(int currentScore) const { return currentScore > 20; }
void AroundTheClockMode::printRules() const { GameMode::printRules(); std::cout << "Rule: Hit targets 1-20 in order.\n"; }
GameMode* AroundTheClockMode::clone() const { return new AroundTheClockMode(*this); }