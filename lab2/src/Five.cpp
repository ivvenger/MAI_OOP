#include <iostream>
#include <stdexcept>
#include <vector>
#include "../include/Five.h"


class Five : public DynamicArrayInterface {
public:
    Five(int capacity = 10) {
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be greater than 0");
        }
        this->capacity = capacity;
        this->size = 0;
        this->array = new unsigned char[capacity];
        std::fill(this->array, this->array + capacity, 0);
    }

    ~Five() {
        delete[] array;
    }

    void append(unsigned char value) override {
        if (value < 0 || value > 4) {
            throw std::invalid_argument("Value must be a valid quinary digit (0-4)");
        }
        if (size == capacity) {
            resize(2 * capacity);
        }
        array[size++] = value;
    }

    unsigned char get(int index) const override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void set(int index, unsigned char value) override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (value < 0 || value > 4) {
            throw std::invalid_argument("Value must be a valid quinary digit (0-4)");
        }
        array[index] = value;
    }

    int size() const override {
        return size;
    }

    DynamicArrayInterface* add(const DynamicArrayInterface& other) const override {
        const Five& otherFive = dynamic_cast<const Five&>(other);
        Five* result = new Five(std::max(capacity, otherFive.capacity));
        unsigned char carry = 0;
        for (int i = 0; i < std::max(size, otherFive.size); ++i) {
            unsigned char val1 = (i < size) ? array[i] : 0;
            unsigned char val2 = (i < otherFive.size) ? otherFive.array[i] : 0;
            unsigned char total = val1 + val2 + carry;
            if (total >= 5) {
                carry = 1;
                total -= 5;
            } else {
                carry = 0;
            }
            result->append(total);
        }
        if (carry) {
            result->append(carry);
        }
        return result;
    }

    DynamicArrayInterface* subtract(const DynamicArrayInterface& other) const override {
        const Five& otherFive = dynamic_cast<const Five&>(other);
        Five* result = new Five(std::max(capacity, otherFive.capacity));
        unsigned char borrow = 0;
        for (int i = 0; i < std::max(size, otherFive.size); ++i) {
            unsigned char val1 = (i < size) ? array[i] : 0;
            unsigned char val2 = (i < otherFive.size) ? otherFive.array[i] : 0;
            int total = val1 - val2 - borrow;
            if (total < 0) {
                borrow = 1;
                total += 5;
            } else {
                borrow = 0;
            }
            result->append(total);
        }
        return result;
    }

    bool equals(const DynamicArrayInterface& other) const override {
        const Five& otherFive = dynamic_cast<const Five&>(other);
        if (size != otherFive.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (array[i] != otherFive.array[i]) {
                return false;
            }
        }
        return true;
    }

    bool lessThan(const DynamicArrayInterface& other) const override {
        const Five& otherFive = dynamic_cast<const Five&>(other);
        if (size != otherFive.size) {
            return size < otherFive.size;
        }
        for (int i = size - 1; i >= 0; --i) {
            if (array[i] != otherFive.array[i]) {
                return array[i] < otherFive.array[i];
            }
        }
        return false;
    }

    bool greaterThan(const DynamicArrayInterface& other) const override {
        const Five& otherFive = dynamic_cast<const Five&>(other);
        if (size != otherFive.size) {
            return size > otherFive.size;
        }
        for (int i = size - 1; i >= 0; --i) {
            if (array[i] != otherFive.array[i]) {
                return array[i] > otherFive.array[i];
            }
        }
        return false;
    }

    DynamicArrayInterface* copy() const override {
        Five* newArray = new Five(capacity);
        newArray->size = size;
        std::copy(array, array + size, newArray->array);
        return newArray;
    }

    void print() const {
        for (int i = size - 1; i >= 0; --i) {
            std::cout << static_cast<int>(array[i]);
        }
        std::cout << std::endl;
    }

private:
    void resize(int new_capacity) {
        unsigned char* new_array = new unsigned char[new_capacity];
        std::copy(array, array + size, new_array);
        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

    int capacity;
    int size;
    unsigned char* array;
};
