#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

using namespace std;

template<typename E>

class Queue{
    private:
    Node<E>* front;
    Node<E>* rear;
    int size;

    public:

    Queue(){
        front = rear = nullptr;
        size = 0;
    }

    ~Queue(){
        while (front->next != nullptr ){
            Node<E>* temp = front->next;
            front->next = front->next->next;
            delete temp;
        }
        delete front;
    }

    void enqueue(E it){
        Node<E>* newNode = new Node<E>(it, nullptr);

        if (rear == nullptr){
            front = rear = newNode;
        } else{
        rear->next = newNode;
        rear = newNode;
        }
        size++;
    }

    E dequeue(){
        Node<E>* temp = front;
        if (size == 0){
            throw runtime_error("Fila vazia!");
        }
        E it = front->element;
        front = front->next;
        delete temp;

        size--;

        return it;
    }

    E frontValue(){
        if (size == 0){
            throw runtime_error("Fila vazia!");
        }
        return front->element;
    }

    int length(){ return size; }

};

#endif