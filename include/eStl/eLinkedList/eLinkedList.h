//
// Created by esteb on 04/04/2025.
//

#ifndef ESTL_ELINKEDLIST_H
#define ESTL_ELINKEDLIST_H
#include "iostream"

#include "Node.h"
template<typename T>
class eLinkedList {
public:
    Node<T> *head;
    Node<T> *tail;
    eLinkedList();
    ~eLinkedList();
    T front();
    T back();
    void push_front(T value);
    void push_back(T value);

    void show();
};

template<typename T>
eLinkedList<T>::eLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
eLinkedList<T>::~eLinkedList() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
T eLinkedList<T>::front() {
    if (head != nullptr) {
        return head->val;
    }
    throw std::out_of_range("List is empty");
}

template<typename T>
T eLinkedList<T>::back() {
    if (tail != nullptr) {
        return tail->val;
    }
    throw std::out_of_range("List is empty");
}
template<typename T>
void eLinkedList<T>::push_front(T value) {
    auto *newNode = new Node<T>;
    newNode->val = value;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }

}

template<typename T>
void eLinkedList<T>::push_back(T value) {
    auto *newNode = new Node<T>;
    newNode->val = value;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
}

template<typename T>
void eLinkedList<T>::show() {
    Node<T> *current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


#endif //ESTL_ELINKEDLIST_H
