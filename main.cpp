#include <iostream>
#include <memory>
#include "Dart.h"
#include "Player.h"
#include "Match.h"
#include "GameFactory.h"
#include "Logger.h"
#include "Templates.h"
#include "Exceptions.h"

using namespace std;

int main() {
    Logger::getInstance().log("Rarts Simulator v0.3 Started");

    cout << "Sageti create in memorie: " << Dart::getTotalDartsCreated() << "\n";
    Dart d1("Red Dragon", 22);
    Dart d2("Winmau", 24);

    cout << "Alege modul de joc:\n";
    cout << "1. Classic 301\n";
    cout << "2. Pro 501\n";
    cout << "3. Practice (Fara limita)\n";
    cout << "4. Around The Clock (Modul nou adaugat)\n";
    cout << "Introdu numarul optiunii: ";

    int optiune;
    cin >> optiune;

    std::unique_ptr<GameMode> selectedMode = GameFactory::createGame(optiune);
    Logger::getInstance().log("Game mode selected: " + selectedMode->getName());

    try {
        Player p1("Phil Taylor", selectedMode->getStartingScore(), d1);
        Player p2("Michael van Gerwen", selectedMode->getStartingScore(), d2);

        Match finalMatch("World Darts Championship", p1, p2, selectedMode.get());
        cout << finalMatch;

        finalMatch.playRound(20, 1);
        finalMatch.playRound(1, 2);

        cout << "\n--- Status curent istoric aruncari ---\n";
        finalMatch.printPlayerHistories();

        cout << "Max throw for P1: " << getMaxValue(p1.getThrowHistory().getData()) << "\n";

        Tracker<std::string> eventTracker;
        eventTracker.add("Bullseye");
        eventTracker.add("Bust");
        eventTracker.add("Double 20");
        eventTracker.printAll("Event Tracker Test");
        cout << "Max alphabetical event: " << getMaxValue(eventTracker.getData()) << "\n";

        finalMatch.playRound(180, 3);

    } catch (const DartsException& e) {
        Logger::getInstance().log(std::string("EXCEPTION CAUGHT: ") + e.what());
        cout << "\n[EROARE JOC] " << e.what() << "\n";
    } catch (const std::exception& e) {
        cout << "\n[EROARE SISTEM] " << e.what() << "\n";
    }

    return 0;
}