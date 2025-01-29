#include <iostream>
#include <iomanip>
#include "products.h"
#include "freshfood.h"
#include "prepackedfood.h"

using namespace std;

void record(){

    Product *products [4];
    static double precoTotal = 0;

    for (int i = 0; i < 4; i++){

        string checkout;
        cin >> checkout;

        if (checkout == "fresh"){

            double precoItem;
            products[i] = new FreshFood();
            products[i]->scanner();

            precoItem = dynamic_cast<FreshFood*>(products[i])->getPeso() * dynamic_cast<FreshFood*>(products[i])->getPesoPorKilo();
            precoTotal += precoItem;

            /*if (fresh){
            precoItem = products[i]->getPeso() * products[i]->getPesoPorKilo();
            precoTotal += precoItem;
            }*/

        } else if (checkout == "pre-packed"){

            products[i] = new PrePackedFood();
            products[i]->scanner();
            precoTotal += dynamic_cast<PrePackedFood*>(products[i])->getUnitPrice();

            /*if (prepacked){
            products[i] = new PrePackedFood();
            precoTotal += products[i]->getUnitPrice();
            }*/

        } 
    }

    for (int j = 0; j < 4; j++){
        products[j]->print();
    }

    for (int m = 0; m < 4; m++){
        delete products[m];
    }

    cout << "Preço total: R$" << fixed << setprecision(2) << precoTotal;

}

int main(void){

    record();

    return 0;
}

// g++ -std=c++17 freshfood.cpp prepackedfood.cpp products.cpp main4.cpp -o main4