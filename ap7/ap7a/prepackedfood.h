#ifndef PREPACKEDFOOD_H
#define PREPACKEDFOOD_H

#include <iostream>
#include "products.h"

using namespace std;

class PrePackedFood : public Product{
    private:
    double unitPrice;

    public:
    
    PrePackedFood();
    PrePackedFood(long barcode, const string& name, double unitPrice = 0.0);

    ~PrePackedFood();

    void setUnitPrice(double x);
    double getUnitPrice() const;
    void scanner()override;
    void print() const override;



};

#endif