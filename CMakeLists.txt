cmake_minimum_required(VERSION 3.14)
project(Lab04)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Create library
add_library(FigureLibrary
    src/Point.cpp
    src/Figure.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
)

# Create main executable
add_executable(Lab04Main src/main.cpp)
target_link_libraries(Lab04Main FigureLibrary)

# Option to enable/disable tests
option(ENABLE_TESTS "Enable tests" ON)

if(ENABLE_TESTS)
    # Enable testing
    enable_testing()
    
    # Try to find GTest
    find_package(GTest)
    
    if(GTest_FOUND)
        message(STATUS "Google Test found, building tests")
        
        # Add tests subdirectory
        add_subdirectory(tests)
    else()
        message(WARNING "Google Test not found, tests will be disabled")
    endif()
else()
    message(STATUS "Tests disabled by user")
endif()