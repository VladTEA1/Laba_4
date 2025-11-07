#include "../include/Pentagon.h"
#include <cmath>
#include <vector>

// Определяем PI вручную
constexpr double PI = 3.14159265358979323846;

template<class T>
Pentagon<T>::Pentagon(Point<T> center, T radius) 
    : center(std::make_unique<Point<T>>(center)), radius(radius) {}

template<class T>
Pentagon<T>::Pentagon(const Pentagon<T>& other) 
    : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}

template<class T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T>& other) {
    if (this != &other) {
        center = std::make_unique<Point<T>>(*other.center);
        radius = other.radius;
    }
    return *this;
}

template<class T>
double Pentagon<T>::area() const {
    return (5.0 / 2.0) * static_cast<double>(radius) * static_cast<double>(radius) * 
           std::sin(2 * PI / 5);
}

template<class T>
Point<T> Pentagon<T>::geometricCenter() const {
    return *center;
}

template<class T>
void Pentagon<T>::printVertices() const {
    std::cout << "Pentagon vertices: ";
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * PI * i / 5;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        std::cout << "(" << x << ", " << y << ") ";
    }
    std::cout << std::endl;
}

template<class T>
std::vector<Point<T>> Pentagon<T>::getVertices() const {
    std::vector<Point<T>> vertices;
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * PI * i / 5;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        vertices.emplace_back(x, y);
    }
    return vertices;
}

template<class T>
bool Pentagon<T>::operator==(const Figure<T>& other) const {
    const Pentagon<T>* pentagon = dynamic_cast<const Pentagon<T>*>(&other);
    if (!pentagon) return false;
    return *center == *(pentagon->center) && radius == pentagon->radius;
}

template<class T>
Figure<T>* Pentagon<T>::clone() const {
    return new Pentagon<T>(*this);
}

template<class T>
T Pentagon<T>::getRadius() const { return radius; }

template<class T>
Point<T> Pentagon<T>::getCenter() const { return *center; }

// Explicit instantiation
template class Pentagon<int>;
template class Pentagon<double>;
template class Pentagon<float>;