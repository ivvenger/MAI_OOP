#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const std::vector<std::pair<double, double>>& vertices);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() override = default;

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
