#include "Player.h"
#include "Exceptions.h"
#include "GameMode.h"

Player::Player(const std::string& playerName, int initialScore, const Dart& playerDart)
    : name(playerName), currentScore(initialScore), myDart(playerDart) {
    if (playerName.empty() || playerName == " ") {
        throw PlayerNotFoundException(playerName);
    }
}

Player::Player() : name("Unknown"), currentScore(0) {}

Player::Player(const Player& other)
    : name(other.name), currentScore(other.currentScore), myDart(other.myDart), throwHistory(other.throwHistory) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        currentScore = other.currentScore;
        myDart = other.myDart;
        throwHistory = other.throwHistory;
    }
    return *this;
}

Player::~Player() {}

bool Player::throwDart(int pointsScored, const GameMode* mode) {
    if (pointsScored < 0 || pointsScored > 60) {
        throw InvalidThrowException(pointsScored);
    }

    throwHistory.add(pointsScored);

    std::cout << name << " throws for " << pointsScored << "...\n";

    int newScore = mode ? mode->processThrow(currentScore, pointsScored) : currentScore;

    if (newScore == currentScore && pointsScored != 0) {
        std::cout << "  -> BUST or MISSED TARGET! Score/Target remains: " << currentScore << ".\n";
        return false;
    } else {
        currentScore = newScore;
        std::cout << "  -> Good throw! New Score/Target: " << currentScore << ".\n";
        return true;
    }
}

const std::string& Player::getName() const {
    return name;
}

void Player::printHistory() const {
    throwHistory.printAll(name + "'s throw history");
}

std::ostream& operator<<(std::ostream& os, const Player& p) {
    os << "Player: " << p.name << " | Score/Target: " << p.currentScore
       << " | Throws made: " << p.throwHistory.getSize() << " | " << p.myDart;
    return os;
}