#pragma once
#include "Figure.h"
#include <memory>
#include <cmath>

template <Scalar T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> topLeft;
    std::unique_ptr<Point<T>> topRight;
    std::unique_ptr<Point<T>> bottomRight;
    std::unique_ptr<Point<T>> bottomLeft;

public:
    Trapezoid()
        : topLeft(std::make_unique<Point<T>>()),
          topRight(std::make_unique<Point<T>>()),
          bottomRight(std::make_unique<Point<T>>()),
          bottomLeft(std::make_unique<Point<T>>()) {}

    Trapezoid(const Point<T>& tl, const Point<T>& tr, const Point<T>& br, const Point<T>& bl)
        : topLeft(std::make_unique<Point<T>>(tl)),
          topRight(std::make_unique<Point<T>>(tr)),
          bottomRight(std::make_unique<Point<T>>(br)),
          bottomLeft(std::make_unique<Point<T>>(bl)) {}

    double area() const override {
        T a = topRight->x - topLeft->x;
        T b = bottomRight->x - bottomLeft->x;
        T h = topLeft->y - bottomLeft->y;
        return static_cast<double>((a + b) * h / 2);
    }

    Point<T> geometricCenter() const override {
        T centerX = (topLeft->x + topRight->x + bottomRight->x + bottomLeft->x) / static_cast<T>(4);
        T centerY = (topLeft->y + topRight->y + bottomRight->y + bottomLeft->y) / static_cast<T>(4);
        return Point<T>(centerX, centerY);
    }

    void print() const override {
        std::cout << "Вершины трапеции: ";
        topLeft->print(); std::cout << ", ";
        topRight->print(); std::cout << ", ";
        bottomRight->print(); std::cout << ", ";
        bottomLeft->print(); std::cout << "\n";
        std::cout << "Area: " << area() << "\n";
    }

    void input() {
        std::cout << "Enter top-left point (x y): ";
        topLeft->input();
        std::cout << "Enter top-right point (x y): ";
        topRight->input();
        std::cout << "Enter bottom-right point (x y): ";
        bottomRight->input();
        std::cout << "Enter bottom-left point (x y): ";
        bottomLeft->input();
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Trapezoid<T>>(*this);
    }

    Trapezoid(const Trapezoid<T>& other)
        : topLeft(std::make_unique<Point<T>>(*other.topLeft)),
          topRight(std::make_unique<Point<T>>(*other.topRight)),
          bottomRight(std::make_unique<Point<T>>(*other.bottomRight)),
          bottomLeft(std::make_unique<Point<T>>(*other.bottomLeft)) {}

    Trapezoid(Trapezoid<T>&& other) noexcept
        : topLeft(std::move(other.topLeft)),
          topRight(std::move(other.topRight)),
          bottomRight(std::move(other.bottomRight)),
          bottomLeft(std::move(other.bottomLeft)) {}

    Trapezoid<T>& operator=(const Trapezoid<T>& other) {
        if (this != &other) {
            *topLeft = *other.topLeft;
            *topRight = *other.topRight;
            *bottomRight = *other.bottomRight;
            *bottomLeft = *other.bottomLeft;
        }
        return *this;
    }

    Trapezoid<T>& operator=(Trapezoid<T>&& other) noexcept {
        if (this != &other) {
            topLeft = std::move(other.topLeft);
            topRight = std::move(other.topRight);
            bottomRight = std::move(other.bottomRight);
            bottomLeft = std::move(other.bottomLeft);
        }
        return *this;
    }
};
