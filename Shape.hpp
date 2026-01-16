#pragma once
#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;

    virtual std::string name() const = 0;
    virtual int requiredArgs() const = 0;
    virtual void compute(const std::vector<double>& args) const = 0;
};
