#ifndef TESTS_DOUBLYLINKEDLIST_H
#define TESTS_DOUBLYLINKEDLIST_H
#include <iostream>
#include <cassert>
#include "../include/eDoublyLinkedList/eDoublyLinkedList.h"

inline void test_eDoublyLinkedList() {

    eDoublyLinkedList<int> list;

    // 1) empty y size en lista nueva
    assert(list.empty());
    assert(list.size() == 0);

    // 2) push_front / front
    list.push_front(10);
    assert(!list.empty());
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);

    // 3) push_back / back
    list.push_back(20);
    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 20);

    // 4) operator[]
    assert(list[0] == 10);
    assert(list[1] == 20);

    // 5) pop_front
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 20);
    assert(list.back() == 20);

    // 6) pop_back dejando lista vacía
    list.pop_back();
    assert(list.empty());
    assert(list.size() == 0);

    // 7) insertar varios y comprobar insert/remove
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i * 10); // 10,20,30,40,50
    }
    assert(list.size() == 5);
    // insert en el medio
    list.insert(25, 2);        // 10,20,25,30,40,50
    assert(list.size() == 6);
    assert(list[2] == 25);
    // remove el elemento que acabamos de insertar
    list.remove(2);            // vuelve a 10,20,30,40,50
    assert(list.size() == 5);
    assert(list[2] == 30);

    // 8) clear
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    // 9) reverse
    for (int i = 1; i <= 4; ++i) {
        list.push_back(i); // 1,2,3,4
    }
    list.reverse();        // 4,3,2,1
    assert(list.size() == 4);
    assert(list[0] == 4);
    assert(list[1] == 3);
    assert(list[2] == 2);
    assert(list[3] == 1);

    // 10) combinaciones adicionales de push y pop
    list.clear();
    list.push_front(100);
    list.push_back(200);
    list.push_front(50);
    // Ahora: 50,100,200
    assert(list.front() == 50);
    assert(list.back() == 200);
    list.pop_back();      // 50,100
    assert(list.back() == 100);
    list.pop_front();     // 100
    assert(list.front() == 100);
    list.pop_front();     // vacío otra vez
    assert(list.empty());

    std::cout << __FILE__<<"✅ Todos los tests pasaron correctamente.\n";

}


#endif