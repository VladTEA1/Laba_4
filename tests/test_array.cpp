#include <gtest/gtest.h>
#include "../include/Array.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <memory>

TEST(ArrayTest, DefaultConstructor) {
    Array<Figure<double>> array;
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.capacity(), 0);
}

TEST(ArrayTest, AddAndSize) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    
    array.add(pentagon);
    EXPECT_EQ(array.size(), 1);
}

TEST(ArrayTest, AddRawPointer) {
    Array<Figure<double>> array;
    auto* pentagon = new Pentagon<double>(Point<double>(0, 0), 1.0);
    
    array.add(pentagon);
    EXPECT_EQ(array.size(), 1);
}

TEST(ArrayTest, RemoveElement) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    auto hexagon = std::make_shared<Hexagon<double>>(Point<double>(1, 1), 2.0);
    
    array.add(pentagon);
    array.add(hexagon);
    EXPECT_EQ(array.size(), 2);
    
    array.remove(0);
    EXPECT_EQ(array.size(), 1);
    
    // Проверяем, что остался hexagon
    EXPECT_EQ(array[0]->geometricCenter().getX(), 1.0);
    EXPECT_EQ(array[0]->geometricCenter().getY(), 1.0);
}

TEST(ArrayTest, RemoveInvalidIndex) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    array.add(pentagon);
    
    // Попытка удалить несуществующий индекс не должна вызывать ошибку
    EXPECT_NO_THROW(array.remove(5));
    EXPECT_EQ(array.size(), 1); // Размер не должен измениться
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<Figure<double>> array;
    
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    auto hexagon = std::make_shared<Hexagon<double>>(Point<double>(0, 0), 1.0);
    
    array.add(pentagon);
    array.add(hexagon);
    
    double total_area = array.totalArea();
    double expected_total = pentagon->area() + hexagon->area();
    
    EXPECT_NEAR(total_area, expected_total, 1e-6);
}

TEST(ArrayTest, TotalAreaEmptyArray) {
    Array<Figure<double>> array;
    
    double total_area = array.totalArea();
    EXPECT_DOUBLE_EQ(total_area, 0.0);
}

TEST(ArrayTest, IndexOperator) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(2.0, 3.0), 1.0);
    
    array.add(pentagon);
    
    EXPECT_EQ(array[0]->geometricCenter().getX(), 2.0);
    EXPECT_EQ(array[0]->geometricCenter().getY(), 3.0);
}

TEST(ArrayTest, IndexOperatorConst) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(2.0, 3.0), 1.0);
    array.add(pentagon);
    
    const Array<Figure<double>>& const_array = array;
    EXPECT_EQ(const_array[0]->geometricCenter().getX(), 2.0);
    EXPECT_EQ(const_array[0]->geometricCenter().getY(), 3.0);
}

TEST(ArrayTest, ReserveAndCapacity) {
    Array<Figure<double>> array;
    
    size_t initial_capacity = array.capacity();
    array.reserve(20);
    
    EXPECT_GE(array.capacity(), 20);
    if (initial_capacity < 20) {
        EXPECT_GT(array.capacity(), initial_capacity);
    }
}

TEST(ArrayTest, ReserveSmallerCapacity) {
    Array<Figure<double>> array;
    array.reserve(10);
    size_t capacity_after_first_reserve = array.capacity();
    
    // Резервирование меньшего размера не должно изменить capacity
    array.reserve(5);
    EXPECT_EQ(array.capacity(), capacity_after_first_reserve);
}

TEST(ArrayTest, IteratorSupport) {
    Array<Figure<double>> array;
    
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    auto hexagon = std::make_shared<Hexagon<double>>(Point<double>(1, 1), 2.0);
    
    array.add(pentagon);
    array.add(hexagon);
    
    int count = 0;
    for (const auto& figure : array) {
        ++count;
    }
    
    EXPECT_EQ(count, 2);
}

TEST(ArrayTest, IteratorModification) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    array.add(pentagon);
    
    for (auto& figure : array) {
        // Можно получить доступ к методам фигуры
        EXPECT_EQ(figure->geometricCenter().getX(), 0.0);
        EXPECT_EQ(figure->geometricCenter().getY(), 0.0);
    }
}

TEST(ArrayTest, MixedFigures) {
    Array<Figure<double>> array;
    
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    auto hexagon = std::make_shared<Hexagon<double>>(Point<double>(1, 1), 2.0);
    auto octagon = std::make_shared<Octagon<double>>(Point<double>(2, 2), 3.0);
    
    array.add(pentagon);
    array.add(hexagon);
    array.add(octagon);
    
    EXPECT_EQ(array.size(), 3);
    
    // Проверяем, что все фигуры сохранили свои свойства
    EXPECT_EQ(array[0]->geometricCenter().getX(), 0.0);
    EXPECT_EQ(array[1]->geometricCenter().getX(), 1.0);
    EXPECT_EQ(array[2]->geometricCenter().getX(), 2.0);
}

TEST(ArrayTest, PrintMethods) {
    Array<Figure<double>> array;
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(1, 2), 3.0);
    array.add(pentagon);
    
    // Проверяем, что методы print не падают с ошибкой
    EXPECT_NO_THROW(array.printAllGeometricCenters());
    EXPECT_NO_THROW(array.printAllVertices());
    EXPECT_NO_THROW(array.printAllAreas());
}

TEST(ArrayTest, ClearByRemovingAll) {
    Array<Figure<double>> array;
    
    auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(0, 0), 1.0);
    auto hexagon = std::make_shared<Hexagon<double>>(Point<double>(1, 1), 2.0);
    
    array.add(pentagon);
    array.add(hexagon);
    EXPECT_EQ(array.size(), 2);
    
    // Удаляем все элементы
    array.remove(0);
    array.remove(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(ArrayTest, MoveSemanticsOnReserve) {
    Array<Figure<double>> array;
    
    // Добавляем несколько фигур
    for (int i = 0; i < 5; ++i) {
        auto pentagon = std::make_shared<Pentagon<double>>(Point<double>(i, i), 1.0);
        array.add(pentagon);
    }
    
    size_t initial_size = array.size();
    array.reserve(20); // Должен использовать move семантику
    
    EXPECT_EQ(array.size(), initial_size); // Размер не должен измениться
    EXPECT_GE(array.capacity(), 20); // Capacity должен увеличиться
}