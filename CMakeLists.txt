cmake_minimum_required(VERSION 3.29)
project(Project3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_PREFIX_PATH )

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(Project3
        src/main.cpp
        src/sort_window.cpp
        src/sort_window.h
        src/helper.cpp
        src/helper.h
        src/quick_sort.cpp
        src/quick_sort.h
        src/merge_sort.cpp
        src/merge_sort.h
        src/sorting_helper.h
)

target_link_libraries(Project3 Qt6::Widgets)
set(BUILD_SHARED_LIBS OFF)
