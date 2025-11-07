#include "../include/Octagon.h"
#include <cmath>
#include <vector>

// Определяем PI вручную
constexpr double PI = 3.14159265358979323846;

template<class T>
Octagon<T>::Octagon(Point<T> center, T radius) 
    : center(std::make_unique<Point<T>>(center)), radius(radius) {}

template<class T>
Octagon<T>::Octagon(const Octagon<T>& other) 
    : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}

template<class T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& other) {
    if (this != &other) {
        center = std::make_unique<Point<T>>(*other.center);
        radius = other.radius;
    }
    return *this;
}

template<class T>
double Octagon<T>::area() const {
    return 2 * (1 + std::sqrt(2)) * static_cast<double>(radius) * static_cast<double>(radius);
}

template<class T>
Point<T> Octagon<T>::geometricCenter() const {
    return *center;
}

template<class T>
void Octagon<T>::printVertices() const {
    std::cout << "Octagon vertices: ";
    for (int i = 0; i < 8; ++i) {
        double angle = 2 * PI * i / 8;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        std::cout << "(" << x << ", " << y << ") ";
    }
    std::cout << std::endl;
}

template<class T>
std::vector<Point<T>> Octagon<T>::getVertices() const {
    std::vector<Point<T>> vertices;
    for (int i = 0; i < 8; ++i) {
        double angle = 2 * PI * i / 8;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        vertices.emplace_back(x, y);
    }
    return vertices;
}

template<class T>
bool Octagon<T>::operator==(const Figure<T>& other) const {
    const Octagon<T>* octagon = dynamic_cast<const Octagon<T>*>(&other);
    if (!octagon) return false;
    return *center == *(octagon->center) && radius == octagon->radius;
}

template<class T>
Figure<T>* Octagon<T>::clone() const {
    return new Octagon<T>(*this);
}

template<class T>
T Octagon<T>::getRadius() const { return radius; }

template<class T>
Point<T> Octagon<T>::getCenter() const { return *center; }

// Explicit instantiation
template class Octagon<int>;
template class Octagon<double>;
template class Octagon<float>;