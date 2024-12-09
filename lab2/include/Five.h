#ifndef FIVE_H
#define FIVE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <string>

using namespace std;

class Five {
public:
    Five();
    Five(const size_t & n, unsigned char t = 0);
    Five(const initializer_list<unsigned char> &t);
    Five(const string &t);
    Five(const Five& other);
    Five(Five&& other) noexcept;
    ~Five() noexcept;

    Five& operator=(const Five& other);
    Five& operator=(Five&& other) noexcept;
    Five operator+(const Five& other) const;
    Five operator-(const Five& other) const;
    Five& operator+=(const Five& other);
    Five& operator-=(const Five& other);

    bool operator==(const Five& other) const;
    bool operator!=(const Five& other) const;
    bool operator<(const Five& other) const;
    bool operator>(const Five& other) const;
    bool operator<=(const Five& other) const;
    bool operator>=(const Five& other) const;
    friend ostream& operator<<(ostream& os, const Five& five);
    friend istream& operator>>(istream& is, Five& five);
    string to_string() const;

private:
    vector<unsigned char> digits;
    void normalize();
    void validateDigit(unsigned char digit) const;
};

#endif
