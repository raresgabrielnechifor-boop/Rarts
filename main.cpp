#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int currentScore;

    public:
    Player(string playerName, int initialScore) {
        name = playerName;
        currentScore = initialScore;

    }

    void displayStatus() {
        cout << "Player: " << name << " | Score: " << currentScore << endl;
    }
};
int main()
{
    Player player1("Rares", 301);
    player1.displayStatus();
    return 0;
}
