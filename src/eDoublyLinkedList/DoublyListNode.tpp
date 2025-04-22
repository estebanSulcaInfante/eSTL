//
// Created by esulca on 15/04/25.
//
#ifndef DOUBLYLISTNODE_TPP
#define DOUBLYLISTNODE_TPP
#include "eDoublyLinkedList/DoublyListNode.h"

template <typename T>
DoublyListNode<T>::DoublyListNode(): val(T()), next(nullptr), prev(nullptr){}

template<typename T>
DoublyListNode<T>::DoublyListNode(T val): next(nullptr), prev(nullptr) {
    this.val = val;
}

#endif
