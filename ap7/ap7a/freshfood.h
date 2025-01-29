#ifndef FRESHFOOD_H
#define FRESHFOOD_H

#include <iostream>
#include "products.h"

using namespace std;

class FreshFood : public Product{
    private:
    double peso;
    double pesoPorKilo;

    public:
 
    FreshFood();
    FreshFood(long barcode, const string& name, double peso = 0.0, double pesoPorKilo = 0.0);

    ~FreshFood();

    void setPeso(double peso);
    double getPeso() const;
    void setPesoPorKilo(double pesoPorKilo);
    double getPesoPorKilo() const;
    void scanner();
    void print() const override;

};

#endif