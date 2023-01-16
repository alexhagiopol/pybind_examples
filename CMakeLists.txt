cmake_minimum_required(VERSION 3.25)
project(example_functions)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_subdirectory(extern/pybind11)
pybind11_add_module(example_functions ExampleFunctions.cpp)
target_include_directories(example_functions PRIVATE extern/eigen)
