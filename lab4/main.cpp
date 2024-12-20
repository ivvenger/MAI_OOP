#include <iostream>
#include <memory>
#include "include/Point.h"
#include "include/Figure.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/Rhombus.h"
#include "include/Array.h"

int main() {
    try {
        Array<Figure<int>> figuresArray;

        int choice;
        while (true) {
            std::cout << "\nМеню:\n";
            std::cout << "1. Добавить Прямоугольник\n";
            std::cout << "2. Добавить Трапецию\n";
            std::cout << "3. Добавить Ромб\n";
            std::cout << "4. Вывести все фигуры\n";
            std::cout << "5. Вычислить общую площадь\n";
            std::cout << "6. Удалить фигуру по индексу\n";
            std::cout << "7. Выход\n";
            std::cout << "Выберите опцию: ";
            std::cin >> choice;

            if(choice == 1) {
                auto rect = std::make_unique<Rectangle<int>>();
                rect->input();
                figuresArray.add(std::move(rect));
                std::cout << "Прямоугольник добавлен.\n";
            }
            else if(choice == 2) {
                auto trapezoid = std::make_unique<Trapezoid<int>>();
                trapezoid->input();
                figuresArray.add(std::move(trapezoid));
                std::cout << "Трапеция добавлена.\n";
            }
            else if(choice == 3) {
                auto rhombus = std::make_unique<Rhombus<int>>();
                rhombus->input();
                figuresArray.add(std::move(rhombus));
                std::cout << "Ромб добавлен.\n";
            }
            else if(choice == 4) {
                std::cout << "\nФигуры в массиве:\n";
                for(size_t i = 0; i < figuresArray.size(); ++i) {
                    std::cout << "Фигура " << i << ":\n";
                    figuresArray[i].print();
                    std::cout << "Геометрический центр: ";
                    Point<int> center = figuresArray[i].geometricCenter();
                    center.print();
                    std::cout << "\n\n";
                }
            }
            else if(choice == 5) {
                double totalArea = 0.0;
                for(size_t i = 0; i < figuresArray.size(); ++i) {
                    totalArea += figuresArray[i].area();
                }
                std::cout << "Общая площадь всех фигур: " << totalArea << "\n";
            }
            else if(choice == 6) {
                size_t index;
                std::cout << "Введите индекс для удаления: ";
                std::cin >> index;
                figuresArray.remove_at(index);
                std::cout << "Фигура удалена.\n";
            }
            else if(choice == 7) {
                std::cout << "Выход из программы.\n";
                break;
            }
            else {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }
    catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
