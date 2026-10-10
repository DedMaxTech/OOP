cmake_minimum_required(VERSION 3.16)
project(algo LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(class main.cpp class.h)



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(my_tests test.cpp)
target_link_libraries(my_tests PRIVATE GTest::gtest_main)