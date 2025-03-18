cmake_minimum_required(VERSION 3.14)
project(problem-2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent) 
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    prob2
    main.cpp
    util.h
    util.cpp
)

add_executable(
    prob2b
    main-2b.cpp
    util.h
    util.cpp
)

add_executable(
    prob2_test
    tests.cpp
    util.h
    util.cpp
)

target_link_libraries(
    prob2_test
    GTest::gtest_main
   
)

include(GoogleTest)
gtest_discover_tests(prob2_test)