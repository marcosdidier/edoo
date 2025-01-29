#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(void){

    long sec;

    time(&sec);
    srand((unsigned) sec);

    int numero = rand() % 15;
    int tentativa;

    for (int i = 0; i < 3; i++){
        cin >> tentativa;
        if (tentativa == numero){
            cout << "Parabéns, você acertou!" << endl;
            return 1;
        } else if (tentativa < numero){
            cout << "O número que você digitou é menor do que o número secreto!" << endl;
        } else{
            cout << "O número que você digitou é maior do que o número secreto!" << endl;
        }
    }

    cout << "Infelizmente você perdeu, o número correto era: " << numero << endl;


    return 0;
}