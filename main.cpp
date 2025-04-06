//
// Created by esteb on 04/04/2025.
//

#include <iostream>
#include "./include/eStl/eLinkedList/eLinkedList.h"

using namespace std;

int main() {

    eLinkedList<int> list;

    cout << "Comprobar si la lista esta vacia: " << endl;
    cout << boolalpha << list.empty() << endl;

    cout << "Insertar elemento (1) al inicio de la lista: " << endl;
    list.push_front(3);
    list.show();

    cout << "Comprobar si la lista esta vacia: " << endl;
    cout << boolalpha << list.empty() << endl;

    cout << "Insertar elemento (4) al final de la lista: " << endl;
    list.push_back(4);
    list.show();

    cout << "Insertar elementos (2,3) al inicio de la lista: " << endl;
    list.push_front(2);
    list.push_front(1);
    list.show();

    cout << "Insertar elementos (5,6) al final de la lista: " << endl;
    list.push_back(5);
    list.push_back(6);
    list.show();

    cout << "Retorner el primer elemento de la lista: " << endl;
    cout << list.front() << endl;

    cout << "Retorner el ultimo elemento de la lista: " << endl;
    cout << list.back() << endl;

    cout << "Comprobar longitud de la lista: " << endl;
    cout << list.size() << endl;

    cout << "Revertir orden de la lista: " << endl;
    list.show();
    list.reverse();
    list.show();

    cout << "Borrar primer elemento de la lista: " << endl;
    cout << list.pop_front() << endl;
    list.show();

    cout << "Borrar ultimo elemento de la lista: " << endl;
    cout << list.pop_back() << endl;
    list.show();

    cout << "Retornar elemento en la posicion (2): " << endl;
    cout << list[2] << endl;

    cout << "Ordenar elementos de la lista: " << endl;
    list.sort();
    list.show();

    cout << "Borrar todos los elementos de la lista y comprobar si esta vacia: " << endl;
    list.clear();
    cout << boolalpha << list.empty() << endl;

    return 0;
}