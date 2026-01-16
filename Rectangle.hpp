#include "ShapeFactory.hpp"
#include <iostream>

class Rectangle : public Shape {
public:
    std::string name() const override {
	return "rectangle";
    }

    int requiredArgs() const override {
	return 2;
    }

    void compute(const std::vector<double>& args) const override {
	double side1 = args[0];
	double side2 = args[1];
	std::cout << "Perimeter: " << (side1 + side2) * 2 << std::endl;
	std::cout << "Area: " << side1 * side2 << std::endl;
    }
};

bool rectangleRegistered = []() {
    ShapeFactory::registerType("rectangle", []() {
	return std::make_unique<Rectangle>();
    });
    return true;
}();
