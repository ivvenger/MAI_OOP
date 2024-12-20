#pragma once
#include "scalar.h"
#include <iostream>

template <Scalar T>
class Point {
public:
    T x;
    T y;

    Point() : x(0), y(0) {}
    Point(T x_val, T y_val) : x(x_val), y(y_val) {}
    void input() {
        std::cin >> x >> y;
    }
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    bool operator==(const Point<T>& other) const {
        return (x == other.x) && (y == other.y);
    }
};
