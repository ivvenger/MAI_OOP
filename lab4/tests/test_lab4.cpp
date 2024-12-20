#include <gtest/gtest.h>
#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Array.h"

TEST(PointTest, ConstructorAndPrint) {
    Point<int> p1;
    EXPECT_EQ(p1.x, 0);
    EXPECT_EQ(p1.y, 0);
    Point<double> p2(3.5, -2.1);
    EXPECT_DOUBLE_EQ(p2.x, 3.5);
    EXPECT_DOUBLE_EQ(p2.y, -2.1);
}

TEST(RectangleTest, AreaCalculation) {
    Point<int> tl(0, 2);
    Point<int> tr(3, 2);
    Point<int> br(3, 0);
    Point<int> bl(0, 0);
    Rectangle<int> rect(tl, tr, br, bl);
    EXPECT_EQ(rect.area(), 6.0);
}

TEST(TrapezoidTest, GeometricCenter) {
    Point<int> tl(1, 3);
    Point<int> tr(4, 3);
    Point<int> br(5, 0);
    Point<int> bl(0, 0);
    Trapezoid<int> trap(tl, tr, br, bl);
    Point<int> center = trap.geometricCenter();
    EXPECT_EQ(center.x, 2.5);
    EXPECT_EQ(center.y, 1.5);
}

TEST(RhombusTest, AreaCalculation) {
    Point<int> v1(0, 0);
    Point<int> v2(2, 2);
    Point<int> v3(4, 0);
    Point<int> v4(2, -2);
    Rhombus<int> rhomb(v1, v2, v3, v4);
    EXPECT_EQ(rhomb.area(), 8.0);
}

TEST(FigureTest, Comparison) {
    Point<int> tl(0, 2);
    Point<int> tr(3, 2);
    Point<int> br(3, 0);
    Point<int> bl(0, 0);
    Rectangle<int> rect1(tl, tr, br, bl);
    Rectangle<int> rect2(tl, tr, br, bl);
    EXPECT_TRUE(rect1 == rect2);
}

TEST(FigureTest, DoubleConversion) {
    Point<int> tl(0, 2);
    Point<int> tr(3, 2);
    Point<int> br(3, 0);
    Point<int> bl(0, 0);
    Rectangle<int> rect(tl, tr, br, bl);
    double area = static_cast<double>(rect);
    EXPECT_EQ(area, 6.0);
}

TEST(ArrayTest, AddAndAccessFigure) {
    Array<std::unique_ptr<Figure<int>>> array;
    Point<int> tl(0, 2);
    Point<int> tr(3, 2);
    Point<int> br(3, 0);
    Point<int> bl(0, 0);
    Rectangle<int> rect(tl, tr, br, bl);
    EXPECT_EQ(array.size(), 1);
}

TEST(FigureTest, Cloning) {
    Point<int> tl(0, 2);
    Point<int> tr(3, 2);
    Point<int> br(3, 0);
    Point<int> bl(0, 0);
    Rectangle<int> rect(tl, tr, br, bl);
    auto cloneRect = rect.clone();
    EXPECT_EQ(rect.area(), cloneRect->area());
    EXPECT_TRUE(rect == *cloneRect);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
