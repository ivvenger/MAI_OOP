#include "../include/Rhombus.h"

void Rhombus::calculate_geometric_center() const {
    std::cout << "Geometric center of Rhombus: (" << side / 2 << ", " << height / 2 << ")\n";
}

double Rhombus::area() const {
    return side * height;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& rhomb) {
    os << "Rhombus: side = " << rhomb.side << ", height = " << rhomb.height;
    return os;
}

std::istream& operator>>(std::istream& is, Rhombus& rhomb) {
    is >> rhomb.side >> rhomb.height;
    return is;
}

Rhombus* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* otherRhomb = dynamic_cast<const Rhombus*>(&other);
    return otherRhomb && side == otherRhomb->side && height == otherRhomb->height;
}
