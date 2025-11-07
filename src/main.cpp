#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include "../include/Array.h"
#include <iostream>
#include <memory>

template<class T>
std::shared_ptr<Figure<T>> createPentagonFromInput() {
    T x, y, radius;
    std::cout << "Enter pentagon center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter pentagon radius: ";
    std::cin >> radius;
    return std::make_shared<Pentagon<T>>(Point<T>(x, y), radius);
}

template<class T>
std::shared_ptr<Figure<T>> createHexagonFromInput() {
    T x, y, radius;
    std::cout << "Enter hexagon center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter hexagon radius: ";
    std::cin >> radius;
    return std::make_shared<Hexagon<T>>(Point<T>(x, y), radius);
}

template<class T>
std::shared_ptr<Figure<T>> createOctagonFromInput() {
    T x, y, radius;
    std::cout << "Enter octagon center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter octagon radius: ";
    std::cin >> radius;
    return std::make_shared<Octagon<T>>(Point<T>(x, y), radius);
}

template<class T>
void demonstrateArrayOperations() {
    Array<Figure<T>> figures;
    
    std::cout << "\n=== Demonstrating Array Operations ===" << std::endl;
    
    // Добавление фигур
    figures.add(std::make_shared<Pentagon<T>>(Point<T>(0, 0), 5));
    figures.add(std::make_shared<Hexagon<T>>(Point<T>(1, 1), 3));
    figures.add(std::make_shared<Octagon<T>>(Point<T>(2, 2), 4));
    
    std::cout << "Initial figures count: " << figures.size() << std::endl;
    std::cout << "Initial capacity: " << figures.capacity() << std::endl;
    
    // Демонстрация операций
    figures.printAllGeometricCenters();
    figures.printAllAreas();
    std::cout << "Total area: " << figures.totalArea() << std::endl;
    
    // Увеличение capacity с использованием move
    std::cout << "\nReserving more capacity..." << std::endl;
    figures.reserve(10);
    std::cout << "New capacity: " << figures.capacity() << std::endl;
    
    // Удаление фигуры
    std::cout << "\nRemoving figure at index 1..." << std::endl;
    figures.remove(1);
    std::cout << "Figures count after removal: " << figures.size() << std::endl;
    figures.printAllAreas();
}

int main() {
    Array<Figure<double>> figures;
    
    std::cout << "=== Figure Management System ===" << std::endl;
    
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Pentagon\n";
        std::cout << "2. Add Hexagon\n";
        std::cout << "3. Add Octagon\n";
        std::cout << "4. Show all figures\n";
        std::cout << "5. Remove figure by index\n";
        std::cout << "6. Show total area\n";
        std::cout << "7. Demonstrate array operations\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose option: ";
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                figures.add(createPentagonFromInput<double>());
                break;
            case 2:
                figures.add(createHexagonFromInput<double>());
                break;
            case 3:
                figures.add(createOctagonFromInput<double>());
                break;
            case 4:
                std::cout << "\nAll figures:\n";
                figures.printAllGeometricCenters();
                figures.printAllVertices();
                figures.printAllAreas();
                break;
            case 5: {
                std::cout << "Enter index to remove: ";
                size_t index;
                std::cin >> index;
                if (index < figures.size()) {
                    figures.remove(index);
                    std::cout << "Figure removed.\n";
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            case 6:
                std::cout << "Total area of all figures: " << figures.totalArea() << std::endl;
                break;
            case 7:
                demonstrateArrayOperations<double>();
                break;
            case 8:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }
    
    return 0;
}