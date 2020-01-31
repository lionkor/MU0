cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-c++11-compat-binary-literal")

project(MU0)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories(Catch2/single_include/catch2)

project(tests)

add_executable(${CMAKE_PROJECT_NAME} 
    tests/tests.cpp
    tests/test_bitops.cpp
)

