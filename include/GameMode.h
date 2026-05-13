#pragma once
#include <string>
#include <iostream>

class GameMode {
protected:
    std::string modeName;
    int startingScore;

public:
    GameMode(const std::string& name, int score) : modeName(name), startingScore(score) {}
    
    virtual ~GameMode() = default;

    virtual bool checkWinCondition(int currentScore) const = 0; 

    virtual void printRules() const {
        std::cout << "Playing: " << modeName << " | Start Score: " << startingScore << "\n";
    }

    virtual GameMode* clone() const = 0; 

    int getStartingScore() const { return startingScore; }
    std::string getName() const { return modeName; }
};

class Game301 : public GameMode {
public:
    Game301() : GameMode("Classic 301", 301) {}

    bool checkWinCondition(int currentScore) const override {
        return currentScore == 0;
    }

    void printRules() const override {
        GameMode::printRules();
        std::cout << "Rule: Must reach exactly 0. Bust applies.\n";
    }

    GameMode* clone() const override {
        return new Game301(*this);
    }
};

class Game501 : public GameMode {
public:
    Game501() : GameMode("Pro 501", 501) {}

    bool checkWinCondition(int currentScore) const override {
        return currentScore == 0; 
    }

    void printRules() const override {
        GameMode::printRules();
        std::cout << "Rule: Pro standard. Must reach exactly 0.\n";
    }

    GameMode* clone() const override {
        return new Game501(*this);
    }
};

class PracticeMode : public GameMode {
private:
    int targetPracticeThrows;
public:
    PracticeMode(int throws) : GameMode("Practice", 0), targetPracticeThrows(throws) {}

    bool checkWinCondition(int currentScore) const override {
        return false;
    }

    void printRules() const override {
        GameMode::printRules();
        std::cout << "Rule: Just hit the board " << targetPracticeThrows << " times.\n";
    }

    GameMode* clone() const override {
        return new PracticeMode(*this);
    }
};