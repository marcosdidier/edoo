#ifndef STACK_H
#define STACK_H

#include "node.h"

using namespace std;

template <typename E>

class Stack{
    private:
    Node<E>* top;
    int size;

    public:

    Stack(){
        top = nullptr;
        size = 0;
    };

    ~Stack(){
        while (top != nullptr){
            Node<E>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void clear();

    void push(E it){
        top = new Node<E>(it, top);
        size++; 
    }

    E pop(){
        if (top == nullptr){
            throw runtime_error("Não há elemento para remover");
        }

        E it = top->element;
        Node<E>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }

   
    E topValue(){
        if (top == nullptr){
            throw runtime_error("Pilha vazia!");
        }
        return top->element;
    }
    int length(){ return size; }
    bool isEmpty(){ 
        if (size == 0) return true;
        return false;
    }

    int sum(){
        int soma = 0;
        Node<E>* temp = top;
        while(temp != nullptr){
            soma += temp->element;
            temp = temp->next;
        }
        return soma;
    }

};

#endif