cmake_minimum_required(VERSION 3.14)
project(FigureTests)

# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)

# Include directories
include_directories(
    ../include
    ${CMAKE_SOURCE_DIR}/include
)

# Add executable for tests
add_executable(
    FigureTests
    test_main.cpp
    test_point.cpp
    test_figures.cpp
    test_array.cpp
)

# Link with GoogleTest and our library
target_link_libraries(
    FigureTests
    GTest::gtest_main
    FigureLibrary
)

# Add test
add_test(
    NAME FigureTests
    COMMAND FigureTests
)

# Set properties for test
set_tests_properties(FigureTests PROPERTIES TIMEOUT 60)