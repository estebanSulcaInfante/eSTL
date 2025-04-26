cmake_minimum_required(VERSION 3.10)

project(eSTL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(eSTL main.cpp
        include/eSinglyLinkedList/eLinkedList.h
        include/eSinglyLinkedList/SinglyLinkedListNode.h
        src/eDoublyLinkedList/eDoublyLinkedList.tpp
        include/eDoublyLinkedList/eDoublyLinkedList.h
        src/eDoublyLinkedList/DoublyListNode.tpp
        include/eDoublyLinkedList/DoublyListNode.h
        tests/singlyLinkedListTest.h
        tests/doublyLinkedListTest.h
        include/eCircularDoublyLinkedList/eCircularDoublyLinkedList.h
        tests/circularDoublyLinkedListTest.h

)

# Add source files
target_sources(eSTL PUBLIC src/eSinglyLinkedList/eLinkedList.tpp
                    PUBLIC src/eSinglyLinkedList/SinglyLinkedListNode.tpp
)
