#include <iostream>

using namespace std;

int main(void){

    int soma = 0;
    int receptor;

    for (int i = 0; i < 5; i++){
        cin >> receptor;
        soma += receptor;
    }

    cout << "Average = " << soma/5 << endl;

    return 0;
}