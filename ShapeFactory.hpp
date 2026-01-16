#pragma once
#include "Shape.hpp"
#include <map>
#include <functional>
#include <memory>
#include <string>

class ShapeFactory {
public:
    // function pointer type that returns a unque pointer to shape object
    using Creator = std::function<std::unique_ptr<Shape>()>;

    // register new types with ID as shape name (circle, square, ...,etc) and a creation function
    // this function will called inside the child with a constructor of the child type in the child class
    static void registerType(const std::string& id, Creator creator) {
	getRegistry()[id] = creator;
    }
    // the create function, returns a unique pointer to the child we created
    // we create the object through the map we have built 
    // static of course to have one static object of the factory class, because we need the registry map.
    static std::unique_ptr<Shape> create(const std::string& id) {
	auto it = getRegistry().find(id);
	if (it != getRegistry().end()) {
	    return it->second(); // call the creator function
	}

	return nullptr;
    }

private:
    // internal map to store creators for different child types
    static std::map<std::string, Creator>& getRegistry() {
	static std::map<std::string, Creator> registry;
	return registry;
    }
};
