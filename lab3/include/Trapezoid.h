#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid(double base1 = 0, double base2 = 0, double height = 0) : base1(base1), base2(base2), height(height) {}

    void calculate_geometric_center() const override {
        double x = (base1 + 2 * base2) / 3;
        double y = height / 3;
        std::cout << "Geometric center of Trapezoid: (" << x << ", " << y << ")\n";
    }

    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trap) {
        os << "Trapezoid: base1 = " << trap.base1 << ", base2 = " << trap.base2 << ", height = " << trap.height;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Trapezoid& trap) {
        is >> trap.base1 >> trap.base2 >> trap.height;
        return is;
    }

    Trapezoid* clone() const override {
        return new Trapezoid(*this);
    }

    bool operator==(const Figure& other) const override {
        const Trapezoid* otherTrap = dynamic_cast<const Trapezoid*>(&other);
        return otherTrap && base1 == otherTrap->base1 && base2 == otherTrap->base2 && height == otherTrap->height;
    }

private:
    double base1;
    double base2;
    double height;
};

#endif
