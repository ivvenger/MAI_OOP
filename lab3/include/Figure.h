#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;

    virtual void calculate_geometric_center() const = 0;
    virtual double area() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);

    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};

#endif
