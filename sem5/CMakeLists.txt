cmake_minimum_required(VERSION 3.16)
project(hypotenuse LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)	

add_subdirectory(my_lib)
add_executable(hypotenuse main.cpp)

target_link_libraries(hypotenuse PUBLIC my_lib)
