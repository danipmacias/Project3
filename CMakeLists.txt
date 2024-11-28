cmake_minimum_required(VERSION 3.29)
project(Project3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project3
        src/helper.cpp
        src/main.cpp
        src/helper.h
        src/merge_sort.cpp
        src/quick_sort.cpp
        src/quick_sort.h)

# Set the working directory to the root of the project
set_target_properties(Project3 PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")