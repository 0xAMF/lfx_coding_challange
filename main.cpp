#include "ShapeFactory.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    if (argc < 2) {
	std::cout << "usage: ./describe_object <shape> [args]" << std::endl; }

    std::string shape_name = argv[1];
    auto shape = ShapeFactory::create(shape_name);

    if (!shape) {
	std::cout << "shape not found" << std::endl;
	return 1;
    }

    if (argc - 2 < shape->requiredArgs()) {
	std::cout << "provide suitable arguments for the shape" << std::endl;
    }

    std::vector<double> args;
    for (int i = 2; i < argc; ++i) {
	// convert string argument input to double and push into the args vector
	args.push_back(std::stod(argv[i]));
    }

    // calculate shape attributes based on the arguments vector
    shape->compute(args);

    return 0;
}
