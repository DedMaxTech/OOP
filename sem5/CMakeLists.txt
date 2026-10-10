cmake_minimum_required(VERSION 3.20)
project(hypotenuse LANGUAGES CXX)

add_subdirectory(my_lib)
add_executable(hypotenuse main.cpp)
target_link_libraries(hypotenuse PRIVATE my_lib)

option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
