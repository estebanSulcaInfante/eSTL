//
// Created by esteb on 04/04/2025.
//
#ifndef ESTL_ELINKEDLIST_TPP
#define ESTL_ELINKEDLIST_TPP

#include "eLinkedList/eLinkedList.h"

template <typename T>
eLinkedList<T>::eLinkedList() : head(nullptr){}

template <typename T>
eLinkedList<T>::~eLinkedList() {
    ForwardListNode<T> *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
bool eLinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
int eLinkedList<T>::size() {
    int count = 0;
    ForwardListNode<T> *temp = head;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

template<typename T>
void eLinkedList<T>::push_front(T value) {
    auto *newNode = new ForwardListNode<T>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void eLinkedList<T>::push_back(T value) {
    auto *newNode = new ForwardListNode<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ForwardListNode<T> *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template<typename T>
T eLinkedList<T>::front() {
    return head->val;
}

template<typename T>
T eLinkedList<T>::back() {
    ForwardListNode<T> *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::show() {
    ForwardListNode<T> *temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
T eLinkedList<T>::pop_front() {
    T val = head->val;
    ForwardListNode<T> *temp = head;
    head = head->next;
    delete temp;
    return val;
}

template<typename T>
T eLinkedList<T>::pop_back() {
    ForwardListNode<T> *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    T val = temp->next->val;
    delete temp->next;
    temp->next = nullptr;
    return val;
}

template<typename T>
T eLinkedList<T>::operator[](int index) {
    ForwardListNode<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::clear() {
    ForwardListNode<T> *temp = head;
    while (temp) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void eLinkedList<T>::reverse() {
    ForwardListNode<T> *prev = nullptr, *curr = head, *next = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<typename T>
ForwardListNode<T> *eLinkedList<T>::getMiddle(ForwardListNode<T>* start) {
    if(!start) return nullptr;

    ForwardListNode<T> *slow = start, *fast = start->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
ForwardListNode<T> *eLinkedList<T>::merge(ForwardListNode<T> *left, ForwardListNode<T> *right) {
    if(!left) return right;
    if(!right) return left;
    if(left->val < right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

template<typename T>
ForwardListNode<T> *eLinkedList<T>::mergeSort(ForwardListNode<T> *start) {
    if(!start || !start->next) return start;

    ForwardListNode<T> *mid = getMiddle(start);
    ForwardListNode<T> *midNext = mid->next;

    mid->next = nullptr;

    ForwardListNode<T> *left = mergeSort(start);
    ForwardListNode<T> *right = mergeSort(midNext);

    return merge(left, right);
}

template<typename T>
void eLinkedList<T>::sort() {
    head = mergeSort(head);
}

#endif // ESTL_ELINKEDLIST_TPP