#pragma once
#include "Figure.h"
#include <memory>
#include <cmath>

template <Scalar T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T>> vertex1;
    std::unique_ptr<Point<T>> vertex2;
    std::unique_ptr<Point<T>> vertex3;
    std::unique_ptr<Point<T>> vertex4;

public:
    Rhombus()
        : vertex1(std::make_unique<Point<T>>()),
          vertex2(std::make_unique<Point<T>>()),
          vertex3(std::make_unique<Point<T>>()),
          vertex4(std::make_unique<Point<T>>()) {}

    Rhombus(const Point<T>& v1, const Point<T>& v2, const Point<T>& v3, const Point<T>& v4)
        : vertex1(std::make_unique<Point<T>>(v1)),
          vertex2(std::make_unique<Point<T>>(v2)),
          vertex3(std::make_unique<Point<T>>(v3)),
          vertex4(std::make_unique<Point<T>>(v4)) {}

    double area() const override {
        double d1 = std::sqrt(std::pow(vertex1->x - vertex3->x, 2) + std::pow(vertex1->y - vertex3->y, 2));
        double d2 = std::sqrt(std::pow(vertex2->x - vertex4->x, 2) + std::pow(vertex2->y - vertex4->y, 2));
        return (d1 * d2) / 2.0;
    }

    Point<T> geometricCenter() const override {
        T centerX = (vertex1->x + vertex2->x + vertex3->x + vertex4->x) / static_cast<T>(4);
        T centerY = (vertex1->y + vertex2->y + vertex3->y + vertex4->y) / static_cast<T>(4);
        return Point<T>(centerX, centerY);
    }

    void print() const override {
        std::cout << "Вершины ромба: ";
        vertex1->print(); std::cout << ", ";
        vertex2->print(); std::cout << ", ";
        vertex3->print(); std::cout << ", ";
        vertex4->print(); std::cout << "\n";
        std::cout << "Area: " << area() << "\n";
    }

    void input() {
        std::cout << "Enter vertex 1 (x y): ";
        vertex1->input();
        std::cout << "Enter vertex 2 (x y): ";
        vertex2->input();
        std::cout << "Enter vertex 3 (x y): ";
        vertex3->input();
        std::cout << "Enter vertex 4 (x y): ";
        vertex4->input();
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Rhombus<T>>(*this);
    }

    Rhombus(const Rhombus<T>& other)
        : vertex1(std::make_unique<Point<T>>(*other.vertex1)),
          vertex2(std::make_unique<Point<T>>(*other.vertex2)),
          vertex3(std::make_unique<Point<T>>(*other.vertex3)),
          vertex4(std::make_unique<Point<T>>(*other.vertex4)) {}

    Rhombus(Rhombus<T>&& other) noexcept
        : vertex1(std::move(other.vertex1)),
          vertex2(std::move(other.vertex2)),
          vertex3(std::move(other.vertex3)),
          vertex4(std::move(other.vertex4)) {}

    Rhombus<T>& operator=(const Rhombus<T>& other) {
        if (this != &other) {
            *vertex1 = *other.vertex1;
            *vertex2 = *other.vertex2;
            *vertex3 = *other.vertex3;
            *vertex4 = *other.vertex4;
        }
        return *this;
    }

    Rhombus<T>& operator=(Rhombus<T>&& other) noexcept {
        if (this != &other) {
            vertex1 = std::move(other.vertex1);
            vertex2 = std::move(other.vertex2);
            vertex3 = std::move(other.vertex3);
            vertex4 = std::move(other.vertex4);
        }
        return *this;
    }
};
