#ifndef NODE_H
#define NODE_H

template <typename E>

class Node {

    public:
    E element;
    Node<E>* next;

    public:
    Node(E it, Node<E>* nextval){
        element = it;
        next = nextval;
    }

    Node(Node<E>* nextval){
        next = nextval;
    }

    ~Node() {}

};

#endif