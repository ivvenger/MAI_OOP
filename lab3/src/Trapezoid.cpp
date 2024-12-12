#include "../include/Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid() : Figure(), vertices(4, {0.0, 0.0}) {}

Trapezoid::Trapezoid(const std::vector<std::pair<double, double>>& verts) : Figure(), vertices(verts) {}

Trapezoid::Trapezoid(const Trapezoid& other) : Figure(other), vertices(other.vertices) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : Figure(std::move(other)), vertices(std::move(other.vertices)) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        Figure::operator=(other);
        vertices = other.vertices;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        vertices = std::move(other.vertices);
    }
    return *this;
}

std::pair<double, double> Trapezoid::geometricCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vert : vertices) {
        x_sum += vert.first;
        y_sum += vert.second;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

void Trapezoid::printVertices(std::ostream& os) const {
    for (const auto& vert : vertices) {
        os << "(" << vert.first << ", " << vert.second << ") ";
    }
}

void Trapezoid::readVertices(std::istream& is) {
    for (auto& vert : vertices) {
        is >> vert.first >> vert.second;
    }
}

double Trapezoid::area() const {
    double a = std::hypot(vertices[1].first - vertices[0].first, vertices[1].second - vertices[0].second);
    double b = std::hypot(vertices[2].first - vertices[3].first, vertices[2].second - vertices[3].second);
    double h = std::abs(vertices[1].second - vertices[0].second);
    return (a + b) * h / 2.0;
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
    if (!trap) return false;
    return vertices == trap->vertices;
}
