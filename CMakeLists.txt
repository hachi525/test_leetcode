cmake_minimum_required(VERSION 3.22)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp tinyxml.h Test/graph/Union_Find.cpp Test/graph/Union_Find.h L850_rectangleArea.cpp)
add_executable(Thread Thread_Test.cpp)
add_executable(Test1 L1640_canFormArray.cpp)
add_executable(Daily Test.cpp)
add_executable(shuati bishi_test.cpp)