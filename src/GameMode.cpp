#include "GameMode.h"

GameMode::GameMode(const std::string& name, int score) : modeName(name), startingScore(score) {}
void GameMode::printDetails(std::ostream& os) const { os << "Playing: " << modeName << " | Start: " << startingScore; }
void GameMode::printRules() const { std::cout << *this << "\n"; }
int GameMode::getStartingScore() const { return startingScore; }
std::string GameMode::getName() const { return modeName; }
std::ostream& operator<<(std::ostream& os, const GameMode& gm) { gm.printDetails(os); return os; }

Game301::Game301() : GameMode("Classic 301", 301) {}
int Game301::processThrow(int currentScore, int pointsScored) const { return (currentScore - pointsScored < 0) ? currentScore : currentScore - pointsScored; }
bool Game301::checkWinCondition(int currentScore) const { return currentScore == 0; }
void Game301::printRules() const { GameMode::printRules(); std::cout << "Rule: Reach exactly 0. Bust applies.\n"; }
GameMode* Game301::clone() const { return new Game301(*this); }

Game501::Game501() : GameMode("Pro 501", 501) {}
int Game501::processThrow(int currentScore, int pointsScored) const { return (currentScore - pointsScored < 0) ? currentScore : currentScore - pointsScored; }
bool Game501::checkWinCondition(int currentScore) const { return currentScore == 0; }
void Game501::printRules() const { GameMode::printRules(); std::cout << "Rule: Pro standard. Reach exactly 0.\n"; }
GameMode* Game501::clone() const { return new Game501(*this); }

PracticeMode::PracticeMode() : GameMode("Practice", 0) {}
int PracticeMode::processThrow(int currentScore, int pointsScored) const { return currentScore + pointsScored; }
bool PracticeMode::checkWinCondition const { return false; }
void PracticeMode::printRules() const { GameMode::printRules(); std::cout << "Rule: Just accumulate points.\n"; }
GameMode* PracticeMode::clone() const { return new PracticeMode(*this); }