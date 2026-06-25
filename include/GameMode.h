#pragma once
#include <string>
#include <iostream>

class GameMode {
protected:
    std::string modeName;
    int startingScore;
public:
    GameMode(const std::string& name, int score);
    virtual ~GameMode() = default;

    virtual int processThrow(int currentScore, int pointsScored) const = 0;
    virtual bool checkWinCondition(int currentScore) const = 0;
    virtual void printDetails(std::ostream& os) const;
    virtual void printRules() const;
    virtual GameMode* clone() const = 0;

    int getStartingScore() const;
    const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const GameMode& gm);
};