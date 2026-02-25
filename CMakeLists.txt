cmake_minimum_required(VERSION 3.10.0)
project(fermecpp VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(fermecpp ${SOURCES})

