#pragma once
#include "GameMode.h"

class Game301 : public GameMode {
public:
    Game301();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int currentScore) const override;
    void printRules() const override;
    GameMode* clone() const override;
};