cmake_minimum_required(VERSION 3.16)
project(hypotenuse LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(hypotenuse main.cpp hypotenuse.cpp random_hypotenuse.cpp)
