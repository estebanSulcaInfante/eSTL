//
// Created by esteb on 04/04/2025.
//

#ifndef ESTL_NODE_H
#define ESTL_NODE_H

template<typename T>
struct Node {
    T val;
    Node *next;

    Node(): val(T()), next(nullptr){};
    explicit Node(T val): val(val), next(nullptr){};
};


#endif //ESTL_NODE_H
