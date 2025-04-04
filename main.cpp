//
// Created by esteb on 04/04/2025.
//
#include "./include/eStl/eLinkedList/eLinkedList.h"

int main() {
    eLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.show();

    return 0;
}