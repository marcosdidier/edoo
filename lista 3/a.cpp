#include <iostream>

using namespace std;

template <typename E>

class Node{
    public:
    E key;
    E element;
    Node* left;
    Node* right;

    Node(E key, E element){
        this->key = key;
        this->element = element;
        left = right = nullptr;
    }

    ~Node(){
        delete left;
        delete right;
    }
};

template<typename E>

class BST{
    private:
    Node<E>* root;
    int nodecount;

    public:
    BST(): root(nullptr), nodecount(0) {}

    ~BST(){//Codar a deleção

    }

    E find(E k){
        int *result = findhelp(root, k);
        if (result == nullptr) { return -1; }
        else { return *result; }
    }

    E* findhelp(Node<E>* rt, E k){
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k){ return findhelp(rt->left, k); }
        else if (rt->key == k) { return &rt->element; }
        else { return findhelp(rt->right, k); }
    }

    void insert(E k, E e){
        root = inserthelp(root, k, e);
        nodecount++;
    }

    Node<E>* inserthelp(Node<E>* rt, E k, E e){
        if (rt == nullptr) return new Node<E>(k, e);
        if (rt->key > k) { rt->left = inserthelp(rt->left, k, e); }
        else { rt->right = inserthelp(rt->right, k, e); }
        return rt;
    }

    E remove(E k){
        E* temp = findhelp(root, k);
        if (temp != nullptr){
            root = removehelp(root, k);
            nodecount--;
            return *temp;
        }
        return -1;
    }

    Node<E>* removehelp(Node<E>* rt, E k){
        if (rt == nullptr ) { return nullptr; }
        if (rt->key > k) { rt->left = removehelp(rt->left, k); }
        else if (rt->key < k) { rt->right = removehelp(rt->right, k); }
        else {
            if (rt->left == nullptr ){ 
                Node<E>* temp = rt->right;
                delete rt;
                return temp;
            }
            else if (rt->right == nullptr){
                Node<E>*temp = rt->left;
                delete rt; 
                return temp;
            }
            else {
                Node<E>* temp = getmin(rt->right);
                rt->element = temp->element;
                rt->key = temp->key;
                rt->right = deletemin(rt->right);
            }
        }

        return rt;
    }

    Node<E>* getmin(Node<E>* rt){
        if (rt->left == nullptr) { return rt; }
        return getmin(rt->left);
    }

    Node<E>* deletemin(Node<E>* rt){
        if (rt->left == nullptr) {
            Node<E>* temp = rt->right;
            delete rt;
            return temp;
        }
        rt->left = deletemin(rt->left);
        return rt;
    }

    void preorder(Node<E>* rt){
        if (rt == nullptr){ return; }
        cout << ' ' << rt->key;
        preorder(rt->left);
        preorder(rt->right);
    }

    void inorder(Node<E>* rt){
        if (rt == nullptr){ return; }
        inorder(rt->left);
        cout << ' ' << rt->key;
        inorder(rt->right);
    }

    void posorder(Node<E>* rt){
        if (rt == nullptr){ return; }
        posorder(rt->left);
        posorder(rt->right);
        cout << ' ' << rt->key;
    }

    Node<E>* getRoot(){ return root; }


};

int main(void){

    int operations;
    cin >> operations;

    BST<int> bst;

    for (int i = 0; i < operations; i++){

        int operation;
        cin >> operation;

        bst.insert(operation, 0);
    }
    
    cout << "Pre order :";
    bst.preorder(bst.getRoot()); 
    cout << "\nIn order  :";
    bst.inorder(bst.getRoot());  
    cout << "\nPost order:";
    bst.posorder(bst.getRoot()); 

    return 0;
}