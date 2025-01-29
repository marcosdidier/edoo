#include <iostream>
#include "tool1.h"
#include "tool2.h"

int main(void){

    double n1, n2;
    std::cout << "Nós temos 2 headers com nomes iguais mas fazem coisas diferentes, digite dois números para testarmos os headers: ";
    std::cin >> n1 >> n2;

    std::cout << "Resultado no 1º header: " << tool1::calculate(n1, n2) << std::endl;
    std::cout << "Resultado no 2º header: " << tool2::calculate(n1, n2) << std::endl;


    return 0;
}