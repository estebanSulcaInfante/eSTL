//
// Created by esteb on 04/04/2025.
//

#ifndef ESTL_ELINKEDLIST_H
#define ESTL_ELINKEDLIST_H
#include "iostream"

#include "ForwardListNode.h"
template<typename T>
class eLinkedList {
    ForwardListNode<T> *head;
public:
    eLinkedList();
    ~eLinkedList();

    [[nodiscard]] bool empty() const;
    [[nodiscard]] int size() const;

    void push_front(T value);
    void push_back(T value);
    T front();
    T back();
    T pop_front();
    T pop_back();
    T operator[](int);
    int size();
    void clear();
    ForwardListNode<T> *getMiddle(ForwardListNode<T>* start);
    ForwardListNode<T> *merge(ForwardListNode<T> *left, ForwardListNode<T> *right);
    ForwardListNode<T> *mergeSort(ForwardListNode<T> *start);
    void sort();
    void reverse();
    void show();
};




#include "../src/eSinglyLinkedList/eLinkedList.tpp"
#endif //ESTL_ELINKEDLIST_H
