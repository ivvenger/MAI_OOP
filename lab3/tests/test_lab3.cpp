#include <gtest/gtest.h>
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Array.h"


TEST(FigureTest, RectangleArea) {
    Rectangle rect(4, 5);
    EXPECT_DOUBLE_EQ(rect.area(), 20.0);
}

TEST(FigureTest, TrapezoidArea) {
    Trapezoid trap(3, 4, 5);
    EXPECT_DOUBLE_EQ(trap.area(), 17.5);
}

TEST(FigureTest, RhombusArea) {
    Rhombus rhomb(4, 5);
    EXPECT_DOUBLE_EQ(rhomb.area(), 20.0);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    array.add_figure(new Rectangle(4, 5));
    array.add_figure(new Trapezoid(3, 4, 5));
    array.add_figure(new Rhombus(4, 5));
    EXPECT_DOUBLE_EQ(array.total_area(), 57.5);
}

TEST(ArrayTest, RemoveFigure) {
    Array array;
    array.add_figure(new Rectangle(4, 5));
    array.add_figure(new Trapezoid(3, 4, 5));
    array.add_figure(new Rhombus(4, 5));
    array.remove_figure(1);
    EXPECT_DOUBLE_EQ(array.total_area(), 40.0);
}
