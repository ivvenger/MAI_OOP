#ifndef MEMORY_RESOURCE_H
#define MEMORY_RESOURCE_H
#include <memory_resource>
#include <map>
#include <cstdlib>
#include <iostream>


class CustomMemoryResource : public std::pmr::memory_resource {
public:
    CustomMemoryResource() = default;

    ~CustomMemoryResource() {
        for (const auto& pair : allocations) {
            std::free(pair.first);
        }
    }

protected:
    void* do_allocate(std::size_t size, std::size_t alignment) override {
        void* ptr = std::aligned_alloc(alignment, size);
        if (ptr) {
            allocations[ptr] = size; // Сохраняем информацию об выделении
        }
        return ptr;
    }

    void do_deallocate(void* ptr, std::size_t size, std::size_t alignment) override {
        if (allocations.erase(ptr)) {
            std::free(ptr);
        }
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

private:
    std::map<void*, std::size_t> allocations; // Хранит указатели и размеры выделенной памяти
};

#endif
