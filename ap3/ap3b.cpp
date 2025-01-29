#include <iostream>

using namespace std;

int main(void){

    string teste;

    cin >> teste;
    

    for (int i = 0, j = (teste.length()) - 1; i < j; i++, j--){
        if (teste[i] != teste[j]){
            cout << "A palavra não é um palíndromo" << endl;
            return 1;
        }
    }

    cout << "A palavra " << '"' << teste << '"' << " é um palíndromo" << endl;

    return 0;
}