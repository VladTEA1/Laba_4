#include "../include/Point.h"

template<class T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<class T>
T Point<T>::getX() const { return x; }

template<class T>
T Point<T>::getY() const { return y; }

template<class T>
void Point<T>::setX(T x_val) { x = x_val; }

template<class T>
void Point<T>::setY(T y_val) { y = y_val; }

template<class T>
double Point<T>::distanceTo(const Point<T>& other) const {
    return std::sqrt(std::pow(static_cast<double>(x - other.x), 2) + 
                     std::pow(static_cast<double>(y - other.y), 2));
}

template<class T>
bool Point<T>::operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
}

template<class T>
Point<T>& Point<T>::operator=(const Point<T>& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Explicit instantiation for common types
template class Point<int>;
template class Point<double>;
template class Point<float>;