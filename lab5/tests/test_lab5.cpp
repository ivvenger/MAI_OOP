#include <gtest/gtest.h>
#include "../include/memory_resource.h"
#include "../include/dynamic_array.h"

struct MyStruct {
    int a;
    double b;
    MyStruct(int x, double y) : a(x), b(y) {}
};

TEST(CustomArrayTest, PushBackSimpleType) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    array.push_back(10);
    array.push_back(20);
    array.push_back(30);

    ASSERT_EQ(array.get_size(), 3);
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
    EXPECT_EQ(array[2], 30);
}

TEST(CustomArrayTest, PushBackComplexType) {
    CustomMemoryResource custom_resource;
    CustomArray<MyStruct> array(&custom_resource);

    array.push_back(MyStruct(1, 1.1));
    array.push_back(MyStruct(2, 2.2));

    ASSERT_EQ(array.get_size(), 2);
    EXPECT_EQ(array[0].a, 1);
    EXPECT_DOUBLE_EQ(array[0].b, 1.1);
    EXPECT_EQ(array[1].a, 2);
    EXPECT_DOUBLE_EQ(array[1].b, 2.2);
}

TEST(CustomArrayTest, Clear) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    array.push_back(10);
    array.push_back(20);
    array.clear();

    ASSERT_EQ(array.get_size(), 0);
}

TEST(CustomArrayTest, Resize) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }

    ASSERT_EQ(array.get_size(), 10);
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(array[i], i);
    }
}

TEST(CustomArrayTest, DeallocateMemory) {
    CustomMemoryResource custom_resource;
    {
        CustomArray<int> array(&custom_resource);
        array.push_back(1);
        array.push_back(2);
    }
}

TEST(CustomArrayTest, ComplexTypeMemoryManagement) {
    CustomMemoryResource custom_resource;
    {
        CustomArray<MyStruct> array(&custom_resource);
        array.push_back(MyStruct(1, 1.1));
        array.push_back(MyStruct(2, 2.2));
    }
}

TEST(CustomArrayTest, MultipleAllocations) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    for (int i = 0; i < 100; ++i) {
        array.push_back(i);
    }

    ASSERT_EQ(array.get_size(), 100);
}

TEST(CustomArrayTest, MixedTypes) {
    CustomMemoryResource custom_resource;
    CustomArray<MyStruct> array(&custom_resource);

    array.push_back(MyStruct(1, 1.1));
    array.push_back(MyStruct(2, 2.2));

    ASSERT_EQ(array.get_size(), 2);
}

TEST(CustomArrayTest, DefaultConstructor) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    ASSERT_EQ(array.get_size(), 0);
}

TEST(CustomArrayTest, AllocationAfterDeallocation) {
    CustomMemoryResource custom_resource;
    CustomArray<int> array(&custom_resource);

    array.push_back(1);
    array.clear();
    array.push_back(2);

    ASSERT_EQ(array.get_size(), 1);
    EXPECT_EQ(array[0], 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
