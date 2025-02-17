#include <iostream>
#include "array_based_list.h"

using namespace std;

int main(void){


    int numeroCasos;
    cin >> numeroCasos;

    for (int i = 0; i < numeroCasos; i++){
        ArrayList<int> l(30);

        cout << "Caso " << i+1 << ": " << endl;

        int numeroOperacoes;
        cin >> numeroOperacoes;
        string operacao;
        int operando;

        for (int j = 0; j < numeroOperacoes; j++){
            cin >> operacao;

            if (operacao == "insert"){
                cin >> operando;
                l.insert(operando);
            }
            else if (operacao == "remove"){
                l.remove();
            }
            else if (operacao == "count"){
                cin >> operando;
                cout << l.count(operando) << endl;
            }
            else if (operacao == "prev"){
                l.prev();
            }
            else if (operacao == "next"){
                l.next();
            }
        }

    }


    return 0;
}