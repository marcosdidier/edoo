#include <iostream>

using namespace std;


class Node {

public:
    int element;
    bool side;
    Node* next;

public:
    Node(int it, Node* nextval){
        element = it;
        next = nextval;
    }

    Node(Node* nextval){
        next = nextval;
    }

    ~Node() {}

};

class Queue{
public:
    Node* front;
    Node* rear;
    int size;

    //public:

    Queue(){
        front = rear = nullptr;
        size = 0;
    }

    ~Queue(){
        /*while (front != nullptr ){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;*/
    }

    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }

    void enqueue(int it){
        Node* newNode = new Node(it, nullptr);
        if (rear == nullptr){
            front = rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue(){
        Node* temp = front;
        if (size == 0){
            throw runtime_error("Fila vazia!");
        }
        int it = front->element;
        front = front->next;
        delete temp;

        size--;

        return it;
    }
};


int main(void){

    int testCases;

    cin >> testCases;

    for(int i = 0; i < testCases; i++){
        int lengthFerry, cars;

        cin >> lengthFerry >> cars;
        lengthFerry *= 100;
        int lengthTemp = lengthFerry;
        bool sideFerry = false;


        if (cars == 0) {
            cout << 0;
            break;
        }

        Queue qr;
        Queue ql;

        int lengthCar;
        string side;
        int voltas = 0;


        for (int j = 0; j < cars; j++){
            cin >> lengthCar >> side;
            if (side == "left") { ql.enqueue(lengthCar); }
            else if (side == "right") {qr.enqueue(lengthCar); }
        }

        while (ql.size > 0 || qr.size > 0){
            if(!sideFerry){
                while (ql.size > 0 && (lengthTemp - ql.front->element) >= 0){
                lengthTemp -= ql.front->element;
                ql.dequeue();
                }
                sideFerry = true;
                lengthTemp = lengthFerry;
                voltas++;
            } else if (sideFerry){
                while (qr.size > 0 && (lengthTemp - qr.front->element) >= 0){
                    lengthTemp -= qr.front->element;
                    qr.dequeue();
                    }
                    sideFerry = false;
                    lengthTemp = lengthFerry;
                    voltas++;
            }
        }
        cout << voltas << endl;
    }
    return 0;
}