#include <iostream>
#include <list>
#include <vector>

using namespace std;


int h(int key){ return key % 10; }

class Dict{
    private:
    int m;
    int cnt;
    vector<list<pair<int, int>>> Table;

    public:

    Dict(int size): m(size), cnt(0), Table(m) {};

    int* find(int key){
        int pos = h(key);
        for (pair<int, int>& it : Table[pos]){
            if (it.first == key){ return &it.second; }
        }
        return nullptr;
    }

    void insert(int key, int element){
        if (find(key) != nullptr) { return; }
        int pos = h(key);
        Table[pos].push_back({key, element}); 
    }

    void print(){
        for (int i = 0; i < m; i++){
            cout << i << ' ';
            for (pair<int, int> element : Table[i]){
                cout << element.first << ' ';
            }
            cout << endl;
        }
    }
};

int main(void){
    int operacoes, operando;
    Dict d(10);
    cin >> operacoes;

    for (int i = 0; i < operacoes; i++){
        cin >> operando;
        d.insert(operando, 0);
    }

    d.print();

    return 0;
}