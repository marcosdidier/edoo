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

    freshfoodPtr->print();

    //Aprendendo a mexer com downcasting e upcasting:
    
    /*PrePackedFood *prepackedPtr = dynamic_cast<PrePackedFood*>(products[0]);

    if (prepackedPtr){
        prepackedPtr->print();
    }*/

    /*Product *productPtr = products[1];
    productPtr->Product::print();*/

    Product *productPtr2 = freshfoodPtr;
    productPtr2->Product::print();





    for (int i = 0; i < 3; i++){
        delete products[i];
    }

    //delete productPtr;
    delete productPtr2;


    //delete freshfoodPtr;


    return 0;
}

// g++ -std=c++17 products.cpp freshfood.cpp prepackedfood.cpp main2.cpp -o main2