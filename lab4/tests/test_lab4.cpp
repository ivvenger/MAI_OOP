#include <gtest/gtest.h>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Point.h"

const double Eps = 1e-6;

using namespace std;

TEST(FigureTest, RectangleArea) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(1, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(0, 1));
    Rectangle<double> r(vertices);
    ASSERT_NEAR(static_cast<double>(r), 1.0, Eps);
}

TEST(FigureTest, TrapezoidArea) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(2, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(3, 1));
    Trapezoid<double> t(vertices);
    ASSERT_NEAR(static_cast<double>(t), 2.0, Eps);
}

TEST(FigureTest, RhombusArea) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(1, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(0, 1));
    Rhombus<double> r(vertices);
    ASSERT_NEAR(static_cast<double>(r), 1.0, Eps);
}

TEST(FigureTest, RectangleGeometricCenter) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(2, 0));
    vertices.push_back(make_unique<Point<double>>(2, 2));
    vertices.push_back(make_unique<Point<double>>(0, 2));
    Rectangle<double> r(vertices);
    auto center = r.getGeometricCenter();
    ASSERT_NEAR(center.first, 1.0, Eps);
    ASSERT_NEAR(center.second, 1.0, Eps);
}

TEST(FigureTest, TrapezoidGeometricCenter) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(2, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(3, 1));
    Trapezoid<double> t(vertices);
    auto center = t.getGeometricCenter();
    ASSERT_NEAR(center.first, 1.5, Eps);
    ASSERT_NEAR(center.second, 0.5, Eps);
}

TEST(FigureTest, RhombusGeometricCenter) {
    vector<unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(1, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(0, 1));
    Rhombus<double> r(vertices);
    auto center = r.getGeometricCenter();
    ASSERT_NEAR(center.first, 0.5, Eps);
    ASSERT_NEAR(center.second, 0.5, Eps);
}

TEST(FigureTest, RectangleEquality) {
    vector<unique_ptr<Point<double>>> vertices1;
    vertices1.push_back(make_unique<Point<double>>(0, 0));
    vertices1.push_back(make_unique<Point<double>>(1, 0));
    vertices1.push_back(make_unique<Point<double>>(1, 1));
    vertices1.push_back(make_unique<Point<double>>(0, 1));
    Rectangle<double> r1(vertices1);

    vector<unique_ptr<Point<double>>> vertices2;
    vertices2.push_back(make_unique<Point<double>>(0, 0));
    vertices2.push_back(make_unique<Point<double>>(1, 0));
    vertices2.push_back(make_unique<Point<double>>(1, 1));
    vertices2.push_back(make_unique<Point<double>>(0, 1));
    Rectangle<double> r2(vertices2);

    ASSERT_TRUE(r1 == r2);
}

TEST(FigureTest, TrapezoidEquality) {
    vector<unique_ptr<Point<double>>> vertices1;
    vertices1.push_back(make_unique<Point<double>>(0, 0));
    vertices1.push_back(make_unique<Point<double>>(2, 0));
    vertices1.push_back(make_unique<Point<double>>(1, 1));
    vertices1.push_back(make_unique<Point<double>>(3, 1));
    Trapezoid<double> t1(vertices1);

    vector<unique_ptr<Point<double>>> vertices2;
    vertices2.push_back(make_unique<Point<double>>(0, 0));
    vertices2.push_back(make_unique<Point<double>>(2, 0));
    vertices2.push_back(make_unique<Point<double>>(1, 1));
    vertices2.push_back(make_unique<Point<double>>(3, 1));
    Trapezoid<double> t2(vertices2);

    ASSERT_TRUE(t1 == t2);
}

TEST(FigureTest, RhombusEquality) {
    vector<unique_ptr<Point<double>>> vertices1;
    vertices1.push_back(make_unique<Point<double>>(0, 0));
    vertices1.push_back(make_unique<Point<double>>(1, 0));
    vertices1.push_back(make_unique<Point<double>>(1, 1));
    vertices1.push_back(make_unique<Point<double>>(0, 1));
    Rhombus<double> r1(vertices1);

    vector<unique_ptr<Point<double>>> vertices2;
    vertices2.push_back(make_unique<Point<double>>(0, 0));
    vertices2.push_back(make_unique<Point<double>>(1, 0));
    vertices2.push_back(make_unique<Point<double>>(1, 1));
    vertices2.push_back(make_unique<Point<double>>(0, 1));
    Rhombus<double> r2(vertices2);

    ASSERT_TRUE(r1 == r2);
}

TEST(FigureTest, ArrayAddRemove) {
    Array<shared_ptr<Figure<double>>> figures;
    vector<std::unique_ptr<Point<double>>> vertices;
    vertices.push_back(make_unique<Point<double>>(0, 0));
    vertices.push_back(make_unique<Point<double>>(1, 0));
    vertices.push_back(make_unique<Point<double>>(1, 1));
    vertices.push_back(make_unique<Point<double>>(0, 1));
    auto rect = make_shared<Rectangle<double>>(vertices);
    figures.add(rect);
    ASSERT_EQ(figures.size(), 1);
    figures.remove(0);
    ASSERT_EQ(figures.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
