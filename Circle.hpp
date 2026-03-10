#pragma once
#include <cmath>
#include <iostream>

class Circle {
public:
    Circle(double radius) : r(radius) {}

    void compute() const {
        std::cout << "Circumference: " << 2 * M_PI * r << "\n";
        std::cout << "Area: " << M_PI * r * r << "\n";
    }

private:
    double r;
};
