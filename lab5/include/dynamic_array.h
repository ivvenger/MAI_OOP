#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <memory_resource>
#include <new>
#include <utility>

template<typename T>

class CustomArray {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;

    explicit CustomArray(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
        : allocator(resource), size(0), capacity(1), data(allocator.allocate(capacity)) {}

    ~CustomArray() {
        clear();
        allocator.deallocate(data, capacity);
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            resize();
        }
        new(data + size) T(value);
        ++size;
    }

    void clear() {
        for (std::size_t i = 0; i < size; ++i) {
            data[i].~T();
        }
        size = 0;
    }

    std::size_t get_size() const { return size; }
    T& operator[](std::size_t index) { return data[index]; }
    const T& operator[](std::size_t index) const { return data[index]; }

private:
    void resize() {
        capacity *= 2;
        T* new_data = allocator.allocate(capacity);
        for (std::size_t i = 0; i < size; ++i) {
            new(new_data + i) T(std::move(data[i]));
            data[i].~T();
        }
        allocator.deallocate(data, size);
        data = new_data;
    }

    allocator_type allocator;
    std::size_t size;
    std::size_t capacity;
    T* data;
};

#endif
