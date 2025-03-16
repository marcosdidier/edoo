#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Dict{
    private:
    int m;
    int cnt;
    vector<string> Table;
    vector<bool> Accessed;
    vector<bool> Deleted;
    
    public:
    
    Dict(int size): m(size), cnt(0), Table(m){
        Accessed.assign(m, false);
        Deleted.assign(m, false);
    }

    int h(string K){
        int s = K.length();
        int sum = 0;
        for (int i = 0; i < s; i++){
            sum += K[i];
        }
        return abs(sum) % m;
    }

    /*int* find(string key){
        int index = h(key);
        int newIndex = index;
        if (Accessed[index] && Table[index] == key){
            return new int(index);
        }
        for (int i = 1; i < m; i++){
            newIndex = (index + i) % m;
            if (Accessed[index] && Table[newIndex] == key){
                return new int(newIndex);
            }
        }
        return nullptr;
    }*/

    int hashFind(string key){
        int index = h(key);
        for (int i = 0; i < m; i++){
            int newIndex = (index + i) % m;
            if (Accessed[newIndex] && Table[newIndex] == key){
            return newIndex;
            }
        }
        return -1;
    }

    /*void insert(string key){
        int *result = find(key);
        if (cnt < (m && result == nullptr)){
            int index = h(key);
            int newIndex = index;
            if (Accessed[newIndex]){
                for (int i = 1; i < m; i++){
                    newIndex = (index + i) % m;
                    if (!Accessed[newIndex]) { 
                        Table[newIndex] = key;
                        Accessed[newIndex] = true;
                        Deleted[newIndex] = false;
                        delete result;
                        break;
                    }
                }
            }
        } 
        delete result;
    }*/

    void insert(string key) {
        if (cnt < m && hashFind(key) == -1) {
                int pos = h(key);
                int i = 0;
                while(Accessed[pos]){
                    pos = (pos + 1) % m;
                    i++;
                    if(i == m){
                        break;
                    }
                }
            if (!Accessed[pos]){
            Table[pos] = key;
            Accessed[pos] = true;
            Deleted[pos] = false;
            cnt++;
        }
        }
    }

    /*void deleteEntry(string key){
        int *index = find(key);
        if (index != nullptr){
            Accessed[*index] = false;
            Deleted[*index] = true;
            cnt--;
            Table[*index] = '\0';
        }
        delete index;
    }*/

    void deleteEntry(string key) {
        int index = hashFind(key);
        if (index != -1) {
            Accessed[index] = false;
            Deleted[index] = true;
            cnt--;
        }
    }





};

int main(void){
    int size;
    string operacao, operando;

    cin >> size;

    Dict d(size);

    while (cin >> operacao && operacao != "fim"){
        cin >> operando;
        if (operacao == "add"){
            d.insert(operando);
        } else if ( operacao == "rmv"){
            d.deleteEntry(operando);
        } else if ( operacao == "sch"){
            int index = d.hashFind(operando);
            if(index == -1){
                cout << operando << " -1" << endl;
            } else {
                cout << operando << ' ' << index << endl;
            }
        }
    }
    return 0;
}