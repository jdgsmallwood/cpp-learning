cmake_minimum_required(VERSION 3.14)
project(problem-1)

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
    prob1
    prob-1.cpp
    util.h
    util.cpp
)

add_executable(
    prob1_test
    tests.cpp
    util.h
    util.cpp
)

target_link_libraries(
    prob1_test
    GTest::gtest_main
   
)

include(GoogleTest)
gtest_discover_tests(prob1_test)