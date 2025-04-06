//
// Created by esteb on 04/04/2025.
//
#ifndef ESTL_ELINKEDLIST_TPP
#define ESTL_ELINKEDLIST_TPP

#include "eStl/eLinkedList/eLinkedList.h"

template <typename T>
eLinkedList<T>::eLinkedList() : head(nullptr){}

template <typename T>
eLinkedList<T>::~eLinkedList() {
    Node<T> *temp = head;
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
    Node<T> *temp = head;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

template<typename T>
void eLinkedList<T>::push_front(T value) {
    auto *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void eLinkedList<T>::push_back(T value) {
    auto *newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T> *temp = head;
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
    Node<T> *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::show() {
    Node<T> *temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
T eLinkedList<T>::pop_front() {
    T val = head->val;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    return val;
}

template<typename T>
T eLinkedList<T>::pop_back() {
    Node<T> *temp = head;
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
    Node<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

template<typename T>
void eLinkedList<T>::clear() {
    Node<T> *temp = head;
    while (temp) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void eLinkedList<T>::reverse() {
    Node<T> *prev = nullptr, *curr = head, *next = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<typename T>
Node<T> *eLinkedList<T>::getMiddle(Node<T>* start) {
    if(!start) return nullptr;

    Node<T> *slow = start, *fast = start->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
Node<T> *eLinkedList<T>::merge(Node<T> *left, Node<T> *right) {
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
Node<T> *eLinkedList<T>::mergeSort(Node<T> *start) {
    if(!start || !start->next) return start;

    Node<T> *mid = getMiddle(start);
    Node<T> *midNext = mid->next;

    mid->next = nullptr;

    Node<T> *left = mergeSort(start);
    Node<T> *right = mergeSort(midNext);

    return merge(left, right);
}

template<typename T>
void eLinkedList<T>::sort() {
    head = mergeSort(head);
}

#endif // ESTL_ELINKEDLIST_TPP