#include <gtest/gtest.h>
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <memory>

TEST(PentagonTest, ConstructorAndGetters) {
    Point<double> center(1.0, 2.0);
    Pentagon<double> pentagon(center, 5.0);
    
    EXPECT_EQ(pentagon.getCenter().getX(), 1.0);
    EXPECT_EQ(pentagon.getCenter().getY(), 2.0);
    EXPECT_EQ(pentagon.getRadius(), 5.0);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon<double> pentagon(Point<double>(0, 0), 1.0);
    double expected_area = (5.0 / 2.0) * 1.0 * 1.0 * std::sin(2 * M_PI / 5);
    EXPECT_NEAR(pentagon.area(), expected_area, 1e-6);
}

TEST(PentagonTest, GeometricCenter) {
    Point<double> center(3.0, 4.0);
    Pentagon<double> pentagon(center, 2.0);
    
    Point<double> geometric_center = pentagon.geometricCenter();
    EXPECT_EQ(geometric_center.getX(), 3.0);
    EXPECT_EQ(geometric_center.getY(), 4.0);
}

TEST(PentagonTest, CopyConstructor) {
    Pentagon<double> original(Point<double>(1, 2), 3.0);
    Pentagon<double> copy(original);
    
    EXPECT_EQ(original.getCenter().getX(), copy.getCenter().getX());
    EXPECT_EQ(original.getCenter().getY(), copy.getCenter().getY());
    EXPECT_EQ(original.getRadius(), copy.getRadius());
}

TEST(PentagonTest, AssignmentOperator) {
    Pentagon<double> original(Point<double>(1, 2), 3.0);
    Pentagon<double> assigned = original;
    
    EXPECT_EQ(original.getCenter().getX(), assigned.getCenter().getX());
    EXPECT_EQ(original.getCenter().getY(), assigned.getCenter().getY());
    EXPECT_EQ(original.getRadius(), assigned.getRadius());
}

TEST(PentagonTest, EqualityOperator) {
    Pentagon<double> p1(Point<double>(1, 2), 3.0);
    Pentagon<double> p2(Point<double>(1, 2), 3.0);
    Pentagon<double> p3(Point<double>(1, 2), 4.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PentagonTest, CloneMethod) {
    Pentagon<double> original(Point<double>(1, 2), 3.0);
    std::unique_ptr<Figure<double>> clone(original.clone());
    
    EXPECT_TRUE(original == *clone);
}

TEST(HexagonTest, ConstructorAndGetters) {
    Point<double> center(2.0, 3.0);
    Hexagon<double> hexagon(center, 4.0);
    
    EXPECT_EQ(hexagon.getCenter().getX(), 2.0);
    EXPECT_EQ(hexagon.getCenter().getY(), 3.0);
    EXPECT_EQ(hexagon.getRadius(), 4.0);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon<double> hexagon(Point<double>(0, 0), 2.0);
    double expected_area = (3 * std::sqrt(3) / 2) * 4.0; // radius^2 = 4
    EXPECT_NEAR(hexagon.area(), expected_area, 1e-6);
}

TEST(HexagonTest, GeometricCenter) {
    Point<double> center(0.0, 5.0);
    Hexagon<double> hexagon(center, 3.0);
    
    Point<double> geometric_center = hexagon.geometricCenter();
    EXPECT_EQ(geometric_center.getX(), 0.0);
    EXPECT_EQ(geometric_center.getY(), 5.0);
}

TEST(HexagonTest, CopyConstructor) {
    Hexagon<double> original(Point<double>(2, 3), 4.0);
    Hexagon<double> copy(original);
    
    EXPECT_EQ(original.getCenter().getX(), copy.getCenter().getX());
    EXPECT_EQ(original.getCenter().getY(), copy.getCenter().getY());
    EXPECT_EQ(original.getRadius(), copy.getRadius());
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon<double> h1(Point<double>(1, 1), 2.0);
    Hexagon<double> h2(Point<double>(1, 1), 2.0);
    Hexagon<double> h3(Point<double>(1, 1), 3.0);
    
    EXPECT_TRUE(h1 == h2);
    EXPECT_FALSE(h1 == h3);
}

TEST(OctagonTest, ConstructorAndGetters) {
    Point<double> center(0.0, 1.0);
    Octagon<double> octagon(center, 3.0);
    
    EXPECT_EQ(octagon.getCenter().getX(), 0.0);
    EXPECT_EQ(octagon.getCenter().getY(), 1.0);
    EXPECT_EQ(octagon.getRadius(), 3.0);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon<double> octagon(Point<double>(0, 0), 1.0);
    double expected_area = 2 * (1 + std::sqrt(2)) * 1.0;
    EXPECT_NEAR(octagon.area(), expected_area, 1e-6);
}

TEST(OctagonTest, GeometricCenter) {
    Point<double> center(-1.0, -2.0);
    Octagon<double> octagon(center, 5.0);
    
    Point<double> geometric_center = octagon.geometricCenter();
    EXPECT_EQ(geometric_center.getX(), -1.0);
    EXPECT_EQ(geometric_center.getY(), -2.0);
}

TEST(OctagonTest, CopyConstructor) {
    Octagon<double> original(Point<double>(-1, -2), 5.0);
    Octagon<double> copy(original);
    
    EXPECT_EQ(original.getCenter().getX(), copy.getCenter().getX());
    EXPECT_EQ(original.getCenter().getY(), copy.getCenter().getY());
    EXPECT_EQ(original.getRadius(), copy.getRadius());
}

TEST(OctagonTest, EqualityOperator) {
    Octagon<double> o1(Point<double>(0, 0), 1.0);
    Octagon<double> o2(Point<double>(0, 0), 1.0);
    Octagon<double> o3(Point<double>(0, 0), 2.0);
    
    EXPECT_TRUE(o1 == o2);
    EXPECT_FALSE(o1 == o3);
}

TEST(FigureTest, OperatorParentheses) {
    Pentagon<double> pentagon(Point<double>(0, 0), 2.0);
    double area1 = pentagon.area();
    double area2 = pentagon();
    
    EXPECT_DOUBLE_EQ(area1, area2);
}

TEST(FigureTest, DifferentTypesEquality) {
    Pentagon<double> pentagon(Point<double>(0, 0), 1.0);
    Hexagon<double> hexagon(Point<double>(0, 0), 1.0);
    
    // Разные типы фигур не должны быть равны
    EXPECT_FALSE(pentagon == hexagon);
}

TEST(FigureTest, PrintVertices) {
    Pentagon<double> pentagon(Point<double>(0, 0), 1.0);
    
    testing::internal::CaptureStdout();
    pentagon.printVertices();
    std::string output = testing::internal::GetCapturedStdout();
    
    // Проверяем, что вывод содержит ожидаемый текст
    EXPECT_TRUE(output.find("Pentagon vertices") != std::string::npos);
}

TEST(FigureTest, GetVertices) {
    Pentagon<double> pentagon(Point<double>(0, 0), 1.0);
    auto vertices = pentagon.getVertices();
    
    EXPECT_EQ(vertices.size(), 5);
    
    // Проверяем, что все вершины находятся на расстоянии 1 от центра
    for (const auto& vertex : vertices) {
        double distance = std::sqrt(std::pow(vertex.getX(), 2) + std::pow(vertex.getY(), 2));
        EXPECT_NEAR(distance, 1.0, 1e-6);
    }
}