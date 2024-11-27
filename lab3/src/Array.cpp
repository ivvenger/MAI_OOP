#include "../include/Array.h"

Array::~Array() {
    for (Figure* fig : figures) {
        delete fig;
    }
}

void Array::add_figure(Figure* fig) {
    figures.push_back(fig);
}

void Array::remove_figure(int index) {
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

double Array::total_area() const {
    double total = 0.0;
    for (const Figure* fig : figures) {
        total += fig->area();
    }
    return total;
}

void Array::print_figures() const {
    for (const Figure* fig : figures) {
        std::cout << *fig << "\n";
        fig->calculate_geometric_center();
        std::cout << "Area: " << fig->area() << "\n";
    }
}
