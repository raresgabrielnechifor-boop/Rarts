#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Tracker {
private:
    std::vector<T> data;
public:
    void add(const T& item) {
        data.push_back(item);
    }

    void printAll(const std::string& title) const {
        std::cout << "--- " << title << " ---\n";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }

    const std::vector<T>& getData() const {
        return data;
    }
    
    int getSize() const {
        return data.size();
    }
};

template <typename T>
T getMaxValue(const std::vector<T>& vec) {
    if (vec.empty()) {
        throw std::runtime_error("Vector is empty, cannot find max!");
    }
    T maxVal = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > maxVal) {
            maxVal = vec[i];
        }
    }
    return maxVal;
}