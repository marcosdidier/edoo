#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Dict{
    private:
    int m;
    int cnt;
    vector<vector<pair<string, string>>> Table;
    vector<bool> Occupied;

    public:

    Dict(): m(80000), cnt(0), Table(m){
        Occupied.assign(m, false);
    }

    int hashFunction(string key) {
        const int prime = 31;
        int hashValue = 0;
    
        for (char c : key) {
            hashValue = (hashValue * prime + c) % m;
        }
    
        return hashValue;
    }

    string find(string key){
        int pos = hashFunction(key);
        for (pair<string, string>& it : Table[pos]){
            if (it.first == key){ return it.second; }
        }
        return "eh";
    }

    void insert(string key, string element){
        int pos = hashFunction(key);
        Table[pos].push_back({key, element}); 
    }

};

int main(void){

    string linha, element, key;

    Dict d;

    while(true) {
        getline(cin, linha);

        if (linha.empty()) break;

        stringstream ss(linha);

        ss >> element >> key;

        d.insert(key, element);
    }

    string palavra;

    while(getline(cin, palavra)){
        cout << d.find(palavra) << '\n';
    }

    return 0;
}