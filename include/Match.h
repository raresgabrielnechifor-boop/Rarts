#pragma once
#include <string>
#include <iostream>
#include "Player.h"
#include "GameMode.h"

class Match {
private:
    std::string tournamentName;
    Player player1;
    Player player2;

    GameMode* mode; 

public:
    Match(const std::string& name, const Player& p1, const Player& p2, const GameMode* gameMode);

    Match(const Match& other);
    Match& operator=(Match other);
    ~Match();

    friend void swap(Match& first, Match& second) noexcept;

    void playRound(int p1Score, int p2Score);

    friend std::ostream& operator<<(std::ostream& os, const Match& m);
};