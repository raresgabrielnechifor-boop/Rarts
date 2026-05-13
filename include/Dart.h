#pragma once
#include <string>
#include <iostream>

class Dart {
private:
    std::string brand;
    int weight;

    static int totalDartsCreated; 

public:
    Dart(const std::string& dartBrand, int dartWeight);
    Dart();

    static int getTotalDartsCreated();

    friend std::ostream& operator<<(std::ostream &os, const Dart &d);
};