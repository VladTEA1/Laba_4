#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Figure.h"

template<class T>
class Array {
private:
    std::vector<std::shared_ptr<T>> data;
    
public:
    Array() = default;
    
    void add(const std::shared_ptr<T>& element) {
        data.push_back(element);
    }
    
    void add(T* element) {
        data.emplace_back(element);
    }
    
    void remove(size_t index) {
        if (index < data.size()) {
            data.erase(data.begin() + index);
        }
    }
    
    size_t size() const {
        return data.size();
    }
    
    size_t capacity() const {
        return data.capacity();
    }
    
    std::shared_ptr<T>& operator[](size_t index) {
        return data[index];
    }
    
    const std::shared_ptr<T>& operator[](size_t index) const {
        return data[index];
    }
    
    void reserve(size_t new_capacity) {
        if (new_capacity > data.capacity()) {
            std::vector<std::shared_ptr<T>> new_data;
            new_data.reserve(new_capacity);
            for (auto& item : data) {
                new_data.push_back(std::move(item));
            }
            data = std::move(new_data);
        }
    }
    
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
    
    double totalArea() const {
        double total = 0;
        for (const auto& figure : data) {
            total += figure->area();
        }
        return total;
    }
    
    void printAllGeometricCenters() const {
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << "Figure " << i << " geometric center: " 
                      << data[i]->geometricCenter() << std::endl;
        }
    }
    
    void printAllVertices() const {
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << "Figure " << i << " ";
            data[i]->printVertices();
        }
    }
    
    void printAllAreas() const {
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << "Figure " << i << " area: " << data[i]->area() << std::endl;
        }
    }
};