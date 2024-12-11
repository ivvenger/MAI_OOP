#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

template <Scalar T>
class Rhombus : public Figure<T> {
public:
    Rhombus(const std::vector<std::unique_ptr<Point<T>>>& vertices) : vertices(vertices) {}

    // Копирующий конструктор
    Rhombus(const Rhombus& other) {
        vertices.reserve(other.vertices.size());
        for (const auto& vertex : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(*vertex));
        }
    }

    Rhombus(Rhombus&& other) noexcept : vertices(std::move(other.vertices)) {
        other.vertices.clear();
    }

    Rhombus& operator=(const Rhombus& other) {
        if (this != &other) {
            vertices.clear();
            vertices.reserve(other.vertices.size());
            for (const auto& vertex : other.vertices) {
                vertices.push_back(std::make_unique<Point<T>>(*vertex));
            }
        }
        return *this;
    }

    Rhombus& operator=(Rhombus&& other) noexcept {
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
        T d1 = std::sqrt(std::pow(vertices[2]->getX() - vertices[0]->getX(), 2) + std::pow(vertices[2]->getY() - vertices[0]->getY(), 2));
        T d2 = std::sqrt(std::pow(vertices[1]->getX() - vertices[3]->getX(), 2) + std::pow(vertices[1]->getY() - vertices[3]->getY(), 2));
        return d1 * d2 / 2;
    }

    void print(std::ostream& os) const override {
        os << "Ромб: ";
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
