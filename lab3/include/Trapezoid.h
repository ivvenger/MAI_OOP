#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const std::vector<std::pair<double, double>>& vertices);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    ~Trapezoid() override = default;

    std::pair<double, double> geometricCenter() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    double area() const override;
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    std::vector<std::pair<double, double>> vertices;
};

#endif
