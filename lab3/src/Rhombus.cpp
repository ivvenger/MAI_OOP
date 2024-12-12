#include "../include/Rhombus.h"
#include <cmath>

Rhombus::Rhombus() : Figure(), vertices(4, {0.0, 0.0}) {}

Rhombus::Rhombus(const std::vector<std::pair<double, double>>& verts) : Figure(), vertices(verts) {}

Rhombus::Rhombus(const Rhombus& other) : Figure(other), vertices(other.vertices) {}

Rhombus::Rhombus(Rhombus&& other) noexcept : Figure(std::move(other)), vertices(std::move(other.vertices)) {}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        Figure::operator=(other);
        vertices = other.vertices;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::pair<double, double> Rhombus::geometricCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vert : vertices) {
        x_sum += vert.first;
        y_sum += vert.second;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

void Rhombus::printVertices(std::ostream& os) const {
    for (const auto& vert : vertices) {
        os << "(" << vert.first << ", " << vert.second << ") ";
    }
}

void Rhombus::readVertices(std::istream& is) {
    for (auto& vert : vertices) {
        is >> vert.first >> vert.second;
    }
}

double Rhombus::area() const {
    double d1 = std::hypot(vertices[2].first - vertices[0].first, vertices[2].second - vertices[0].second);
    double d2 = std::hypot(vertices[3].first - vertices[1].first, vertices[3].second - vertices[1].second);
    return (d1 * d2) / 2.0;
}

Figure* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* rhom = dynamic_cast<const Rhombus*>(&other);
    if (!rhom) return false;
    return vertices == rhom->vertices;
}
