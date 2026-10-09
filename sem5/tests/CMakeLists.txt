include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(my_tests test.cpp)
target_link_libraries(my_tests PRIVATE my_lib GTest::gtest_main)
add_custom_target(run_tests
    COMMAND $<TARGET_FILE:my_tests>
    DEPENDS my_tests
)
