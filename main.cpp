#include <iostream>
#include <string>

using namespace std;

class Dart {
private:
    string brand;
    int weight;

public:
    Dart (string dartBrand, int dartWeight) {
        brand = dartBrand;
        weight = dartWeight;
    }
    Dart() {
        brand = "Unknown";
        weight = 0;
    }
    friend ostream& operator<<(ostream &os, const Dart &d) {
        os << "Dart: "<< d.brand << "(" << d.weight << " g)";
        return os;
    }
};

class Player {
private:
    string name;
    int currentScore;
    Dart myDart;

    public:
    Player(string playerName, int initialScore, Dart playerDart) {
        name = playerName;
        currentScore = initialScore;
        myDart = playerDart;

    }

    bool throwDart (int pointsScored) {
        cout << name << " throws for " << pointsScored << " points...\n";

        if (currentScore -pointsScored < 0) {
            cout << "  -> BUST! Score remains: "<< currentScore << ".\n";
            return false;
        }

        else {
            currentScore -= pointsScored;
            cout << "  -> Good throw! Remaining score: " << currentScore << ".\n";
            return true;
        }
    }

    bool hasWon() const {
        return currentScore == 0;
    }

    string getName() const {
        return name;
    }

    friend ostream& operator<<(ostream& os, const Player& p) {
        os << "Player: " << p.name <<" | Score: "<< p.currentScore << " | " << p.myDart;
        return os;
    }
    Player() {
        name = "Unknown";
        currentScore = 0;
    }
};

class Match {
private:
    string tournamentName;
    Player player1;
    Player player2;

public:
    Match (string name, Player p1, Player p2) {
        tournamentName = name;
        player1 = p1;
        player2 = p2;
    }

    void playRound (int p1Score, int p2Score) {
        cout << "\n--- Round Started ---\n";

        player1.throwDart(p1Score);
        if (player1.hasWon()) {
            cout << "\n---" << player1.getName()<< " Wins! ---\n";
            return;
        }

        player2.throwDart(p2Score);
        if (player2.hasWon()) {
            cout << "\n--- " << player2.getName()<< " Wins! ---\n";
        }
    }
    friend ostream& operator<<(ostream& os, const Match& m) {
        os  <<"\n=== MATCH START: " << m.tournamentName << " ===\n"
            << m.player1 << "\n"
            << m.player2 << "\n"
            << "====================================\n";
        return os;
    }
};

int main()
{
    Dart redDragon ("Red Dragon", 22);
    Dart winmau ("Winmau", 23);

    Player player1("Rares", 50 , redDragon);
    Player player2("Iarina", 50 , winmau);

    Match finala("Campiontaul Mondial de Darts", player1, player2);
    cout << finala;

    finala.playRound(20, 45);
    cout << finala;

    finala.playRound(40, 5);
    cout << finala;

    return 0;
}
