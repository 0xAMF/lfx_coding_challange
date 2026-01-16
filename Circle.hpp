#pragma once
#include "ShapeFactory.hpp"
#include <cmath>
#include <iostream>
#include <memory>

class Circle: public Shape {
public:
    std::string name() const override {
	return "Circle";
    }

    int requiredArgs() const override {
	return 1;
    }

    void compute(const std::vector<double>& args) const override {
	double r = args[0];

	std::cout << "Circumference: " << 2 * M_PI * r << std::endl; 
	std::cout << "Area: " << M_PI * r * r << std::endl; 
    }
};

bool circleRegistered = []() {
    ShapeFactory::registerType("circle", []() {
	return std::make_unique<Circle>();
    });
    return true;
}();
