# Shape Calculator (Direct Instantiation)

## What this project does

This program reads a shape name from the command line, parses the numeric arguments, creates a concrete shape object, and prints its perimeter and area. There is no factory or shared interface; `main.cpp` selects the correct class with simple conditionals and then calls `compute()` on the created object.

## Files

- `main.cpp`: Parses input, chooses which shape to instantiate, and triggers the calculation.
- `Circle.hpp`: Concrete `Circle` class with a radius constructor and a `compute()` method.
- `Square.hpp`: Concrete `Square` class with a side constructor and a `compute()` method.
- `Rectangle.hpp`: Concrete `Rectangle` class with side constructors and a `compute()` method.

## Build

```bash
g++ -std=c++11 main.cpp -o describe_object
```

## Run

```bash
./describe_object <shape> [args]
```

Examples:

```bash
./describe_object circle 5
./describe_object square 4
./describe_object rectangle 4 6
```

## Extending

Add a new header with a concrete class and then add another `else if` branch in `main.cpp` to instantiate it and call `compute()`.
