#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "lists.h"

using namespace std;

template<typename E>

class ArrayList : public List<E>{
    private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

    public:
    ArrayList(int size){
        maxSize = size;
        listSize = 0;
        curr = 0;
        listArray = new E[maxSize];
    };

    ~ArrayList(){
        delete[] listArray;
    };

    void insert(const E& item) override{
        if (listSize >= maxSize){
            cout << "Lista cheia" << endl;
            return;
        }
        int i = listSize;
        while (i > curr){
            listArray[i] = listArray[i-1];
            i--;
        }
        listArray[curr] = item;
        listSize++;
    }

    void append(const E& item) override{
        if (listSize >= maxSize){
            cout << "Lista cheia" << endl;
            return;
        }
        listArray[listSize] = item;
        listSize++;
    }

    E remove() override{
        if (curr < 0 || curr >= listSize){
            throw runtime_error("Nenhum valor disponível!");;
        }
        E it = listArray[curr];
        int i = curr;
        while (i < (listSize - 1)){
            listArray[i] = listArray[i + 1];
            i++;
        }
        listSize--;
        return it;
    }

    void moveToStart() override{
        curr = 0;
    }

    void moveToEnd() override{
        curr = listSize;
    }

    void prev() override{
        if (curr != 0) curr--;
    }

    void next() override{
        if (curr < listSize) curr++;
    }

    int length() override{
        return listSize;
    }

    int currPos() override{
        return curr;
    }

    void moveToPos(int pos) override{
        if (pos > (listSize - 1) || pos < 0){
            cout << "Posição inválida" << endl;
            return;
        }
        curr = pos;
    }

    E getValue() override{
        return listArray[curr];
    }

    int count(E item){
        int counter = 0;
        for (int i = 0; i < listSize; i++){
            if (listArray[i] == item){
                counter++;
            }
        }
        return counter;
    }

};

#endif