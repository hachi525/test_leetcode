cmake_minimum_required(VERSION 3.22)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp tinyxml.h Test/graph/Union_Find.cpp Test/graph/Union_Find.h)
add_executable(Test L1508_rangeSum.cpp O115_sequenceReconstruction.cpp O115_sequenceReconstruction.h Test.cpp Test.h L593_validSquare.cpp L593_validSquare.h L952_largestComponentSize.cpp L952_largestComponentSize.h L655_paintTree.cpp L655_paintTree.h test_epoll.cpp)
add_executable(Test1 L565_arrayNesting.cpp socketTest.cpp L782_movesToChessboard.cpp L782_movesToChessboard.h)
add_executable(Test2 Test.cpp "L295_MedianFinder .cpp")
add_executable(Test4 huawei_minGraphLength.cpp)