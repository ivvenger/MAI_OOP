#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

template <Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid(const std::vector<std::unique_ptr<Point<T>>>& vertices) : vertices(vertices) {}

    Trapezoid(const Trapezoid& other) {
        vertices.reserve(other.vertices.size());
        for (const auto& vertex : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(*vertex));
        }
    }

    Trapezoid(Trapezoid&& other) noexcept : vertices(std::move(other.vertices)) {
        other.vertices.clear();
    }

    Trapezoid& operator=(const Trapezoid& other) {
        if (this != &other) {
            vertices.clear();
            vertices.reserve(other.vertices.size());
            for (const auto& vertex : other.vertices) {
                vertices.push_back(std::make_unique<Point<T>>(*vertex));
            }
        }
        return *this;
    }

    Trapezoid& operator=(Trapezoid&& other) noexcept {
        if (this != &other) {
            vertices = std::move(other.vertices);
            other.vertices.clear();
        }
        return *this;
    }

    std::pair<T, T> getGeometricCenter() const override {
        T x = (vertices[0]->getX() + vertices[1]->getX() + vertices[2]->getX() + vertices[3]->getX()) / 4;
        T y = (vertices[0]->getY() + vertices[1]->getY() + vertices[2]->getY() + vertices[3]->getY()) / 4;
        return {x, y};
    }

    T getArea() const override {
        T base1 = std::abs(vertices[1]->getX() - vertices[0]->getX());
        T base2 = std::abs(vertices[3]->getX() - vertices[2]->getX());
        T height = std::abs(vertices[2]->getY() - vertices[0]->getY());
        return (base1 + base2) * height / 2;
    }

    void print(std::ostream& os) const override {
        os << "Трапеция: ";
        for (const auto& vertex : vertices) {
            os << *vertex << " ";
        }
    }

    void read(std::istream& is) override {
        vertices.clear();
        for (size_t i = 0; i < 4; ++i) {
            auto point = std::make_unique<Point<T>>();
            is >> *point;
            vertices.push_back(std::move(point));
        }
    }

private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
};

#endif
