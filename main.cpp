#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "usage: ./describe_object <shape> [args]\n";
        return 1;
    }

    std::string shape = argv[1];
    std::vector<double> args;
    for (int i = 2; i < argc; ++i) {
        args.push_back(std::atof(argv[i]));
    }

    if (shape == "circle") {
        if (args.size() < 1) {
            std::cout << "circle needs 1 argument (radius)\n";
            return 1;
        }
        Circle c(args[0]);
        c.compute();
    } else if (shape == "square") {
        if (args.size() < 1) {
            std::cout << "square needs 1 argument (side)\n";
            return 1;
        }
        Square s(args[0]);
        s.compute();
    } else if (shape == "rectangle") {
        if (args.size() < 2) {
            std::cout << "rectangle needs 2 arguments (side1 side2)\n";
            return 1;
        }
        Rectangle r(args[0], args[1]);
        r.compute();
    } else {
        std::cout << "unknown shape\n";
        return 1;
    }

    return 0;
}
