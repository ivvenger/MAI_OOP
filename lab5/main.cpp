#include <iostream>
#include "include/memory_resource.h"
#include "include/dynamic_array.h"


struct MyStruct {
    int a;
    double b;
    MyStruct(int x, double y) : a(x), b(y) {}
};

int main() {
    CustomMemoryResource custom_resource;
    CustomArray<int> int_array(&custom_resource);
    int_array.push_back(1);
    int_array.push_back(2);
    int_array.push_back(3);

    std::cout << "Int array elements: ";
    for (size_t i = 0; i < int_array.get_size(); ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;

    CustomArray<MyStruct> struct_array(&custom_resource);
    struct_array.push_back(MyStruct(1, 1.1));
    struct_array.push_back(MyStruct(2, 2.2));

    std::cout << "Элементы массива: ";
    for (size_t i = 0; i < struct_array.get_size(); ++i) {
        std::cout << "(" << struct_array[i].a << ", " << struct_array[i].b << ") ";
    }
    std::cout << std::endl;

    return 0;
}
