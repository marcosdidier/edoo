#include <iostream>
#include "products.h"
#include "prepackedfood.h"
#include "freshfood.h"

using namespace std;

int main() {
    // Criando os objetos
    Product* p1 = new Product(1000, "Arroz");
    Product* p2 = new PrePackedFood(1001, "Feijão", 5.99);
    Product* p3 = new FreshFood(1002, "Abacate", 5, 3.5);
    
    
    cout << "\n--- Testando isLowerCode ---" << endl;

    Product& lowerProduct1 = *isLowerCode(*p1, *p2);  
    cout << "Produto com menor código de barras (p1 e p2): ";
    lowerProduct1.print();

    Product& lowerProduct2 = *isLowerCode(*p2, *p3);  
    cout << "Produto com menor código de barras (p2 e p3): ";
    lowerProduct2.print();

    Product& lowerProduct3 = *isLowerCode(*p1, *p3);  
    cout << "Produto com menor código de barras (p1 e p3): ";
    lowerProduct3.print();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}

// g++ -std=c++17 products.cpp freshfood.cpp prepackedfood.cpp main3.cpp -o main3