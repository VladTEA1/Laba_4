#include "../include/Figure.h"

template<class T>
double Figure<T>::operator()() const {
    return area();
}

// Explicit instantiation
template class Figure<int>;
template class Figure<double>;
template class Figure<float>;