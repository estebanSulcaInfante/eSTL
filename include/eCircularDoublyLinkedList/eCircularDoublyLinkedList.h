// CircularDoublyLinkedList.h
#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include "eDoublyLinkedList/DoublyListNode.h"

template<class T>
class CircularDoublyLinkedList {
    DoublyListNode<T>* head;

public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    T front() const;             // O(1)
    T back() const;              // O(1)

    void push_front(const T&);   // O(1)
    void push_back(const T&);    // O(1)

    T pop_front();               // O(1)
    T pop_back();                // O(1)

    void insert(const T&, int);  // O(n)
    void remove(int);            // O(n)

    T operator[](int) const;     // O(n)

    bool empty() const;          // O(1)
    int size() const;            // O(n)

    void clear();                // O(n)
    void reverse();              // O(n)
};

#include "../src/eCircularDoublyLinkedList/eCircularDoublyLinkedList.tpp"
#endif // CIRCULARDOUBLYLINKEDLIST_H
