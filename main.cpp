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
    void displayDart() {
        cout << "Dart: " << brand << " (" << weight << " g)" << endl;
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

    void displayStatus() {
        cout << "Player: " << name << " | Score: " << currentScore << endl;
        myDart.displayDart();
    }
};
int main()
{
    Dart redDragon ("Red Dragon", 22);
    Player player1("Rares", 301 , redDragon);
    player1.displayStatus();
    return 0;
}
