#pragma once
template <typename T>

struct Node {
private:
    T data;
    Node* next; // Se crea un nodo siguiente y un nodo anterior
    Node* previous;
public:
    Node(T value) : data(value), next(nullptr), previous(nullptr) {}
    Node() {};

    // Se utilizan sets y gets para poder manipularlos en la clase List y las que se necesiten
    T getDato() {
        return data;
    }
    Node* getNext() {
        return next;
    }
    Node* getPrevious() {
        return previous;
    }
    void setNext(Node<T>* pNext) {
        this->next = pNext;
    }
    void setPrevious(Node<T>* pPrevious) {
        this->previous = pPrevious;
    }
};

