#include <iostream>
#include <string>

using namespace std;

class Dart {
private:
    string brand;
    int weight;

public:
    Dart (const string& dartBrand, int dartWeight) : brand(dartBrand), weight(dartWeight) {}
    Dart() : brand("Unknown"), weight(0) {}

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

    Player(const string& playerName, int initialScore, const Dart& playerDart):
        name(playerName), currentScore(initialScore), myDart(playerDart) {}
    Player() : name("Unknown"), currentScore(0) {}

    Player(const Player& other) : name(other.name), currentScore(other.currentScore), myDart(other.myDart) {}

    Player& operator= (const Player& other) {
        if (this != &other) {
            name = other.name;
            currentScore = other.currentScore;
            myDart = other.myDart;
        }
        return *this;
    }

    ~Player() {}

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
};

class Match {
private:
    string tournamentName;
    Player player1;
    Player player2;

public:
    Match (const string& name, const Player& p1, const Player& p2):
        tournamentName(name), player1(p1), player2(p2) {}

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
    string name1, name2;
    int startScore;

    cout << "--- Match settings ---\n";
    cout << "Enter starting score: ";
    cin >> startScore;

    cout << "Enter name of player 1: ";
    cin >> name1;

    cout << "Enter name of player 2: ";
    cin >> name2;

    cout<< "\nGenerating Match...\n";

    Dart d1 ("Red Dragon", 22);
    Dart d2 ("Winmau", 23);

    Player player1 (name1, startScore, d1);
    Player player2 (name2, startScore, d2);

    Match finalMatch("Local Darts Championship", player1, player2);
    cout <<finalMatch;

    finalMatch.playRound(45, 60);
    cout <<finalMatch;

    finalMatch.playRound(40, 30);
    cout <<finalMatch;

    finalMatch.playRound(100, 80);
    cout <<finalMatch;

    finalMatch.playRound(116, 120);
    cout <<finalMatch;
    return 0;
}
