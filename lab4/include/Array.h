#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <memory>

template <typename T>
class Array {
public:
    void add(T item) {
        items.push_back(std::move(item));
    }

    void remove(size_t index) {
        if (index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    size_t size() const {
        return items.size();
    }

    T& operator[](size_t index) {
        return items[index];
    }

private:
    std::vector<T> items;
};

#endif
