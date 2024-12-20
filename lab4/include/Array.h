#pragma once
#include <memory>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Array {
private:
    std::shared_ptr<std::unique_ptr<T>[]> data;
    size_t capacity;
    size_t length;
    void resize(size_t new_capacity) {
        std::shared_ptr<std::unique_ptr<T>[]> new_data = std::make_shared<std::unique_ptr<T>[]>(new_capacity);
        for(size_t i = 0; i < length; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = new_data;
        capacity = new_capacity;
    }

public:
    Array(size_t initial_capacity = 10)
        : data(std::make_shared<std::unique_ptr<T>[]>(initial_capacity)),
          capacity(initial_capacity),
          length(0) {}

    ~Array() = default;
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    void add(std::unique_ptr<T> element) {
        if(length >= capacity) {
            resize(capacity * 2);
        }
        data[length++] = std::move(element);
    }

    void remove_at(size_t index) {
        if(index >= length) {
            throw std::out_of_range("Index out of range");
        }
        for(size_t i = index; i < length - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        data[length - 1].reset();
        --length;
    }

    size_t size() const {
        return length;
    }

    T& operator[](size_t index) {
        if(index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return *(data[index]);
    }

    const T& operator[](size_t index) const {
        if(index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return *(data[index]);
    }
};
