#include <iostream>

using namespace std;


int main(void){
    string mensagem = "I have learned something new again!";
    cout << mensagem.length() << endl;
    string mensagempt2;
    cin >> mensagempt2;
    cout << mensagem << " * " << mensagempt2;

    return 0;
}