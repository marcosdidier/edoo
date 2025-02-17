#include <iostream>
#include "stack.h"

using namespace std;

int main(void){
    int casos;
    cin >> casos;
    string comando;
    int operando;

    for (int i = 0; i < casos; i++){
        cout << "Caso " << i+1 << ": " << endl;
        Stack<int> s;

        while (cin >> comando && comando != "end"){
            if (comando == "push"){
                cin >> operando;
                s.push(operando);
            }
            else if (comando == "pop"){
                int soma = 0;
                cin >> operando;
                for (int j = 0; j < operando; j++){
                    soma += s.pop();
                }
                    cout << soma << endl;
            }
        }

    }

    return 0;
}