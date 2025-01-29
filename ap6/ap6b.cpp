#include <iostream>
#include <cstdarg> // Biblioteca para manipular argumentos variádicos

unsigned int min(unsigned int first, ...) {
    va_list args;       // Declara a variável para acessar os argumentos variádicos
    va_start(args, first); // Inicializa a lista de argumentos
    unsigned int minValue = first; // Assume o primeiro valor como mínimo inicial

    while (true) {
        unsigned int num = va_arg(args, unsigned int); // Pega o próximo argumento
        if (num == 0) break; // O último argumento deve ser 0, então paramos

        if (num < minValue) {
            minValue = num; // Atualiza o menor valor encontrado
        }
    }

    va_end(args); // Libera os recursos alocados para a lista de argumentos
    return minValue;
}

int main() {
    std::cout << "Mínimo: " << min(8, 3, 15, 6, 2, 10, 0) << std::endl; // Retorna 2
    std::cout << "Mínimo: " << min(20, 5, 100, 1, 50, 0) << std::endl;  // Retorna 1
    return 0;
}