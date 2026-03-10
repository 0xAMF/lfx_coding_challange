#pragma once
#include <iostream>

class Square {
public:
    Square(double side) : s(side) {}

    void compute() const {
        std::cout << "Perimeter: " << s * 4 << "\n";
        std::cout << "Area: " << s * s << "\n";
    }

private:
    double s;
};
