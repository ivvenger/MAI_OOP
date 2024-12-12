#include "../include/Rectangle.h"
#include <cmath>

Rectangle::Rectangle() : Figure(), vertices(4, {0.0, 0.0}) {}

Rectangle::Rectangle(const std::vector<std::pair<double, double>>& verts) : Figure(), vertices(verts) {}

Rectangle::Rectangle(const Rectangle& other) : Figure(other), vertices(other.vertices) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : Figure(std::move(other)), vertices(std::move(other.vertices)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        Figure::operator=(other);
        vertices = other.vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::pair<double, double> Rectangle::geometricCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vert : vertices) {
        x_sum += vert.first;
        y_sum += vert.second;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

void Rectangle::printVertices(std::ostream& os) const {
    for (const auto& vert : vertices) {
        os << "(" << vert.first << ", " << vert.second << ") ";
    }
}

void Rectangle::readVertices(std::istream& is) {
    for (auto& vert : vertices) {
        is >> vert.first >> vert.second;
    }
}

double Rectangle::area() const {
    double width = std::hypot(vertices[1].first - vertices[0].first, vertices[1].second - vertices[0].second);
    double height = std::hypot(vertices[3].first - vertices[0].first, vertices[3].second - vertices[0].second);
    return width * height;
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
    if (!rect) return false;
    return vertices == rect->vertices;
}
