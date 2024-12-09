#include <gtest/gtest.h>
#include "../include/Five.h"

TEST(FiveTest, ConstructorDefault) {
    Five five;
    ASSERT_EQ(five.to_string(), "0");
}

TEST(FiveTest, ConstructorSize) {
    Five five(3, 2);
    ASSERT_EQ(five.to_string(), "222");
}

TEST(FiveTest, ConstructorInitializerList) {
    Five five({1, 2, 3});
    ASSERT_EQ(five.to_string(), "123");
}

TEST(FiveTest, ConstructorString) {
    Five five("1234");
    ASSERT_EQ(five.to_string(), "1234");
}

TEST(FiveTest, Addition) {
    Five a("123");
    Five b("401");
    Five c = a + b;
    ASSERT_EQ(c.to_string(), "1334");
}

TEST(FiveTest, Subtraction) {
    Five a("401");
    Five b("123");
    Five c = a - b;
    ASSERT_EQ(c.to_string(), "223");
}

TEST(FiveTest, Equality) {
    Five a("123");
    Five b("123");
    ASSERT_TRUE(a == b);
}

TEST(FiveTest, Inequality) {
    Five a("123");
    Five b("401");
    ASSERT_TRUE(a != b);
}

TEST(FiveTest, LessThan) {
    Five a("123");
    Five b("401");
    ASSERT_TRUE(a < b);
}

TEST(FiveTest, GreaterThan) {
    Five a("401");
    Five b("123");
    ASSERT_TRUE(a > b);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
