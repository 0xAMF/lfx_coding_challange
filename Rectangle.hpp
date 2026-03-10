#pragma once
#include <iostream>

class Rectangle {
public:
    Rectangle(double side1, double side2) : side1(side1), side2(side2) {}

    void compute() const {
        std::cout << "Perimeter: " << (side1 + side2) * 2 << "\n";
        std::cout << "Area: " << side1 * side2 << "\n";
    }

private:
    double side1;
    double side2;
};
