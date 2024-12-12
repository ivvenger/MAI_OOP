#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <vector>
#include <utility>

class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readVertices(std::istream& is) = 0;
    virtual double area() const = 0;
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printVertices(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.readVertices(is);
        return is;
    }

    operator double() const {
        return area();
    }

    Figure(const Figure&) = default;
    Figure(Figure&&) noexcept = default;
    Figure& operator=(const Figure&) = default;
    Figure& operator=(Figure&&) noexcept = default;
};

#endif
