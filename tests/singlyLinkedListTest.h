#ifndef TESTS_SINGLYLINKEDLIST_H
#define TESTS_SINGLYLINKEDLIST_H

#include "../include/eLinkedList/eLinkedList.h"
#include <cassert>
#include <cmath>
#include <iostream>

inline void test_eSinglyLinkedList() {
    constexpr double EPS = 1e-9;   // Tolerancia para comparaciones con double

    eLinkedList<int>    list;
    eLinkedList<char>   list2;
    eLinkedList<double> list3;

    /* 1. Las listas comienzan vacías */
    assert(list.empty());
    assert(list2.empty());
    assert(list3.empty());

    /* 2. Inserción al frente */
    list.push_front(3);
    list2.push_front('c');
    list3.push_front(20.3);

    assert(!list.empty()  && list.front() == 3   && list.back() == 3   && list.size() == 1);
    assert(!list2.empty() && list2.front() == 'c' && list2.back() == 'c' && list2.size() == 1);
    assert(!list3.empty() && std::fabs(list3.front() - 20.3) < EPS && std::fabs(list3.back() - 20.3) < EPS && list3.size() == 1);

    /* 3. Inserción al final */
    list.push_back(4);
    list2.push_back('d');
    list3.push_back(12.9);

    assert(list.back() == 4  && list.size()  == 2);
    assert(list2.back() == 'd' && list2.size() == 2);
    assert(std::fabs(list3.back() - 12.9) < EPS && list3.size() == 2);

    /* 4. Múltiples inserciones al frente */
    list.push_front(2);
    list.push_front(1);
    list2.push_front('b');
    list2.push_front('a');
    list3.push_front(32.8);
    list3.push_front(10.2);

    /* 5. Múltiples inserciones al final */
    list.push_back(5);
    list.push_back(6);
    list2.push_back('e');
    list2.push_back('f');
    list3.push_back(15.4);
    list3.push_back(27.8);

    assert(list.front() == 1   && list.back() == 6   && list.size() == 6);
    assert(list2.front() == 'a' && list2.back() == 'f' && list2.size() == 6);
    assert(std::fabs(list3.front() - 10.2) < EPS && std::fabs(list3.back() - 27.8) < EPS && list3.size() == 6);

    /* 6. reverse() */
    list.reverse();   // [6,5,4,3,2,1]
    list2.reverse();  // [f,e,d,c,b,a]
    list3.reverse();  // [27.8,15.4,12.9,20.3,32.8,10.2]

    assert(list.front() == 6  && list.back() == 1);
    assert(list2.front() == 'f' && list2.back() == 'a');
    assert(std::fabs(list3.front() - 27.8) < EPS && std::fabs(list3.back() - 10.2) < EPS);

    /* 7. pop_front() */
    assert(list.pop_front()  == 6);
    assert(list2.pop_front() == 'f');
    assert(std::fabs(list3.pop_front() - 27.8) < EPS);

    /* 8. pop_back() */
    assert(list.pop_back()  == 1);
    assert(list2.pop_back() == 'a');
    assert(std::fabs(list3.pop_back() - 10.2) < EPS);

    // Secuencias esperadas tras las extracciones:
    // list  -> [5,4,3,2]
    // list2 -> [e,d,c,b]
    // list3 -> [15.4,12.9,20.3,32.8]

    assert(list.size()  == 4 && list.front()  == 5 && list.back()  == 2);
    assert(list2.size() == 4 && list2.front() == 'e' && list2.back() == 'b');
    assert(list3.size() == 4 && std::fabs(list3.front() - 15.4) < EPS && std::fabs(list3.back() - 32.8) < EPS);

    /* 9. operator[] */
    assert(list[2]  == 3);
    assert(list2[3] == 'b');
    assert(std::fabs(list3[1] - 12.9) < EPS);

    /* 10. sort() */
    list.sort();   // [2,3,4,5]
    list2.sort();  // [b,c,d,e]
    list3.sort();  // [12.9,15.4,20.3,32.8]

    assert(list.front()  == 2   && list.back()  == 5);
    assert(list2.front() == 'b' && list2.back() == 'e');
    assert(std::fabs(list3.front() - 12.9) < EPS && std::fabs(list3.back() - 32.8) < EPS);

    /* 11. clear() y empty() */
    list.clear();
    list2.clear();
    list3.clear();

    assert(list.empty());
    assert(list2.empty());
    assert(list3.empty());

    std::cout << __FILE__ << " ✅ Todos los tests pasaron correctamente.\n";
}

#endif // TESTS_SINGLYLINKEDLIST_H
