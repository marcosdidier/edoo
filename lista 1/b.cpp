#include <iostream>

using namespace std;

class Node {

public:
    char element;
    Node* next;

public:
    Node(char it, Node* nextval){
        element = it;
        next = nextval;
    }

    Node(Node* nextval){
        next = nextval;
    }

    ~Node() {}

};


class Stack{
public:
    Node* top;
    int size;


    Stack(){
        top = nullptr;
        size = 0;
    };

    /*~Stack(){
        while (top != nullptr){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }*/

    void clear();

    void push(char it){
        top = new Node(it, top);
        size++;
    }

    char pop(){
        if (top == nullptr){
            throw runtime_error("Não há elemento para remover");
        }

        char it = top->element;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }


    char topValue(){
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

};

int main(void){
    int casos;
    char caractere;
    cin >> casos;
    cin.ignore();
    string palavra;

    for (int i = 0; i < casos; i++){
        Stack s;
        bool problema = false;
        getline(cin, palavra);
        if (palavra == ""){
            cout << "Yes" << endl;
            continue;
        }
        for(int j = 0; j < palavra.length(); j++){
            if (palavra[j] == '(' || palavra[j] == '['){ s.push(palavra[j]); }
            else{
                if (palavra[j] == ')' && (s.top == nullptr || s.top->element != '(')){
                    problema = true;
                    break;
                } else if (palavra[j] == ']' && (s.top == nullptr || s.top->element != '[')){
                    problema = true;
                    break;
                } else{
                    s.pop();
                }
            }
        }
        if (!problema && s.size == 0) {cout << "Yes" << endl; }
        else{ cout << "No" << endl; }
    }
    return 0;
}

