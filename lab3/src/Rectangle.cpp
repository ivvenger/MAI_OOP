#include "../include/Rectangle.h"

void Rectangle::calculate_geometric_center() const {
    std::cout << "Geometric center of Rectangle: (" << width / 2 << ", " << height / 2 << ")\n";
}

double Rectangle::area() const {
    return width * height;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle: width = " << rect.width << ", height = " << rect.height;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect) {
    is >> rect.width >> rect.height;
    return is;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    return otherRect && width == otherRect->width && height == otherRect->height;
}
