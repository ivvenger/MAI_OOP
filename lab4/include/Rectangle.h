#pragma once
#include "Figure.h"
#include <memory>
#include <cmath>

template <Scalar T>
class Rectangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> topLeft;
    std::unique_ptr<Point<T>> topRight;
    std::unique_ptr<Point<T>> bottomRight;
    std::unique_ptr<Point<T>> bottomLeft;

public:
    Rectangle()
        : topLeft(std::make_unique<Point<T>>()),
          topRight(std::make_unique<Point<T>>()),
          bottomRight(std::make_unique<Point<T>>()),
          bottomLeft(std::make_unique<Point<T>>()) {}

    Rectangle(const Point<T>& tl, const Point<T>& tr, const Point<T>& br, const Point<T>& bl)
        : topLeft(std::make_unique<Point<T>>(tl)),
          topRight(std::make_unique<Point<T>>(tr)),
          bottomRight(std::make_unique<Point<T>>(br)),
          bottomLeft(std::make_unique<Point<T>>(bl)) {}

    double area() const override {
        T width = topRight->x - topLeft->x;
        T height = topLeft->y - bottomLeft->y;
        return static_cast<double>(std::abs(width * height));
    }

    Point<T> geometricCenter() const override {
        T centerX = (topLeft->x + topRight->x + bottomRight->x + bottomLeft->x) / static_cast<T>(4);
        T centerY = (topLeft->y + topRight->y + bottomRight->y + bottomLeft->y) / static_cast<T>(4);
        return Point<T>(centerX, centerY);
    }

    void print() const override {
        std::cout << "Вершины прямоугольника: ";
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
        return std::make_unique<Rectangle<T>>(*this);
    }
    Rectangle(const Rectangle<T>& other)
        : topLeft(std::make_unique<Point<T>>(*other.topLeft)),
          topRight(std::make_unique<Point<T>>(*other.topRight)),
          bottomRight(std::make_unique<Point<T>>(*other.bottomRight)),
          bottomLeft(std::make_unique<Point<T>>(*other.bottomLeft)) {}

    Rectangle(Rectangle<T>&& other) noexcept
        : topLeft(std::move(other.topLeft)),
          topRight(std::move(other.topRight)),
          bottomRight(std::move(other.bottomRight)),
          bottomLeft(std::move(other.bottomLeft)) {}

    Rectangle<T>& operator=(const Rectangle<T>& other) {
        if (this != &other) {
            *topLeft = *other.topLeft;
            *topRight = *other.topRight;
            *bottomRight = *other.bottomRight;
            *bottomLeft = *other.bottomLeft;
        }
        return *this;
    }

    Rectangle<T>& operator=(Rectangle<T>&& other) noexcept {
        if (this != &other) {
            topLeft = std::move(other.topLeft);
            topRight = std::move(other.topRight);
            bottomRight = std::move(other.bottomRight);
            bottomLeft = std::move(other.bottomLeft);
        }
        return *this;
    }
};
