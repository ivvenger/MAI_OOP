#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle(double width = 0, double height = 0) : width(width), height(height) {}

    void calculate_geometric_center() const override {
        std::cout << "Geometric center of Rectangle: (" << width / 2 << ", " << height / 2 << ")\n";
    }

    double area() const override {
        return width * height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
        os << "Rectangle: width = " << rect.width << ", height = " << rect.height;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rectangle& rect) {
        is >> rect.width >> rect.height;
        return is;
    }

    Rectangle* clone() const override {
        return new Rectangle(*this);
    }

    bool operator==(const Figure& other) const override {
        const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
        return otherRect && width == otherRect->width && height == otherRect->height;
    }

private:
    double width;
    double height;
};

#endif
