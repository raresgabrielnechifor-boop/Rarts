#include "Dart.h"

int Dart::totalDartsCreated = 0;

Dart::Dart(const std::string& dartBrand, int dartWeight) : brand(dartBrand), weight(dartWeight) {
    totalDartsCreated++;
}

Dart::Dart() : brand("Unknown"), weight(0) {
    totalDartsCreated++;
}

int Dart::getTotalDartsCreated() {
    return totalDartsCreated;
}

std::ostream& operator<<(std::ostream &os, const Dart &d) {
    os << "Dart: " << d.brand << "(" << d.weight << " g)";
    return os;
}