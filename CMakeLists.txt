cmake_minimum_required(VERSION 3.10)

project(eSTL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(eSTL main.cpp
        include/eLinkedList/eLinkedList.h
        include/eLinkedList/ForwardListNode.h
        src/eDoublyLinkedList/eDoublyLinkedList.tpp
        include/eDoublyLinkedList/eDoublyLinkedList.h
        src/eDoublyLinkedList/DoublyListNode.tpp
        include/eDoublyLinkedList/DoublyListNode.h

)

# Add source files
target_sources(eSTL PUBLIC src/eLinkedList/eLinkedList.tpp
                    PUBLIC src/eLinkedList/ForwardListNode.tpp
)
