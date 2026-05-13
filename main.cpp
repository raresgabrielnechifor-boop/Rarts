#include <iostream>
#include "Dart.h"
#include "Player.h"
#include "Match.h"
#include "GameMode.h"
#include "AroundTheClockMode.h"
#include "Exceptions.h"

using namespace std;

int main() {

    cout << "Initial Darts: " << Dart::getTotalDartsCreated() << "\n";

    Dart d1("Red Dragon", 22);
    Dart d2("Winmau", 24);

    cout << "Final Darts: " << Dart::getTotalDartsCreated() << "\n\n";

    AroundTheClockMode clockMode;

    try {
        Player p1("Phil Taylor", clockMode.getStartingScore(), d1);
        Player p2("Michael van Gerwen", clockMode.getStartingScore(), d2);

        Match finalMatch("World Darts Championship", p1, p2, &clockMode);

        cout << finalMatch;

        finalMatch.playRound(20, 1);

        finalMatch.playRound(1, 2);

        cout << "\nThrow history\n";
        finalMatch.printPlayerHistories();

        finalMatch.playRound(180, 3);

        finalMatch.playRound(2, 3);

    } catch (const PlayerNotFoundException& e) {
        cout << "\n[PLAYER ERROR] " << e.what() << "\n";
    } catch (const InvalidMatchConfigException& e) {
        cout << "\n[CONFIGURATION ERROR] " << e.what() << "\n";
    } catch (const InvalidThrowException& e) {
        cout << "\n[GAME ERROR] GAME STOPPED: " << e.what() << "\n";
    } catch (const DartsException& e) {
        cout << "\n[GENERAL ERROR] " << e.what() << "\n";
    } catch (const std::exception& e) {
        cout << "\n[SYSTEM ERROR] " << e.what() << "\n";
    }

    cout << "\nGAME OVER!\n";

    return 0;
}