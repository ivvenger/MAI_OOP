#include "include/Five.h"

using namespace std;

int main() {
    Five five1;
    Five five2;

    cout << "Введите первое число: ";
    string input1;
    cin >> input1;
    for (char c : input1) {
        five1.append(c - '0');
    }

    cout << "Введите второе число: ";
    string input2;
    cin >> input2;
    for (char c : input2) {
        five2.append(c - '0');
    }

    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - сравнение): ";
    int operation;
    cin >> operation;

    if (operation == 1) {
        Five* result = dynamic_cast<Five*>(five1.add(five2));
        cout << "Результат сложения: ";
        result->print();
        delete result;
    } else if (operation == 2) {
        Five* result = dynamic_cast<Five*>(five1.subtract(five2));
        cout << "Результат вычитания: ";
        result->print();
        delete result;
    } else if (operation == 3) {
        cout << "Первое число равно второму: " << (five1.equals(five2) ? "Да" : "Нет") << '\n';
        cout << "Первое число меньше второго: " << (five1.lessThan(five2) ? "Да" : "Нет") << '\n';
        cout << "Первое число больше второго: " << (five1.greaterThan(five2) ? "Да" : "Нет") << '\n';
    } else {
        cout << "Недоступная опция." << '\n';
    }
    return 0;
}
