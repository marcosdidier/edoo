#include <iostream>
#include <list>
#include <vector>

using namespace std;



class Dict{
    private:
    int m;
    int cnt;
    vector<vector<pair<int, string>>> Table;
    
    public:

    int h(int key){ return key % 10; }

    Dict(): m(10), cnt(0), Table(m) {};

    string find(int key){
        int pos = h(key);
        for (pair<int, string>& it : Table[pos]){
            if (it.first == key){ return it.second; } //Ver se o element pode ser vazio
        }
        return "";
    }

    void insert(int key, string element){
        if (find(key) != "") { return; }
        int pos = h(key);
        Table[pos].push_back({key, element}); 
        cnt++;
    }

    void del(int key) {
        string finder = find(key);
        if (finder == "") { return; }
        int pos = h(key);
        auto it = Table[pos].begin();
    
        while (it != Table[pos].end()) {
            if (it->first == key) {
                Table[pos].erase(it);
                cnt--;
                return;
            }
            ++it;
        }
    }

    void print(){
        cout << "alpha = " << cnt << '/' << m << endl;
        for (int i = 0; i < m; i++){
            cout << i << ':';
            bool isFirst = false;
            for (pair<int, string> element : Table[i]){
                if (!isFirst){
                    cout << '(' << element.first << ',' << element.second << ')';
                    isFirst = true;
                } else {
                    cout << ",(" << element.first << ',' << element.second << ')';
                }
            }
            cout << endl;
        }
    }
};

int main(void){
    int casos;
    cin >> casos;
    for (int j = 0; j < casos; j++){
        Dict d;
        int operacoes;
        cin >> operacoes;

        for (int i = 0; i < operacoes; i++){
            string operacao, element;
            cin >> operacao;
            int key;

            if (operacao == "add"){
                cin >> key >> element;
                d.insert(key, element);
            } else if (operacao == "del"){
                cin >> key;
                d.del(key);
            }
        }

        cout << "caso " << j+1 << ":\n";
        d.print();

    }

    return 0;
}