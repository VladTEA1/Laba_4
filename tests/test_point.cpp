#include <gtest/gtest.h>
#include "../include/Point.h"

TEST(PointTest, DefaultConstructor) {
    Point<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), 4.2);
}

TEST(PointTest, SettersAndGetters) {
    Point<float> p;
    p.setX(1.1f);
    p.setY(2.2f);
    EXPECT_FLOAT_EQ(p.getX(), 1.1f);
    EXPECT_FLOAT_EQ(p.getY(), 2.2f);
}

TEST(PointTest, DistanceCalculation) {
    Point<int> p1(0, 0);
    Point<int> p2(3, 4);
    EXPECT_DOUBLE_EQ(p1.distanceTo(p2), 5.0);
}

TEST(PointTest, EqualityOperator) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(1.0, 3.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, AssignmentOperator) {
    Point<int> p1(5, 10);
    Point<int> p2;
    p2 = p1;
    
    EXPECT_EQ(p2.getX(), 5);
    EXPECT_EQ(p2.getY(), 10);
}

TEST(PointTest, OutputOperator) {
    Point<int> p(10, 20);
    testing::internal::CaptureStdout();
    std::cout << p;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(10, 20)");
}   