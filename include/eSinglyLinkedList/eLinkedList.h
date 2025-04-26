/**
 * @file eLinkedList.h
 * @brief Lista enlazada simple (singly‑linked list) sin puntero de cola.
 *
 * Este archivo define la plantilla `eLinkedList`, una implementación
 * educativa de una lista enlazada simple que solo mantiene referencia a
 * la cabeza de la estructura.
 */

/** @defgroup singly Listas Enlazadas Simples
 *  @ingroup containers
 *  @{ */

#ifndef ESTL_ELINKEDLIST_H
#define ESTL_ELINKEDLIST_H

#include "SinglyLinkedListNode.h"

/**
 * @tparam T Tipo de dato almacenado.
 *
 * @brief Lista enlazada simple con acceso únicamente por cabeza.
 *
 * Las operaciones que requieren acceder al final (`back`, `push_back`,
 * `pop_back`) tienen costo lineal. El método `size()` recorre la lista
 * para contar nodos, pues no se mantiene un contador interno.
 *
 * @complexity
 * | Operación          | Complejidad |
 * |--------------------|-------------|
 * | front, push_front  | O(1)        |
 * | back, push_back    | O(n)        |
 * | pop_front          | O(1)        |
 * | pop_back           | O(n)        |
 * | operator[]         | O(n)        |
 * | size               | O(n)        |
 * | clear              | O(n)        |
 * | sort (merge sort)  | O(n log n)  |
 * | reverse            | O(n)        |
 */
template<typename T>
class eLinkedList {
    SinglyLinkedListNode<T>* head; ///< Puntero al primer nodo.
public:
    /** Constructor: crea una lista vacía. */
    eLinkedList();

    /** Destructor: libera todos los nodos. */
    ~eLinkedList();

    // ---------- Observadores ----------

    /**
     * @return `true` si la lista está vacía.
     */
    [[nodiscard]] bool empty() const;

    /**
     * @return Número de nodos en la lista.
     */
    [[nodiscard]] int size() const;

    /** @brief Valor del primer nodo.  */
    T front();
    /** @brief Valor del último nodo (recorre la lista). */
    T back();

    /**
     * Acceso aleatorio (no constante).
     * @param index Posición base‑cero.
     * @return Valor del nodo `index`‑ésimo.
     */
    T operator[](int index);

    // ---------- Modificadores ----------

    /** Inserta un elemento al principio. */
    void push_front(T value);
    /** Inserta un elemento al final (O(n)). */
    void push_back(T value);

    /** Elimina y devuelve el primer elemento. */
    T pop_front();
    /** Elimina y devuelve el último elemento (O(n)). */
    T pop_back();

    /** Borra todos los nodos. */
    void clear();

    // ---------- Algoritmos auxiliares ----------
    SinglyLinkedListNode<T>* getMiddle(SinglyLinkedListNode<T>* start);
    SinglyLinkedListNode<T>* merge(SinglyLinkedListNode<T>* left,
                                   SinglyLinkedListNode<T>* right);
    SinglyLinkedListNode<T>* mergeSort(SinglyLinkedListNode<T>* start);

    // ---------- Algoritmos públicos ----------

    /** Ordena la lista mediante Merge Sort. */
    void sort();
    /** Invierte la lista in‑place. */
    void reverse();

    /** Imprime la lista por `std::cout`. */
    void show();
};

#include "../src/eSinglyLinkedList/eLinkedList.tpp"
#endif // ESTL_ELINKEDLIST_H
/** @} */ // end of group singly
