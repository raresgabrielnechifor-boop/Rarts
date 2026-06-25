#include "Match.h"
#include "GameMode.h"
#include "Exceptions.h"
#include <utility>
#include "Game501.h"

Match::Match(const std::string& name, const Player& p1, const Player& p2, const GameMode* gameMode)
    : tournamentName(name), player1(p1), player2(p2) {
    if (gameMode == nullptr) {
        throw InvalidMatchConfigException("GameMode pointer is null! A match must have a game mode.");
    }
    mode = gameMode->clone();
}

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

        const Game501* isProMode = dynamic_cast<Game501*>(mode);
        if (isProMode) {
            std::cout << ">>> [ALERT] Pro 501 Active! No mistakes allowed! <<<\n";
        }
    }

    player1.throwDart(p1Score, mode);

    if (mode && mode->checkWinCondition(player1.getCurrentScore())) {
        std::cout << "\n--- " << player1.getName() << " Wins! ---\n";
        return;
    }

    player2.throwDart(p2Score, mode);

    if (mode && mode->checkWinCondition(player2.getCurrentScore())) {
        std::cout << "\n--- " << player2.getName() << " Wins! ---\n";
    }
}
void Match::printPlayerHistories() const {
    player1.printHistory();
    player2.printHistory();
}
std::ostream& operator<<(std::ostream& os, const Match& m) {
    os << "\n=== MATCH START: " << m.tournamentName << " ===\n"
       << m.player1 << "\n"
       << m.player2 << "\n";

    if (m.mode) {
        os << "Current Mode: " << *(m.mode) << "\n";
    }

    os << "====================================\n";
    return os;
}