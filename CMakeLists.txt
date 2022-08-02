cmake_minimum_required(VERSION 3.4)

project(fraction)

add_library(fraction src/fraction/fraction.cpp)

target_include_directories(fraction PUBLIC include)

add_executable(test examples/sandbox/main.cpp)

target_include_directories(test PRIVATE include)
target_link_libraries(test PRIVATE fraction)