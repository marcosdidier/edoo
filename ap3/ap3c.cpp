#include <iostream>

using namespace std;

// Função para calcular o fatorial usando um loop
long double fatorial_loop(unsigned int x){
    long double resultado = 1;  // Fatorial começa com 1
    for (unsigned int i = 1; i <= x; i++){
        resultado *= i;  // Multiplica o resultado pelo número atual
    }
    return resultado;
}

// Função para calcular o fatorial de forma recursiva
long double fatorial_recursivo(unsigned int x){
    if (x == 0 || x == 1)  // Caso base: fatorial de 0 ou 1 é 1
        return 1;
    else
        return x * fatorial_recursivo(x - 1);  // Chamada recursiva
}

int main(void){
    unsigned int numero = 5;

    cout << "Fatorial usando loop: " << fatorial_loop(numero) << endl;
    cout << "Fatorial usando recursão: " << fatorial_recursivo(numero) << endl;

    return 0;
}