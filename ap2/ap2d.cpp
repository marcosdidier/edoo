#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Tamanho da tabuada
    const int size = 10;

    // Imprimir cabeçalho da tabela
    cout << setw(4) << "×"; // Espaço para alinhar o canto superior esquerdo
    for (int col = 1; col <= size; col++) {
        cout << setw(4) << col;
    }
    cout << endl;

    // Imprimir linhas da tabela
    for (int row = 1; row <= size; row++) {
        cout << setw(4) << row; // Primeira coluna (números da linha)
        for (int col = 1; col <= size; col++) {
            cout << setw(4) << row * col; // Valor calculado
        }
        cout << endl;
    }

    return 0;
}