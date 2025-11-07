#pragma once
#include <iostream>
#include <memory>
#include <cmath>
#include <type_traits>

template<class T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0);
    
    T getX() const;
    T getY() const;
    void setX(T x_val);
    void setY(T y_val);
    
    double distanceTo(const Point<T>& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    bool operator==(const Point<T>& other) const;
    Point<T>& operator=(const Point<T>& other);
};