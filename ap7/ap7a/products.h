#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
using namespace std;

class Product {

    private:
    long barcode;
    string name;

    public:
    Product(long barcode = 0, string name = "Produto sem nome");
    ~Product();

    void setCode(long code);
    long getCode(void) const;
    string getName() const;
    void setName(string name);
    void scanner(void);
    virtual void print(void) const;
    friend Product *isLowerCode(Product& p1, Product& p2);

};

#endif