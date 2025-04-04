cmake_minimum_required(VERSION 3.10)

project(eSTL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(eSTL main.cpp
        include/eStl/eLinkedList/eLinkedList.h)

# Add source files
target_sources(eSTL PRIVATE src/eLinkedList/eLinkedList.cpp)
