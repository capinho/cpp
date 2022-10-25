cmake_minimum_required(VERSION 3.0)
project(cartesian_vector_variable)

set(CMAKE_CXX_STANDARD 14)

add_executable(main vector.cpp main.cpp)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


