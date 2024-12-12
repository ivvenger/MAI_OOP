#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>
#include "Figure.h"

template <typename T>
class Array {
public:
    Array() : data(nullptr), capacity(0), length(0) {}
    Array(const Array& other) : capacity(other.capacity), length(other.length) {
        data = new T*[capacity];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i]->clone();
        }
    }
    Array(Array&& other) noexcept : data(other.data), capacity(other.capacity), length(other.length) {
        other.data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            for (size_t i = 0; i < length; ++i) {
                delete data[i];
            }
            delete[] data;
            capacity = other.capacity;
            length = other.length;
            data = new T*[capacity];
            for (size_t i = 0; i < length; ++i) {
                data[i] = other.data[i]->clone();
            }
        }
        return *this;
    }
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < length; ++i) {
                delete data[i];
            }
            delete[] data;
            data = other.data;
            capacity = other.capacity;
            length = other.length;
            other.data = nullptr;
            other.capacity = 0;
            other.length = 0;
        }
        return *this;
    }
    ~Array() {
        for (size_t i = 0; i < length; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    void add(T* element) {
        if (length == capacity) {
            resize(capacity == 0 ? 4 : capacity * 2);
        }
        data[length++] = element;
    }

    void remove(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        delete data[index];
        for (size_t i = index; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        --length;
    }

    T* get(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t size() const {
        return length;
    }

    T*& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T* operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

private:
    T** data;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity) {
        T** new_data = new T*[new_capacity];
        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
};

#endif
