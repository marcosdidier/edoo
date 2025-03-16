#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Dict{
    private:
    int m;
    int cnt;
    vector<string> Table;
    vector<int> Perm;
    vector<bool> Accessed;
    vector<bool> Deleted;
    
    public:
    
    Dict(): m(101), cnt(0), Table(101){
        Accessed.assign(101, false);
        Deleted.assign(101, false);
        Perm.assign(19, 0);
        for (int i = 1; i <= 19; i++){
            Perm[i-1] = (i * i) + (23 * i);
        }
    }

    int h(string K){
        int index = 0;
        for (int i = 0; K[i] != '\0'; i++){
            index += K[i] * (i + 1);
        }
        index *= 19;
        return index % m;
    }

    int find(string key){
        int index = h(key);
        if (Accessed[index] && Table[index] == key){
            return index;
        } else {
            for (int i = 1; i <= 19; i++){
                int newIndex = (index + Perm[i-1]) % m;
                if (Accessed[newIndex] && Table[newIndex] == key){
                    return newIndex;
                }
            }
        }
        return -1;
    }

    void insert(string key){
        int index, newIndex;
        if (cnt < m && find(key) == -1){
            int index = h(key);
            int newIndex = index;
            if (Accessed[newIndex]){
                for (int i = 1; i <= 19; i++){
                    newIndex = (index + Perm[i-1]) % m;
                    if (!Accessed[newIndex]) { break; }
                }
            }
            if (!Accessed[newIndex]){
                Table[newIndex] = key;
                Accessed[newIndex] = true;
                Deleted[newIndex] = false;
                cnt++;
            }
        }
    }

    void deleteEntry(string key){
        int index = find(key);
        if (index != -1){
            Accessed[index] = false;
            Deleted[index] = true;
            cnt--;
            Table[index] = "";
        }
    }

    void print(){
        for (int i = 0; i < m; i++){
            if(Accessed[i] && !Deleted[i]){
                cout << i << ':' << Table[i] << endl;
            }
        }
    }

    int getCount() { return cnt; }

};

int main(void){
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; i++){
        Dict d;
        int acoes;
        cin >> acoes;

        for (int j = 0; j < acoes; j++){
            string acao, key;
            cin.ignore();
            getline(cin, acao, ':');
            cin >> key;
            if (acao == "ADD"){ d.insert(key); }
            else if (acao == "DEL") { d.deleteEntry(key); }

        }
        cout << d.getCount() << endl;
        d.print();
    }
    return 0;
}