cmake_minimum_required(VERSION 3.10)

project(CppLab)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppLab src/main.cpp src/Rectangle.cpp src/Trapezoid.cpp src/Rhombus.cpp src/Array.cpp)

target_include_directories(CppLab PRIVATE include)

enable_testing()

add_subdirectory(tests)
