cmake_minimum_required(VERSION 3.5)
project(CSAPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES chapter_2.cpp)
add_executable(CSAPP ${SOURCE_FILES})