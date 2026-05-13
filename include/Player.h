#pragma once
#include <string>
#include <iostream>
#include "Dart.h"

class Player {
private:
    std::string name;
    int currentScore;
    Dart myDart;

public:
    Player(const std::string& playerName, int initialScore, const Dart& playerDart);
    Player();

    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    bool throwDart(int pointsScored);
    bool hasWon() const;
    const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Player& p);
};