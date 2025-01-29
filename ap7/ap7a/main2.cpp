#include <iostream>
#include "products.h"
#include "prepackedfood.h"
#include "freshfood.h"

using namespace std;

int main(void){

    Product *products [3];

    products[0] = new Product(1000, "Arroz");
    products[1] = new PrePackedFood(1001, "Feijão", 27);
    products[2] = new FreshFood(1002, "Abacate", 5, 2.5);

    FreshFood *freshfoodPtr = new FreshFood(1003, "Mamão", 10, 7);

    products[0]->print();
    products[1]->print();
    products[2]->print();

    freshfoodPtr->print();


    for (int i = 0; i < 3; i++){
        delete products[i];
    }


    delete freshfoodPtr;


    return 0;
}