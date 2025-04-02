#include <iostream>

using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key = key;
        left = right = nullptr;
    }
};

class BST{
    private:
    Node* root;
    int nodecount;

    public:
    BST(): root(nullptr), nodecount(0) {}

    ~BST(){
        clear(root);
    }

    void clear(Node* rt) {
        if (rt == nullptr) return;
        clear(rt->left);
        clear(rt->right);
        delete rt;
    }

    int find(int k){
        int *result = findhelp(root, k);
        if (result == nullptr) { return -1; }
        else { return *result; }
    }

    int* findhelp(Node* rt, int k){
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k){ return findhelp(rt->left, k); }
        else if (rt->key == k) { return &rt->key; }
        else { return findhelp(rt->right, k); }
    }

    void insert(int k){
        root = inserthelp(root, k);
        nodecount++;
    }

    Node* inserthelp(Node* rt, int k){
        if (rt == nullptr) return new Node(k);
        if (rt->key > k) { rt->left = inserthelp(rt->left, k); }
        else { rt->right = inserthelp(rt->right, k); }
        return rt;
    }

    int remove(int k){
        int* temp = findhelp(root, k);
        if (temp != nullptr){
            root = removehelp(root, k);
            nodecount--;
            return *temp;
        }
        return -1;
    }

    Node* removehelp(Node* rt, int k){
        if (rt == nullptr ) { return nullptr; }
        if (rt->key > k) { rt->left = removehelp(rt->left, k); }
        else if (rt->key < k) { rt->right = removehelp(rt->right, k); }
        else {
            if (rt->left == nullptr ){ 
                Node* temp = rt->right;
                delete rt;
                return temp;
            }
            else if (rt->right == nullptr){
                Node*temp = rt->left;
                delete rt; 
                return temp;
            }
            else {
                Node* temp = getmin(rt->right);
                rt->key = temp->key;
                rt->right = deletemin(rt->right);
            }
        }

        return rt;
    }

    Node* getmin(Node* rt){
        if (rt->left == nullptr) { return rt; }
        return getmin(rt->left);
    }

    Node* deletemin(Node* rt){
        if (rt->left == nullptr) {
            Node* temp = rt->right;
            delete rt;
            return temp;
        }
        rt->left = deletemin(rt->left);
        return rt;
    }

    void posorder(Node* rt){
        if (rt == nullptr){ return; }
        posorder(rt->left);
        posorder(rt->right);
        cout << rt->key << endl;
    }

    Node* getRoot(){ return root; }

    int getNodeCount() { return nodecount; }


};

int main(void){

    int operations;
    cin >> operations;

    BST bst;

    for (int i = 0; i < operations; i++){

        string operation;
        int operando;
        cin >> operation;
        cin >> operando;

        if (operation == "ins"){
            bst.insert(operando);
        } else if (operation == "rem"){
            bst.remove(operando);
        }

    }
    cout << bst.getNodeCount() << endl;
    bst.posorder(bst.getRoot());

    return 0;
}