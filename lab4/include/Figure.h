#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <memory>
#include <vector>
#include "Point.h"

template <Scalar T>

class Figure {
public:
    virtual ~Figure() = default;
    virtual std::pair<T, T> getGeometricCenter() const = 0;
    virtual T getArea() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    operator double() const {
        return static_cast<double>(getArea());
    }

    Figure& operator=(const Figure& other) {
        if (this != &other) {
            vertices.clear();
            for (const auto& vertex : other.vertices) {
                vertices.push_back(std::make_unique<Point<T>>(*vertex));
            }
        }
        return *this;
    }

    Figure& operator=(Figure&& other) noexcept {
        if (this != &other) {
            if (this != &other) {
                vertices = std::move(other.vertices);
                other.vertices.clear();
            }
        }
        return *this;
    }

    bool operator==(const Figure& other) const {
        return getArea() == other.getArea();
    }
};

#endif
