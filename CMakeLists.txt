cmake_minimum_required(VERSION 3.20)
project(course_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(course_4 main.cpp headers/graph/edge.h src/graph/graph.cpp headers/graph/graph.h headers/iterator/iterator.h headers/list/list.h headers/map/map.h src/maxFlowProblem/maxFlowCalculation.cpp headers/maxFlowProblem/maxFlowCalculation.h headers/pair/pair.h headers/queue/queue.h headers/map/rbtree.h)
add_subdirectory(Google_tests)