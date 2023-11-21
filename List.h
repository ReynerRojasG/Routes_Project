#pragma once
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Node.h"

template <typename T>
class List {
private:
    Node<T>* head = nullptr; // Se crea una cabeza para la lista
    Node<T>* tail = nullptr;    // Se crea una cola para la lista
public:
    List() : head(nullptr), tail(nullptr) {}
    //Inserta un nuevo nodo al inicio
    void Insert(const T& value) {
        Node<T>* freshNode = new Node<T>(value);
        // Si la lista esta vacia
        if (head == nullptr) {
            head = freshNode;
            tail = freshNode;
        }
        else {
            freshNode->setPrevious(tail);
            tail->setNext(freshNode);
            tail = freshNode;
        }
    }

    // Elimina el ultimo vertice de la lista de coordenadas y actualiza las lineas en la ventana
    void DeleteLast(sf::VertexArray& lines) {
        if (head == nullptr) {
            // La lista esta vacia, no hay nada que eliminar
            return;
        }

        if (head == tail) {
            // Solo hay un nodo en la lista
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            // Hay mas de un nodo en la lista
            Node<T>* nodoAnteriorAlUltimo = tail->getPrevious();
            delete tail;
            tail = nodoAnteriorAlUltimo;
            tail->setNext(nullptr);
        }

        // Actualizar la sf::VertexArray
        lines.resize(lines.getVertexCount() - 1);
    }

    // Metodo para obtener la cabeza
    Node<T>* getHead() const {
        return head;
    }

    //Destructor de la lista
    ~List() {
        while (head) {
            Node<T>* next = head->getNext();
            delete head;
            head = next;
        }
        tail = nullptr;
    }

};
