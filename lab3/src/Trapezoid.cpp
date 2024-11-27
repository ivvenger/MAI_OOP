#include "../include/Trapezoid.h"

void Trapezoid::calculate_geometric_center() const {
    double x = (base1 + 2 * base2) / 3;
    double y = height / 3;
    std::cout << "Geometric center of Trapezoid: (" << x << ", " << y << ")\n";
}

double Trapezoid::area() const {
    return 0.5 * (base1 + base2) * height;
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trap) {
    os << "Trapezoid: base1 = " << trap.base1 << ", base2 = " << trap.base2 << ", height = " << trap.height;
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trap) {
    is >> trap.base1 >> trap.base2 >> trap.height;
    return is;
}

Trapezoid* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* otherTrap = dynamic_cast<const Trapezoid*>(&other);
    return otherTrap && base1 == otherTrap->base1 && base2 == otherTrap->base2 && height == otherTrap->height;
}
