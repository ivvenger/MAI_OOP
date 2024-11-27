#include <iostream>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Array.h"

using namespace std;

int main() {
    Array array;
    int num_figures;
    cout << "Введите количество фигур: ";
    cin >> num_figures;

    for (int i = 0; i < num_figures; ++i) {
        int type;
        cout << "Введите тип фигуры (1 - Прямоугольник, 2 - Трапеция, 3 - Ромб): ";
        cin >> type;

        if (type == 1) {
            Rectangle* rect = new Rectangle();
            cin >> *rect;
            array.add_figure(rect);
        } else if (type == 2) {
            Trapezoid* trap = new Trapezoid();
            cin >> *trap;
            array.add_figure(trap);
        } else if (type == 3) {
            Rhombus* rhomb = new Rhombus();
            cin >> *rhomb;
            array.add_figure(rhomb);
        } else {
            cerr << "Такой тип фигуры не предусмотрен.\n";
        }
    }

    array.print_figures();
    cout << "Общая площадь фигур: " << array.total_area() << '\n';

    int index_to_remove;
    cout << "Введите индекс фигуры для удаления: ";
    cin >> index_to_remove;
    array.remove_figure(index_to_remove);

    array.print_figures();
    cout << "Общая площадь фигур: " << array.total_area() << '\n';

    return 0;
}
