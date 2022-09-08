cmake_minimum_required(VERSION 3.22)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp tinyxml.h Test/graph/Union_Find.cpp Test/graph/Union_Find.h)
add_executable(Test L667_constructArray.cpp)
add_executable(Test1 L565_arrayNesting.cpp socketTest.cpp L782_movesToChessboard.cpp L782_movesToChessboard.h L793_premiageSize.cpp DS_graph.h)
add_executable(Test2 Test.cpp)
add_executable(Test4 huawei_DP_Soldier.cpp)