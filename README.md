# Coding Challange: Shape Factory Method

## Code Structure

- **`main.cpp`**: The main entry point of the application. It parses command-line arguments, uses the `ShapeFactory` to create a shape, and then calls its `compute` method.
- **`Shape.hpp`**: Defines the `Shape` abstract base class, which acts as an interface for all concrete shape classes.
- **`ShapeFactory.hpp`**: Implements the `ShapeFactory`, which is responsible for registering and creating shape objects.
- **`Circle.hpp`**, **`Rectangle.hpp`**, **`Square.hpp`**: These files define the concrete shape classes (`Circle`, `Rectangle`, `Square`). Each of these classes inherits from `Shape` and implements its virtual functions. They also self-register with the `ShapeFactory`.

## Usage

### Compilation

```bash
g++ -std=c++11 main.cpp -o describe_object
```

### Running the application

To use the program, run the compiled executable with the name of the shape as the first argument, followed by the required dimensions.

```bash
./describe_object <shape> [args]
```

**Examples:**

- **Circle** (requires 1 argument: radius)
  ```bash
  ./describe_object circle 5
  ```

- **Rectangle** (requires 2 arguments: side1, side2)
  ```bash
  ./describe_object rectangle 4 6
  ```

- **Square** (requires 1 argument: side)
  ```bash
  ./describe_object square 4
  ```

## How it Works

The project is built around the Factory design pattern to decouple the object creation logic from the client (the `main` function).
This is one way to abstract the type of objects in `main` functions, so it has no prior knowledge of what type of objects are being created.

- **`ShapeFactory`**: This class contains a static registry (a map) that stores "creator" functions for each shape. The key is the shape's name (e.g., "circle"), and the value is a lambda function that returns a `std::unique_ptr<Shape>` to a new instance of that shape.
- **Self-Registration**: Each concrete shape class (e.g., `Circle`) has a static boolean variable that is initialized by a lambda function. This lambda calls `ShapeFactory::registerType` to register the shape's name and its creation function. This ensures that all shapes are automatically registered before `main` is executed (each class `.hpp` have to be included of course, so the expression gets evaluated).

## Extending with New Shapes

To add a new shape, you need to:

1.  **Create a new header file** for your shape (e.g., `Triangle.hpp`).
2.  **Define the new shape class** that inherits from `Shape` and implements its pure virtual functions (`name`, `requiredArgs`, `compute`).
3.  **Register the new shape** with the `ShapeFactory` using the self-registration mechanism.

Here is an example of how to add a `Triangle` shape:

**`Triangle.hpp`**
```cpp
#pragma once
#include "ShapeFactory.hpp"
#include <iostream>
#include <memory>
#include <cmath>

class Triangle : public Shape {
public:
    std::string name() const override {
        return "triangle";
    }

    int requiredArgs() const override {
        return 3; // a, b, c
    }

    void compute(const std::vector<double>& args) const override {
        // compute logic...
    }
};

// Self-register the Triangle shape
bool triangleRegistered = []() {
    ShapeFactory::registerType("triangle", []() {
        return std::make_unique<Triangle>();
    });
    return true;
}();
```

Finally, include the new header in `main.cpp`:
```cpp
#include "Triangle.hpp"
```

Now, you can compile and run the program with the new `triangle` shape.
