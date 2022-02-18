cmake_minimum_required(VERSION 3.16)
project(acmicpc)

include (CTest)

add_executable(tests test.cpp 
					 testcases.cpp)

add_test(test-1 tests)