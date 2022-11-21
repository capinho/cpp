cmake_minimum_required(VERSION 3.0)
project(cartesian_vector_param)

set(CMAKE_CXX_STANDARD 20)

add_executable(main my_sort.hpp main.cc)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
