#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <vector>

class Array {
public:
    Array() = default;
    ~Array() {
        for (Figure* fig : figures) {
            delete fig;
        }
    }

    void add_figure(Figure* fig) {
        figures.push_back(fig);
    }

    void remove_figure(int index) {
        if (index >= 0 && index < figures.size()) {
            delete figures[index];
            figures.erase(figures.begin() + index);
        }
    }

    double total_area() const {
        double total = 0.0;
        for (const Figure* fig : figures) {
            total += fig->area();
        }
        return total;
    }

    void print_figures() const {
        for (const Figure* fig : figures) {
            std::cout << *fig << "\n";
            fig->calculate_geometric_center();
            std::cout << "Area: " << fig->area() << "\n";
        }
    }

private:
    std::vector<Figure*> figures;
};

#endif
