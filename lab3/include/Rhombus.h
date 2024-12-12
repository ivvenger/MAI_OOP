#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(const std::vector<std::pair<double, double>>& vertices);
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    ~Rhombus() override = default;

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
