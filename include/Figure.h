#pragma once
#include "Point.h"

template<class T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual double area() const = 0;
    virtual Point<T> geometricCenter() const = 0;
    virtual void printVertices() const = 0;
    virtual double operator()() const;
    
    virtual bool operator==(const Figure<T>& other) const = 0;
    virtual Figure<T>* clone() const = 0;
};