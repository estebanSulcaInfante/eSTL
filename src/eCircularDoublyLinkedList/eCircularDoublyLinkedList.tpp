// CircularDoublyLinkedList.tpp
#ifndef CIRCULARDOUBLYLINKEDLIST_TPP
#define CIRCULARDOUBLYLINKEDLIST_TPP
#include "../include/eCircularDoublyLinkedList/eCircularDoublyLinkedList.h"
#include <stdexcept>
// Constructor / Destructor
template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() : head(nullptr) {}

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    clear();
}

// Estado
template<class T>
bool CircularDoublyLinkedList<T>::empty() const {
    return head == nullptr;
}

template<class T>
int CircularDoublyLinkedList<T>::size() const {
    if (empty()) return 0;
    int cnt = 1;
    auto it = head->next;
    while (it != head) {
        ++cnt;
        it = it->next;
    }
    return cnt;
}

// Acceso
template<class T>
T CircularDoublyLinkedList<T>::front() const {
    if (empty()) throw std::out_of_range("Lista vacía");
    return head->val;
}

template<class T>
T CircularDoublyLinkedList<T>::back() const {
    if (empty()) throw std::out_of_range("Lista vacía");
    return head->prev->val;
}

// Inserción
template<class T>
void CircularDoublyLinkedList<T>::push_front(const T& val) {
    auto node = new DoublyListNode<T>(val);
    if (empty()) {
        node->next = node->prev = node;
        head = node;
    } else {
        auto tail = head->prev;
        node->next = head;
        node->prev = tail;
        tail->next = head->prev = node;
        head = node;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::push_back(const T& val) {
    auto node = new DoublyListNode<T>(val);
    if (empty()) {
        node->next = node->prev = node;
        head = node;
    } else {
        auto tail = head->prev;
        tail->next = node;
        node->prev = tail;
        node->next = head;
        head->prev = node;
    }
}

// Eliminación
template<class T>
T CircularDoublyLinkedList<T>::pop_front() {
    if (empty()) throw std::out_of_range("Lista vacía");
    T ret = head->val;
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        auto tail = head->prev;
        auto nxt  = head->next;
        tail->next = nxt;
        nxt->prev  = tail;
        delete head;
        head = nxt;
    }
    return ret;
}

template<class T>
T CircularDoublyLinkedList<T>::pop_back() {
    if (empty()) throw std::out_of_range("Lista vacía");
    auto tail = head->prev;
    T ret = tail->val;
    if (tail == head) {
        delete head;
        head = nullptr;
    } else {
        auto before = tail->prev;
        before->next = head;
        head->prev   = before;
        delete tail;
    }
    return ret;
}

// Insertar/Remover en índice
template<class T>
void CircularDoublyLinkedList<T>::insert(const T& val, int idx) {
    int n = size();
    if (idx < 0 || idx > n) throw std::out_of_range("Índice fuera de rango");
    if (idx == 0) {
        push_front(val);
    } else if (idx == n) {
        push_back(val);
    } else {
        auto it = head;
        for (int i = 0; i < idx; ++i) it = it->next;
        auto node = new DoublyListNode<T>(val);
        auto prev = it->prev;
        prev->next = node;
        node->prev = prev;
        node->next = it;
        it->prev   = node;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::remove(int idx) {
    int n = size();
    if (idx < 0 || idx >= n) throw std::out_of_range("Índice fuera de rango");
    if (idx == 0) {
        pop_front();
    } else if (idx == n - 1) {
        pop_back();
    } else {
        auto it = head;
        for (int i = 0; i < idx; ++i) it = it->next;
        auto p = it->prev;
        auto nx = it->next;
        p->next = nx;
        nx->prev = p;
        delete it;
    }
}

// Acceso aleatorio
template<class T>
T CircularDoublyLinkedList<T>::operator[](int idx) const {
    int n = size();
    if (idx < 0 || idx >= n) throw std::out_of_range("Índice fuera de rango");
    auto it = head;
    for (int i = 0; i < idx; ++i) it = it->next;
    return it->val;
}

// Limpiar
template<class T>
void CircularDoublyLinkedList<T>::clear() {
    while (!empty()) pop_front();
}

// Invertir
template<class T>
void CircularDoublyLinkedList<T>::reverse() {
    if (empty() || head->next == head) return;
    auto curr = head;
    do {
        std::swap(curr->next, curr->prev);
        curr = curr->prev;  // tras el swap, prev apunta al siguiente original
    } while (curr != head);
    head = head->next;  // el nuevo head es el antiguo tail
}

#endif // CIRCULARDOUBLYLINKEDLIST_TPP
