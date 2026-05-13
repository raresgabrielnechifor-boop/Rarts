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
    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const GameMode& gm);
};

class Game301 : public GameMode {
public:
    Game301();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int currentScore) const override;
    void printRules() const override;
    GameMode* clone() const override;
};

class Game501 : public GameMode {
public:
    Game501();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int currentScore) const override;
    void printRules() const override;
    GameMode* clone() const override;
};

class PracticeMode : public GameMode {
public:
    PracticeMode();
    int processThrow(int currentScore, int pointsScored) const override;
    bool checkWinCondition(int currentScore) const override;
    void printRules() const override;
    GameMode* clone() const override;
};