#include "Match.h"

Match::Match(const std::string& name, const Player& p1, const Player& p2, const GameMode* gameMode)
    : tournamentName(name), player1(p1), player2(p2), mode(gameMode ? gameMode->clone() : nullptr) {}

Match::Match(const Match& other)
    : tournamentName(other.tournamentName), player1(other.player1), player2(other.player2),
      mode(other.mode ? other.mode->clone() : nullptr) {}

void swap(Match& first, Match& second) noexcept {
    using std::swap;
    swap(first.tournamentName, second.tournamentName);
    swap(first.player1, second.player1);
    swap(first.player2, second.player2);
    swap(first.mode, second.mode);
}

Match& Match::operator=(Match other) {
    swap(*this, other);
    return *this;
}

Match::~Match() {
    delete mode;
}

void Match::playRound(int p1Score, int p2Score) {
    std::cout << "\n--- Round Started ---\n";

    if (mode) {
        mode->printRules();

        Game501* isProMode = dynamic_cast<Game501*>(mode);
        if (isProMode) {
            std::cout << ">>> [ALERT] Pro 501 Rules Apply! Double-out required! <<<\n";
        }
    }

    player1.throwDart(p1Score);
    if (player1.hasWon()) {
        std::cout << "\n--- " << player1.getName() << " Wins! ---\n";
        return;
    }

    player2.throwDart(p2Score);
    if (player2.hasWon()) {
        std::cout << "\n--- " << player2.getName() << " Wins! ---\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Match& m) {
    os  <<"\n=== MATCH START: " << m.tournamentName << " ===\n"
        << m.player1 << "\n"
        << m.player2 << "\n";
    if (m.mode) {
        os << "Game Mode: " << m.mode->getName() << "\n";
    }
    os << "====================================\n";
    return os;
}