#pragma once
#include "scalar.h"
#include "Point.h"
#include <memory>

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual Point<T> geometricCenter() const = 0;
    virtual void print() const = 0;
    virtual std::unique_ptr<Figure<T>> clone() const = 0;

    bool operator==(const Figure<T>& other) const {
        return this->area() == other.area();
    }

    explicit operator double() const {
        return area();
    }
};
