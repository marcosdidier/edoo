#include <iostream>
#include "myMacros.h"

using namespace std;

int main(void){

    cout << "O valor absoluto de 10 é: " << ABS(10) << endl;
    cout << "Já o de -10 é: " << ABS(-10) << endl;
    cout << "Eles são iguais!" << endl;

    cout << "Digite dois números: ";
    int numero1, numero2;
    cin >> numero1 >> numero2;

    cout << "O maior entre " << numero1 << " e " << numero2 << " é: " << MAX(numero1, numero2) << endl;





    return 0;
}