#include <iostream>
#include "include/lab1.h"

using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    string output = removeVowels(s);
    cout << "Результат: " << output << "\n";
    return 0;
    }
