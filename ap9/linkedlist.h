#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"
#include "lists.h"

using namespace std;

template <typename E>

class LinkedList : public List<E>
{
private:
    Node<E> *head;
    Node<E> *tail;
    Node<E> *curr;
    int cnt;

public:
    LinkedList()
    {
        head = tail = curr = new Node<E>(nullptr);
        cnt = 0;
    }

    ~LinkedList()
    {
        moveToStart();
        while (head != nullptr)
        {
            Node<E> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const E &item) override
    {
        curr->next = new Node<E>(item, curr->next);
        if (tail == curr)
        {
            tail = curr->next;
        }
        cnt++;
    }

    void append(const E &item) override
    {
        tail->next = new Node<E>(item, nullptr);
        tail = tail->next;
    }

    E remove() override
    {
        if (curr->next == nullptr)
        {
            throw runtime_error("Não há elemento para remover!");
        }
        E it = curr->next->element;
        if (tail == curr->next)
        {
            tail = curr;
        }
        curr->next = curr->next->next;
        cnt--;
        return it;
    }

    void moveToStart() override
    {
        curr = head;
    }

    void moveToEnd() override
    {
        curr = tail;
    }

    void prev() override
    {
        if (curr == head)
        {
            cout << "Não há como mover o cursor para trás!" << endl;
            return;
        }
        Node<E> *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }

    void next() override
    {
        if (curr == tail)
        {
            cout << "Não há como mover o cursor para frente!" << endl;
            return;
        }
        curr = curr->next;
    }

    int length() override
    {
        return cnt;
    }

    int currPos() override{
        Node<E> *temp = head;
        int pos = 0;

        while (temp != nullptr && temp != curr)
        {
            temp = temp->next;
            pos++;
        }

        return pos;
    }

    void moveToPos(int pos) override{
        if (pos < 0 || pos >= cnt){
            cout << "Posição inválida!" << endl;
            return;
        }

        Node<E>* temp = head;

        for (int i = 0; i < pos; i++){
            temp = temp->next;
        }

        curr = temp;
    }

    E getValue() override{
        return curr->element;
    }

    int count(const E& it){
        Node<E>* temp = head;
        int qtd = 0;
        while (temp != nullptr){
            if (temp->element == it) qtd++;
            temp = temp->next;
        }
        return qtd;
    }


};

#endif