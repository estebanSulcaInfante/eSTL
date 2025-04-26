//
// Created by esteb on 04/04/2025.
//
#ifndef ESTL_ELINKEDLIST_TPP
#define ESTL_ELINKEDLIST_TPP

#include "eSinglyLinkedList/eLinkedList.h"

template <typename T>
eLinkedList<T>::eLinkedList() : head(nullptr){}

template <typename T>
eLinkedList<T>::~eLinkedList() {
    SinglyLinkedListNode<T> *temp = head;
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
int eLinkedList<T>::size() const {
    int count = 0;
    SinglyLinkedListNode<T> *temp = head;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

template<typename T>
void eLinkedList<T>::push_front(T value) {
    auto *newNode = new SinglyLinkedListNode<T>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void eLinkedList<T>::push_back(T value) {
    auto *newNode = new SinglyLinkedListNode<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        SinglyLinkedListNode<T> *temp = head;
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
    SinglyLinkedListNode<T> *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::show() {
    SinglyLinkedListNode<T> *temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
T eLinkedList<T>::pop_front() {
    T val = head->val;
    SinglyLinkedListNode<T> *temp = head;
    head = head->next;
    delete temp;
    return val;
}

template<typename T>
T eLinkedList<T>::pop_back() {
    SinglyLinkedListNode<T> *temp = head;
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
    SinglyLinkedListNode<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::clear() {
    SinglyLinkedListNode<T> *temp = head;
    while (temp) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void eLinkedList<T>::reverse() {
    SinglyLinkedListNode<T> *prev = nullptr, *curr = head, *next = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<typename T>
SinglyLinkedListNode<T> *eLinkedList<T>::getMiddle(SinglyLinkedListNode<T>* start) {
    if(!start) return nullptr;

    SinglyLinkedListNode<T> *slow = start, *fast = start->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
SinglyLinkedListNode<T> *eLinkedList<T>::merge(SinglyLinkedListNode<T> *left, SinglyLinkedListNode<T> *right) {
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
SinglyLinkedListNode<T> *eLinkedList<T>::mergeSort(SinglyLinkedListNode<T> *start) {
    if(!start || !start->next) return start;

    SinglyLinkedListNode<T> *mid = getMiddle(start);
    SinglyLinkedListNode<T> *midNext = mid->next;

    mid->next = nullptr;

    SinglyLinkedListNode<T> *left = mergeSort(start);
    SinglyLinkedListNode<T> *right = mergeSort(midNext);

    return merge(left, right);
}

template<typename T>
void eLinkedList<T>::sort() {
    head = mergeSort(head);
}

#endif // ESTL_ELINKEDLIST_TPP