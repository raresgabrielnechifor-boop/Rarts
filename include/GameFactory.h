#pragma once
#include <memory>
#include "GameMode.h"
#include "Game301.h"
#include "Game501.h"
#include "PracticeMode.h"
#include "AroundTheClockMode.h"

class GameFactory {
public:
    static std::unique_ptr<GameMode> createGame(int option) {
        switch (option) {
            case 1: return std::make_unique<Game301>();
            case 2: return std::make_unique<Game501>();
            case 3: return std::make_unique<PracticeMode>();
            case 4: return std::make_unique<AroundTheClockMode>();
            default: return std::make_unique<Game501>();
        }
    }
};