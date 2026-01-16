#pragma once
#include "ShapeFactory.hpp"
#include <iostream>
#include <memory>

class Square : public Shape {
public:
    std::string name() const override {
	return "square";
    }

    int requiredArgs() const override {
	return 1;
    }

    void compute(const std::vector<double>& args) const override {
	double side = args[0];
	std::cout << "Perimeter: " << side * 4 << std::endl;
	std::cout << "Area: " << side * side << std::endl;
    }

};

bool squareRegistered = []() {
    ShapeFactory::registerType("square", []() {
	return std::make_unique<Square>();
    });
    return true;
}();
