#include "../include/Five.h"

Five::Five() : digits(1, 0) {}
Five::Five(const size_t & n, unsigned char t) : digits(n, t) {
    validateDigit(t);
}

Five::Five(const initializer_list<unsigned char> &t) : digits(t) {
    for (unsigned char digit : t) {
        validateDigit(digit);
    }
}

Five::Five(const std::string &t) {
    for (char c : t) {
        if (c < '0' || c > '4') {
            throw invalid_argument("Недопустимый формат ввода.");
        }
        digits.push_back(c - '0');
    }
}

Five::Five(const Five& other) : digits(other.digits) {}
Five::Five(Five&& other) noexcept : digits(std::move(other.digits)) {}
Five::~Five() noexcept {}
Five& Five::operator=(const Five& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

Five& Five::operator=(Five&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
    }
    return *this;
}

Five Five::operator+(const Five& other) const {
    Five result;
    size_t maxSize = max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];

        if (sum >= 5) {
            carry = 1;
            sum -= 5;
        } else {
            carry = 0;
        }

        result.digits[i] = sum;
    }

    if (carry > 0) {
        result.digits.push_back(carry);
    }

    return result;
}

Five Five::operator-(const Five& other) const {
    if (*this < other) {
        throw invalid_argument("Результат отрицательный.");
    }

    Five result;
    size_t maxSize = max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    unsigned char borrow = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        int diff = 0;
        if (i < digits.size()) diff += digits[i];
        if (i < other.digits.size()) diff -= other.digits[i];

        if (diff < 0) {
            borrow = 1;
            diff += 5;
        } else {
            borrow = 0;
        }

        result.digits[i] = diff;
    }

    result.normalize();
    return result;
}

Five& Five::operator+=(const Five& other) {
    *this = *this + other;
    return *this;
}

Five& Five::operator-=(const Five& other) {
    *this = *this - other;
    return *this;
}

bool Five::operator==(const Five& other) const {
    return digits == other.digits;
}

bool Five::operator!=(const Five& other) const {
    return !(*this == other);
}

bool Five::operator<(const Five& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (size_t i = digits.size(); i-- > 0; ) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Five::operator>(const Five& other) const {
    return other < *this;
}

bool Five::operator<=(const Five& other) const {
    return !(other < *this);
}

bool Five::operator>=(const Five& other) const {
    return !(*this < other);
}

ostream& operator<<(ostream& os, const Five& five) {
    for (size_t i = five.digits.size(); i-- > 0; ) {
        os << static_cast<int>(five.digits[i]);
    }
    return os;
}

istream& operator>>(istream& is, Five& five) {
    string input;
    is >> input;
    five = Five(input);
    return is;
}

string Five::to_string() const {
    string result;
    for (size_t i = digits.size(); i-- > 0; ) {
        result += static_cast<char>(digits[i] + '0');
    }
    return result;
}

void Five::normalize() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

void Five::validateDigit(unsigned char digit) const {
    if (digit >= 5) {
        throw std::invalid_argument("Недопустимый формат ввода.");
    }
}
