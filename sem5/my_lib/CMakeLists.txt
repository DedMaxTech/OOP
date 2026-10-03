add_library(my_lib STATIC hypotenuse.cpp random_hypotenuse.cpp hypotenuse.h random_hypotenuse.h)
target_include_directories(my_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
