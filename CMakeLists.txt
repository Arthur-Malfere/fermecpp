cmake_minimum_required(VERSION 3.10.0)
project(fermecpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(fermecpp ${SOURCES})

if(MSVC)
    target_compile_options(fermecpp PRIVATE /W4)
else()
    target_compile_options(fermecpp PRIVATE -Wall -Wextra -pedantic)
endif()

