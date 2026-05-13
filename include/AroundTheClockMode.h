#pragma once
#include "GameMode.h"
#include <iostream>

class AroundTheClockMode : public GameMode {
public:
    AroundTheClockMode() : GameMode("Around The Clock", 1) {}

    bool checkWinCondition(int currentScore) const override {
        return currentScore == 21;
    }

    void printRules() const override {
        GameMode::printRules();
        std::cout << "Rule: Hit numbers 1 to 20 in sequential order.\n";
    }

    GameMode* clone() const override {
        return new AroundTheClockMode(*this);
    }
};