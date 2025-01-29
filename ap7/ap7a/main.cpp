#include <iostream>
#include "products.h"
#include "prepackedfood.h"
#include "freshfood.h"

using namespace std;


int main() {
    Product p1(1001, "Arroz");
    Product p2; 
    
    cout << "\n--- Testando a classe Product ---\n";
    p1.print();
    p2.scanner();
    p2.print(); 

    PrePackedFood pf1(2002, "Macarrão", 5.99);
    PrePackedFood pf2;

    cout << "\n--- Testando a classe PrePackedFood ---\n";
    pf1.print();
    pf2.scanner();
    pf2.print();

    pf2.setUnitPrice(6.49);
    cout << "Novo preço do produto: " << pf2.getUnitPrice() << " R$\n";

    FreshFood ff1(3003, "Maçã", 1.5, 4.99); 
    FreshFood ff2;

    cout << "\n--- Testando a classe FreshFood ---\n";
    ff1.print();
    ff2.scanner();
    ff2.print();

    ff2.setPeso(2.0);
    ff2.setPesoPorKilo(5.49);
    cout << "Novo peso do produto: " << ff2.getPeso() << " kg\n";
    cout << "Novo preço por kg: " << ff2.getPesoPorKilo() << " R$\n";

    Product& produto_final = *isLowerCode(ff1, ff2);
    produto_final.print();

    produto_final.setCode(2000);
    produto_final.setName("Damasco");

    ff1.print();

    return 0;
}