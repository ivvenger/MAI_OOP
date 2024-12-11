#include <iostream>
#include "include/Array.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/Rhombus.h"

using namespace std;

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;

    int choice;
    while (true) {
        cout << "Выберите действие:\n";
        cout << "1. Добавить прямоугольник\n";
        cout << "2. Добавить трапецию\n";
        cout << "3. Добавить ромб\n";
        cout << "4. Вывести все фигуры\n";
        cout << "5. Удалить фигуру по индексу\n";
        cout << "6. Вычислить общую площадь\n";
        cout << "0. Выйти\n";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                vector<unique_ptr<Point<double>>> vertices;
                for (size_t i = 0; i < 4; ++i) {
                    auto point = make_unique<Point<double>>();
                    cin >> *point;
                    vertices.push_back(move(point));
                }
                auto rect = make_shared<Rectangle<double>>(vertices);
                figures.add(rect);
                break;
            }
            case 2: {
                vector<unique_ptr<Point<double>>> vertices;
                for (size_t i = 0; i < 4; ++i) {
                    auto point = make_unique<Point<double>>();
                    cin >> *point;
                    vertices.push_back(move(point));
                }
                auto trap = make_shared<Trapezoid<double>>(vertices);
                figures.add(trap);
                break;
            }
            case 3: {
                vector<unique_ptr<Point<double>>> vertices;
                for (size_t i = 0; i < 4; ++i) {
                    auto point = make_unique<Point<double>>();
                    cin >> *point;
                    vertices.push_back(move(point));
                }
                auto rhomb = make_shared<Rhombus<double>>(vertices);
                figures.add(rhomb);
                break;
            }
            case 4: {
                for (size_t i = 0; i < figures.size(); ++i) {
                    cout << "Фигура " << i << ":\n";
                    figures[i]->print(cout);
                    cout << "\nГеометрический центр: ("
                              << figures[i]->getGeometricCenter().first << ", "
                              << figures[i]->getGeometricCenter().second << ")\n";
                    cout << "Площадь: " << static_cast<double>(*figures[i]) << "\n";
                }
                break;
            }
            case 5: {
                size_t index;
                cout << "Введите индекс фигуры для удаления: ";
                cin >> index;
                figures.remove(index);
                break;
            }
            case 6: {
                double totalArea = 0;
                for (size_t i = 0; i < figures.size(); ++i) {
                    totalArea += static_cast<double>(*figures[i]);
                }
                cout << "Общая площадь всех фигур: " << totalArea << "\n";
                break;
            }
            default:
                cout << "Неверный выбор\n";
        }
    }

    return 0;
}
