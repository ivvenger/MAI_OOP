#include "../include/lab1.h"

using namespace std;

string removeVowels(const string& s) {
    string res;
    for (char lit : s) {
        if (lit != 'a' && lit != 'e' && lit != 'i' && lit != 'o' && lit != 'u' && lit != 'y' &&
            lit != 'A' && lit != 'E' && lit != 'I' && lit != 'O' && lit != 'U' && lit != 'Y') {
                res += lit;
        }
    }
    return res;
}
