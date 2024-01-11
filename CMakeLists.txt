cmake_minimum_required(VERSION 3.5)
project(hw3 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_tests hw3_function.h hw3_function.cpp hw3_test.cpp catch.hpp)
add_executable(instructor_tests hw3_function.h hw3_function.cpp instructor_tests.cpp catch.hpp)

# enable testing
enable_testing()

add_test(instructor_tests instructor_tests)
add_test(student_tests student_tests)
