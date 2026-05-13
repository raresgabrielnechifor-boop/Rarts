#include <iostream>
#include <memory>
#include "Dart.h"
#include "Player.h"
#include "Match.h"
#include "GameMode.h"
#include "AroundTheClockMode.h"
#include "Exceptions.h"

using namespace std;

int main() {

    Dart d1("Red Dragon", 22);
    Dart d2("Winmau", 24);
    cout << "Darts created: " << Dart::getTotalDartsCreated() << "\n";

    cout << "Choose the GameMode:\n";
    cout << "1. Classic 301\n";
    cout << "2. Pro 501\n";
    cout << "3. Practice (Fara limita)\n";
    cout << "4. Around The Clock (Modul nou adaugat)\n";
    cout << "Number of your choice: ";

    int optiune;
    cin >> optiune;

    std::unique_ptr<GameMode> selectedMode;

    switch (optiune) {
        case 1: selectedMode = std::make_unique<Game301>(); break;
        case 2: selectedMode = std::make_unique<Game501>(); break;
        case 3: selectedMode = std::make_unique<PracticeMode>(); break;
        case 4: selectedMode = std::make_unique<AroundTheClockMode>(); break;
        default:
            cout << "Invalid option! Default: Pro 501.\n";
            selectedMode = std::make_unique<Game501>();
            break;
    }

    try {
        Player p1("Phil Taylor", selectedMode->getStartingScore(), d1);
        Player p2("Michael van Gerwen", selectedMode->getStartingScore(), d2);

        Match finalMatch("World Darts Championship", p1, p2, selectedMode.get());

        cout << finalMatch;

        finalMatch.playRound(20, 1);
        finalMatch.playRound(1, 2);

        cout << "\nThrow History\n";
        finalMatch.printPlayerHistories();

        finalMatch.playRound(180, 3);

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

    return 0;
}