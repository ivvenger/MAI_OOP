#include <iostream>
#include "include/Five.h"

using namespace std;

int main() {
    try {
        Five a({1, 2, 3});
        Five b({4, 0, 1});
        Five c = a + b;
        Five d = a - b;

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c (a + b): " << c << endl;
        cout << "d (a - b): " << d << endl;

        cout << "a == b: " << (a == b ? "true" : "false") << endl;
        cout << "a < b: " << (a < b ? "true" : "false") << endl;
        cout << "a > b: " << (a > b ? "true" : "false") << endl;

        Five e;
        cout << "Введите пятиричное число:  ";
        cin >> e;
        cout << "e: " << e << endl;
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
