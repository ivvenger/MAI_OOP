// main.cpp
#include "include/Figure.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/Rhombus.h"
#include "include/Array.h"
#include <iostream>
#include <memory>

int main() {
    Array<Figure> figures;
    int choice;

    std::cout << "1. Добавить прямоугольник\n";
    std::cout << "2. Добавить трапецию\n";
    std::cout << "3. Добавить ромб\n";
    std::cout << "4. Вывести фигуры\n";
    std::cout << "5. Посчитать общую площадь\n";
    std::cout << "6. Удаление фигуры по индексу\n";
    std::cout << "7. Выход\n";

    while (true) {
        std::cout << "\nВведите опцию: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Введите 4 вершины (x, y) для прямоугольника:\n";
            Rectangle* rect = new Rectangle();
            std::cin >> *rect;
            figures.add(rect);
        }
        else if (choice == 2) {
            std::cout << "Введите 4 вершины (x, y) для трапеции:\n";
            Trapezoid* trap = new Trapezoid();
            std::cin >> *trap;
            figures.add(trap);
        }
        else if (choice == 3) {
            std::cout << "Введите 4 вершины (x, y) для ромба:\n";
            Rhombus* rhom = new Rhombus();
            std::cin >> *rhom;
            figures.add(rhom);
        }
        else if (choice == 4) {
            for (size_t i = 0; i < figures.size(); ++i) {
                Figure* fig = figures.get(i);
                std::cout << "Фигура " << i << ": " << *fig << "\n";
                auto center = fig->geometricCenter();
                std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")\n";
                std::cout << "Площадь: " << static_cast<double>(*fig) << "\n";
            }
        }
        else if (choice == 5) {
            double total_area = 0.0;
            for (size_t i = 0; i < figures.size(); ++i) {
                total_area += static_cast<double>(*figures.get(i));
            }
            std::cout << "Общая площадь: " << total_area << "\n";
        }
        else if (choice == 6) {
            size_t index;
            std::cout << "Введите индекс для удаления: ";
            std::cin >> index;
            try {
                figures.remove(index);
                std::cout << "Фигура удалена.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << "\n";
            }
        }
        else if (choice == 7) {
            break;
        }
        else {
            std::cout << "Недоступная опция.\n";
        }
    }

    return 0;
}
