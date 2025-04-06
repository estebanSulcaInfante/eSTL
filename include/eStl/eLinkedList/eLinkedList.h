//
// Created by esteb on 04/04/2025.
//

#ifndef ESTL_ELINKEDLIST_H
#define ESTL_ELINKEDLIST_H
#include "iostream"

#include "Node.h"
template<typename T>
class eLinkedList {
    Node<T> *head;
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
    Node<T> *getMiddle(Node<T>* start);
    Node<T> *merge(Node<T> *left, Node<T> *right);
    Node<T> *mergeSort(Node<T> *start);
    void sort();
    void reverse();
    void show();
};




#include "../src/eLinkedList/eLinkedList.tpp"
#endif //ESTL_ELINKEDLIST_H
