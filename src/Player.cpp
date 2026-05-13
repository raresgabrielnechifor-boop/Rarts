#include "Player.h"
#include "Exceptions.h"

Player::Player(const std::string& playerName, int initialScore, const Dart& playerDart)
    : name(playerName), currentScore(initialScore), myDart(playerDart) {}

Player::Player() : name("Unknown"), currentScore(0) {}

Player::Player(const Player& other) 
    : name(other.name), currentScore(other.currentScore), myDart(other.myDart) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        currentScore = other.currentScore;
        myDart = other.myDart;
    }
    return *this;
}

Player::~Player() {}

bool Player::throwDart(int pointsScored) {
    if (pointsScored < 0 || pointsScored > 60) {
        throw InvalidThrowException(pointsScored);
    }

    std::cout << name << " throws for " << pointsScored << " points...\n";

    if (currentScore - pointsScored < 0) {
        std::cout << "  -> BUST! Score remains: " << currentScore << ".\n";
        return false;
    } else {
        currentScore -= pointsScored;
        std::cout << "  -> Good throw! Remaining score: " << currentScore << ".\n";
        return true;
    }
}

bool Player::hasWon() const {
    return currentScore == 0;
}

const std::string& Player::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Player& p) {
    os << "Player: " << p.name << " | Score: " << p.currentScore << " | " << p.myDart;
    return os;
}