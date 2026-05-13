#include <iostream>
#include "Dart.h"
#include "Player.h"
#include "Match.h"
#include "GameMode.h"
#include "Exceptions.h"

using namespace std;

int main() {
    cout << "Initial Darts: " << Dart::getTotalDartsCreated() << "\n";

    Dart d1("Red Dragon", 22);
    Dart d2("Winmau", 24);

    cout << "Final Darts: " << Dart::getTotalDartsCreated() << "\n\n";

    Player p1("Phil Taylor", 501, d1);
    Player p2("Michael van Gerwen", 501, d2);

    Game501 proMode;
    Match finalMatch("World Darts Championship", p1, p2, &proMode);

    cout << finalMatch;

    try {

        finalMatch.playRound(60, 45);

        finalMatch.playRound(180, 20);

        finalMatch.playRound(20, 20);

    } catch (const InvalidThrowException& e) {
        cout << "\n[GAME ERROR] Game stopped! Reason: " << e.what() << "\n";
    } catch (const DartsException& e) {
        cout << "\n[GENERAL ERROR] " << e.what() << "\n";
    } catch (const std::exception& e) {
        cout << "\n[SYSTEM ERROR] " << e.what() << "\n";
    }

    cout << "\nGAME OVER!\n";

    return 0;
}