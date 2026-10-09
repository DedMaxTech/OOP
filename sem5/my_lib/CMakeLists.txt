add_library(my_lib INTERFACE)
target_include_directories(my_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(my_lib INTERFACE cxx_std_17)
