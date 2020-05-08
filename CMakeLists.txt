cmake_minimum_required(VERSION 3.15)
project(MST)

set(CMAKE_CXX_STANDARD 11)

add_executable(MST main.cpp Graph.cpp Graph.h UnionFindDisjointSet.cpp UnionFindDisjointSet.h KruskalMSTAlgorithm.cpp KruskalMSTAlgorithm.h)