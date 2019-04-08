cmake_minimum_required(VERSION 3.13)
project(algorithm_c)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(leetcode)

add_library(util util.c)

add_library(queue queue.c)