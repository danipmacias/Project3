cmake_minimum_required(VERSION 3.29)
project(Project3)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_PREFIX_PATH "/usr/local/opt/qt")



add_executable(Project3
        src/helper.cpp
        src/main.cpp
        src/helper.h
        src/merge_sort.cpp
        src/quick_sort.cpp
        src/quick_sort.h
        src/main.cpp)

# Set the working directory to the root of the project
set_target_properties(Project3 PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

target_link_libraries(Project3 Qt6::Widgets)
