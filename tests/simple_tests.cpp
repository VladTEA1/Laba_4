#include <iostream>
#include <memory>
#include <cmath>
#include "../include/Point.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include "../include/Array.h"

bool test_point() {
    std::cout << "Test Point: ";
    
    Point<double> p1(2.0, 3.0);
    if (p1.getX() != 2.0 || p1.getY() != 3.0) {
        std::cout << "FAIL - constructor\n";
        return false;
    }
    
    Point<double> p2(0, 0), p3(3, 4);
    double dist = p2.distanceTo(p3);
    if (std::abs(dist - 5.0) > 0.001) {
        std::cout << "FAIL - distance\n";
        return false;
    }
    
    std::cout << "PASS\n";
    return true;
}

bool test_pentagon() {
    std::cout << "Test Pentagon: ";
    
    Pentagon<double> pentagon(Point<double>(1, 1), 2.0);
    
    if (pentagon.getRadius() != 2.0) {
        std::cout << "FAIL - radius\n";
        return false;
    }
    
    double area = pentagon.area();
    if (area <= 0) {
        std::cout << "FAIL - area\n";
        return false;
    }
    
    auto vertices = pentagon.getVertices();
    if (vertices.size() != 5) {
        std::cout << "FAIL - vertices count\n";
        return false;
    }
    
    std::cout << "PASS (area=" << area << ")\n";
    return true;
}

bool test_hexagon() {
    std::cout << "Test Hexagon: ";
    
    Hexagon<double> hexagon(Point<double>(0, 0), 3.0);
    
    if (hexagon.getRadius() != 3.0) {
        std::cout << "FAIL - radius\n";
        return false;
    }
    
    double area = hexagon.area();
    if (area <= 0) {
        std::cout << "FAIL - area\n";
        return false;
    }
    
    std::cout << "PASS (area=" << area << ")\n";
    return true;
}

bool test_octagon() {
    std::cout << "Test Octagon: ";
    
    Octagon<double> octagon(Point<double>(2, 2), 4.0);
    
    if (octagon.getRadius() != 4.0) {
        std::cout << "FAIL - radius\n";
        return false;
    }
    
    double area = octagon.area();
    if (area <= 0) {
        std::cout << "FAIL - area\n";
        return false;
    }
    
    std::cout << "PASS (area=" << area << ")\n";
    return true;
}

bool test_array() {
    std::cout << "Test Array: ";
    
    Array<Figure<double>> arr;
    
    if (arr.size() != 0) {
        std::cout << "FAIL - initial size\n";
        return false;
    }
    
    arr.add(std::make_shared<Pentagon<double>>(Point<double>(0,0), 1.0));
    arr.add(std::make_shared<Hexagon<double>>(Point<double>(1,1), 2.0));
    
    if (arr.size() != 2) {
        std::cout << "FAIL - size after add\n";
        return false;
    }
    
    double total = arr.totalArea();
    if (total <= 0) {
        std::cout << "FAIL - total area\n";
        return false;
    }
    
    arr.remove(0);
    if (arr.size() != 1) {
        std::cout << "FAIL - size after remove\n";
        return false;
    }
    
    std::cout << "PASS (total area=" << total << ")\n";
    return true;
}

int main() {
    std::cout << "Starting tests...\n\n";
    
    int passed = 0;
    int total = 5;
    
    if (test_point()) passed++;
    if (test_pentagon()) passed++;
    if (test_hexagon()) passed++;
    if (test_octagon()) passed++;
    if (test_array()) passed++;
    
    std::cout << "\nResults: " << passed << "/" << total << " tests passed\n";
    
    if (passed == total) {
        std::cout << "All tests passed\n";
        return 0;
    } else {
        std::cout << "Some tests failed\n";
        return 1;
    }
}