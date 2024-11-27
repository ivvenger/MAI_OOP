#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus(double side = 0, double height = 0) : side(side), height(height) {}

    void calculate_geometric_center() const override {
        std::cout << "Geometric center of Rhombus: (" << side / 2 << ", " << height / 2 << ")\n";
    }

    double area() const override {
        return side * height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhomb) {
        os << "Rhombus: side = " << rhomb.side << ", height = " << rhomb.height;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rhombus& rhomb) {
        is >> rhomb.side >> rhomb.height;
        return is;
    }

    Rhombus* clone() const override {
        return new Rhombus(*this);
    }

    bool operator==(const Figure& other) const override {
        const Rhombus* otherRhomb = dynamic_cast<const Rhombus*>(&other);
        return otherRhomb && side == otherRhomb->side && height == otherRhomb->height;
    }

private:
    double side;
    double height;
};

#endif
