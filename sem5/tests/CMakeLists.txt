cmake_minimum_required(VERSION 3.14)
project(hypotenuse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(my_tests test.cpp)
add_subdirectory(../my_lib ${CMAKE_CURRENT_BINARY_DIR}/my_lib_build)
target_link_libraries(my_tests PUBLIC my_lib GTest::gtest_main)

# target_link_libraries(
#   my_tests
  
# )

include(GoogleTest)
gtest_discover_tests(my_tests)