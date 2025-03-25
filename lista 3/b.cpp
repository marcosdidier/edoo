#include <iostream>
#include <stack>

using namespace std;

template <typename E>

class Node{
    public:
    E key;
    Node* left;
    Node* right;

    Node(E key){
        this->key = key;
        left = right = nullptr;
    }

};

template<typename E>

class BST{
    private:
    Node<E>* root;
    int nodecount;

    public:
    BST(): root(nullptr), nodecount(0) {}

    ~BST(){
        clear(root);
    }

    void clear(Node<E>* rt){
        if (rt == nullptr) return;
        clear(rt->left);
        clear(rt->right);
        delete rt;
    }

    void insert(E k){
        root = inserthelp(root, k);
        nodecount++;
    }

    Node<E>* inserthelp(Node<E>* rt, E k){
        if (rt == nullptr) return new Node<E>(k);
        if (rt->key > k) { rt->left = inserthelp(rt->left, k); }
        else { rt->right = inserthelp(rt->right, k); }
        return rt;
    }

    void preorder(Node<E>* rt){
        if (rt == nullptr){ return; }
        cout << rt->key;
        preorder(rt->left);
        preorder(rt->right);
    }

    Node<E>* getRoot(){ return root; }
};

int main(void){

    char caractere;
    stack<char> pilha;
    BST<char>* bst = new BST<char>();
    
    while (cin >> caractere){
        if (caractere == '*'){
            while (!pilha.empty()){
                char letra = pilha.top();
                pilha.pop();
                bst->insert(letra);
            }
            bst->preorder(bst->getRoot());
            cout << endl;
            delete bst;
            bst = new BST<char>();
        } else if (caractere == '$'){
            while (!pilha.empty()){
                char letra = pilha.top();
                pilha.pop();
                bst->insert(letra);
            }
            bst->preorder(bst->getRoot());
            cout << endl;
            break;
        } else {
            pilha.push(caractere);
        }
    }
    return 0;
}