#include "../include/Hexagon.h"
#include <cmath>
#include <vector>

// Определяем PI вручную
constexpr double PI = 3.14159265358979323846;

template<class T>
Hexagon<T>::Hexagon(Point<T> center, T radius) 
    : center(std::make_unique<Point<T>>(center)), radius(radius) {}

template<class T>
Hexagon<T>::Hexagon(const Hexagon<T>& other) 
    : center(std::make_unique<Point<T>>(*other.center)), radius(other.radius) {}

template<class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other) {
    if (this != &other) {
        center = std::make_unique<Point<T>>(*other.center);
        radius = other.radius;
    }
    return *this;
}

template<class T>
double Hexagon<T>::area() const {
    return (3 * std::sqrt(3) / 2) * static_cast<double>(radius) * static_cast<double>(radius);
}

template<class T>
Point<T> Hexagon<T>::geometricCenter() const {
    return *center;
}

template<class T>
void Hexagon<T>::printVertices() const {
    std::cout << "Hexagon vertices: ";
    for (int i = 0; i < 6; ++i) {
        double angle = 2 * PI * i / 6;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        std::cout << "(" << x << ", " << y << ") ";
    }
    std::cout << std::endl;
}

template<class T>
std::vector<Point<T>> Hexagon<T>::getVertices() const {
    std::vector<Point<T>> vertices;
    for (int i = 0; i < 6; ++i) {
        double angle = 2 * PI * i / 6;
        T x = center->getX() + radius * static_cast<T>(std::cos(angle));
        T y = center->getY() + radius * static_cast<T>(std::sin(angle));
        vertices.emplace_back(x, y);
    }
    return vertices;
}

template<class T>
bool Hexagon<T>::operator==(const Figure<T>& other) const {
    const Hexagon<T>* hexagon = dynamic_cast<const Hexagon<T>*>(&other);
    if (!hexagon) return false;
    return *center == *(hexagon->center) && radius == hexagon->radius;
}

template<class T>
Figure<T>* Hexagon<T>::clone() const {
    return new Hexagon<T>(*this);
}

template<class T>
T Hexagon<T>::getRadius() const { return radius; }

template<class T>
Point<T> Hexagon<T>::getCenter() const { return *center; }

// Explicit instantiation
template class Hexagon<int>;
template class Hexagon<double>;
template class Hexagon<float>;