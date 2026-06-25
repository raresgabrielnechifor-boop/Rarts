#pragma once
#include "GameMode.h"

class PracticeMode : public GameMode {
public:
    PracticeMode();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int) const override;
    void printRules() const override;
    GameMode* clone() const override;
};