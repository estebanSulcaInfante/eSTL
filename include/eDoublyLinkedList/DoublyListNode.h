//
// Created by esulca on 15/04/25.
//

#ifndef DOUBLYLISTNODE_H
#define DOUBLYLISTNODE_H


template<typename T>
struct DoublyListNode {
    T val;
    DoublyListNode *next;
    DoublyListNode *prev;

    DoublyListNode();
    explicit DoublyListNode(T val);

};

#include "../../src/eDoublyLinkedList/DoublyListNode.tpp"


#endif //DOUBLYLISTNODE_H
