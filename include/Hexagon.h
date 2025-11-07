#pragma once
#include "Figure.h"
#include <vector>

template<class T>
class Hexagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T radius;
    
public:
    Hexagon(Point<T> center = Point<T>(), T radius = 1);
    Hexagon(const Hexagon<T>& other);
    Hexagon<T>& operator=(const Hexagon<T>& other);
    
    double area() const override;
    Point<T> geometricCenter() const override;
    void printVertices() const override;
    
    std::vector<Point<T>> getVertices() const;
    bool operator==(const Figure<T>& other) const override;
    Figure<T>* clone() const override;
    
    T getRadius() const;
    Point<T> getCenter() const;
};