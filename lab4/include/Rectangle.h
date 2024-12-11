#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

template <Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle(const std::vector<std::unique_ptr<Point<T>>>& vertices) : vertices(vertices) {}

    Rectangle(const Rectangle& other) {
        vertices.reserve(other.vertices.size());
        for (const auto& vertex : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(*vertex));
        }
    }

    Rectangle(Rectangle&& other) noexcept : vertices(std::move(other.vertices)) {
        other.vertices.clear();
    }

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            vertices.clear();
            vertices.reserve(other.vertices.size());
            for (const auto& vertex : other.vertices) {
                vertices.push_back(std::make_unique<Point<T>>(*vertex));
            }
        }
        return *this;
    }

    Rectangle& operator=(Rectangle&& other) noexcept {
        if (this != &other) {
            vertices = std::move(other.vertices);
            other.vertices.clear();
        }
        return *this;
    }

    std::pair<T, T> getGeometricCenter() const override {
        T x = (vertices[0]->getX() + vertices[2]->getX()) / 2;
        T y = (vertices[0]->getY() + vertices[2]->getY()) / 2;
        return {x, y};
    }

    T getArea() const override {
        T width = std::abs(vertices[1]->getX() - vertices[0]->getX());
        T height = std::abs(vertices[2]->getY() - vertices[0]->getY());
        return width * height;
    }

    void print(std::ostream& os) const override {
        os << "прямоугольник: ";
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
