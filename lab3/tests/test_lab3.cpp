#include <gtest/gtest.h>
#include "../include/Figure.h"
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Array.h"

TEST(RectangleTest, GeometricCenter) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {4,3}, {0,3} };
    Rectangle rect(vertices);
    auto center = rect.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 1.5);
}

TEST(RectangleTest, Area) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {4,3}, {0,3} };
    Rectangle rect(vertices);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
}

TEST(RectangleTest, IOOperations) {
    Rectangle rect;
    std::istringstream iss("0 0 4 0 4 3 0 3");
    iss >> rect;
    std::ostringstream oss;
    oss << rect;
    EXPECT_EQ(oss.str(), "(0, 0) (4, 0) (4, 3) (0, 3) ");
}

TEST(RectangleTest, CopyAndCompare) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {4,3}, {0,3} };
    Rectangle rect1(vertices);
    Rectangle rect2 = rect1;
    EXPECT_TRUE(rect1 == rect2);
}

TEST(TrapezoidTest, GeometricCenter) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {3,3}, {1,3} };
    Trapezoid trap(vertices);
    auto center = trap.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 1.5);
}

TEST(TrapezoidTest, Area) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {3,3}, {1,3} };
    Trapezoid trap(vertices);
    EXPECT_DOUBLE_EQ(trap.area(), 9.0);
}

TEST(TrapezoidTest, IOOperations) {
    Trapezoid trap;
    std::istringstream iss("0 0 4 0 3 3 1 3");
    iss >> trap;
    std::ostringstream oss;
    oss << trap;
    EXPECT_EQ(oss.str(), "(0, 0) (4, 0) (3, 3) (1, 3) ");
}

TEST(TrapezoidTest, CopyAndCompare) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {4,0}, {3,3}, {1,3} };
    Trapezoid trap1(vertices);
    Trapezoid trap2 = trap1;
    EXPECT_TRUE(trap1 == trap2);
}

TEST(RhombusTest, GeometricCenter) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {2,1}, {0,2}, {-2,1} };
    Rhombus rhom(vertices);
    auto center = rhom.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(RhombusTest, Area) {
    std::vector<std::pair<double, double>> vertices = { {0,0}, {2,1}, {0,2}, {-2,1} };
    Rhombus rhom(vertices);
    EXPECT_DOUBLE_EQ(rhom.area(), 4.0);
}

TEST(ArrayTest, AddRemove) {
    Array<Figure> arr;
    Rectangle* rect = new Rectangle({ {0,0}, {4,0}, {4,3}, {0,3} });
    Trapezoid* trap = new Trapezoid({ {0,0}, {4,0}, {3,3}, {1,3} });
    arr.add(rect);
    arr.add(trap);
    EXPECT_EQ(arr.size(), 2);
    arr.remove(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0)->area(), 9.0);
    arr.remove(0);
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array<Figure> arr;
    arr.add(new Rectangle({ {0,0}, {4,0}, {4,3}, {0,3} }));
    arr.add(new Trapezoid({ {0,0}, {4,0}, {3,3}, {1,3} }));
    arr.add(new Rhombus({ {0,0}, {2,1}, {0,2}, {-2,1} }));
    double total = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total += static_cast<double>(*arr.get(i));
    }
    EXPECT_DOUBLE_EQ(total, 12.0 + 9.0 + 4.0);
}

TEST(ArrayTest, RemoveInvalidIndex) {
    Array<Figure> arr;
    arr.add(new Rectangle({ {0,0}, {4,0}, {4,3}, {0,3} }));
    EXPECT_THROW(arr.remove(1), std::out_of_range);
}
