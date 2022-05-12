cmake_minimum_required(VERSION 3.20)
project(cfg)

set(CMAKE_CXX_STANDARD 17)

add_executable(cfg main.cpp ds/graph.cpp includes/ds/graph.h misc/io.cpp includes/misc/hash.h includes/ds/edge.h includes/misc/io.h)
