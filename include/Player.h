#pragma once
#include <string>
#include <iostream>
#include "Dart.h"
#include "Templates.h"

class GameMode;

class Player {
private:
    std::string name;
    int currentScore;
    Dart myDart;
    Tracker<int> throwHistory;

public:
    Player(const std::string& playerName, int initialScore, const Dart& playerDart);
    Player();

    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    bool throwDart(int pointsScored, const GameMode* mode);

    int getCurrentScore() const { return currentScore; }
    const std::string& getName() const;
    void printHistory() const;
    const Tracker<int>& getThrowHistory() const { return throwHistory; }

    friend std::ostream& operator<<(std::ostream& os, const Player& p);
};