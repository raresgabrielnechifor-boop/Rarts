#pragma once
#include "GameMode.h"

class AroundTheClockMode : public GameMode {
public:
    AroundTheClockMode();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int currentScore) const override;
    void printRules() const override;
    GameMode* clone() const override;
};