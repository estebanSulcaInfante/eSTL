//
// Created by esteb on 04/04/2025.
//

#include <iostream>
#include "./include/eStl/eLinkedList/eLinkedList.h"

using namespace std;

int main() {

    eLinkedList<int> list;
    eLinkedList<char> list2;
    eLinkedList<double> list3;

    cout << "Comprobar si la lista esta vacia: " << endl;
    cout << "Lista int: " << boolalpha << list.empty() << endl;
    cout << "Lista char: " << boolalpha << list.empty() << endl;
    cout << "Lista double: " << boolalpha << list.empty() << endl;

    cout << "Insertar elemento al inicio de la lista: " << endl;
    list.push_front(3);
    list2.push_front('c');
    list3.push_front(20.3);
    list.show();
    list2.show();
    list3.show();

    cout << "Comprobar si la lista esta vacia: " << endl;
    cout << "Lista int: " << boolalpha << list.empty() << endl;
    cout << "Lista char: " << boolalpha << list.empty() << endl;
    cout << "Lista double: " << boolalpha << list.empty() << endl;

    cout << "Insertar elemento  al final de la lista: " << endl;
    list.push_back(4);
    list2.push_back('d');
    list3.push_back(12.9);
    list.show();
    list2.show();
    list3.show();

    cout << "Insertar elementos al inicio de la lista: " << endl;
    list.push_front(2);
    list.push_front(1);
    list2.push_front('b');
    list2.push_front('a');
    list3.push_front(32.8);
    list3.push_front(10.2);
    list.show();
    list2.show();
    list3.show();

    cout << "Insertar elementos al final de la lista: " << endl;
    list.push_back(5);
    list.push_back(6);
    list2.push_back('e');
    list2.push_back('f');
    list3.push_back(15.4);
    list3.push_back(27.8);
    list.show();
    list2.show();
    list3.show();

    cout << "Retornar el primer elemento de la lista: " << endl;
    cout << "Lista int: " << list.front() << endl;
    cout << "Lista char: " << list2.front() << endl;
    cout << "Lista double: " << list3.front() << endl;

    cout << "Retornar el ultimo elemento de la lista: " << endl;
    cout << list.back() << endl;
    cout << list2.back() << endl;
    cout << list3.back() << endl;

    cout << "Comprobar longitud de la lista: " << endl;
    cout << list.size() << endl;
    cout << list2.size() << endl;
    cout << list3.size() << endl;

    cout << "Revertir orden de la lista: " << endl;
    list.show();
    list.reverse();
    list.show();

    list2.show();
    list2.reverse();
    list2.show();

    list3.show();
    list3.reverse();
    list3.show();

    cout << "Borrar primer elemento de la lista: " << endl;
    cout << list.pop_front() << endl;
    list.show();

    cout << list2.pop_front() << endl;
    list2.show();

    cout << list3.pop_front() << endl;
    list3.show();

    cout << "Borrar ultimo elemento de la lista: " << endl;
    cout << list.pop_back() << endl;
    list.show();

    cout << list2.pop_back() << endl;
    list2.show();

    cout << list3.pop_back() << endl;
    list3.show();

    cout << "Retornar elemento en la posicion (2): " << endl;
    cout << list[2] << endl;
    cout << list2[3] << endl;
    cout << list3[1] << endl;

    cout << "Ordenar elementos de la lista: " << endl;
    list.sort();
    list.show();

    list2.sort();
    list2.show();

    list3.sort();
    list3.show();

    cout << "Borrar todos los elementos de la lista y comprobar si esta vacia: " << endl;
    list.clear();
    cout << boolalpha << list.empty() << endl;

    list2.clear();
    cout << boolalpha << list2.empty() << endl;

    list3.clear();
    cout << boolalpha << list3.empty() << endl;

    return 0;
}