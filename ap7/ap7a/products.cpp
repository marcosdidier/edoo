#include <iostream>
#include "products.h"

Product::Product(long barcode, string name) : barcode(barcode), name(name){}

Product::~Product(){
    cout << "O produto " << name << " foi destruído" << endl;
}

void Product::setCode(long code){ this->barcode = code; }

long Product::getCode() const{ return this->barcode; }

void Product::setName(string name) { this->name = name; }

string Product::getName() const { return this->name ;}

void Product::scanner(){
    long barcode;
    string name;

    cout << "Digite na ordem o código de barras e o nome do produto" << endl;
    cin >> barcode;
    cin >> name;
    setCode(barcode);
    setName(name);
}

void Product::print() const{
    cout << "O produto escolhido é o " << name << " e tem o código de barras de número: " << barcode << endl;
}

Product *isLowerCode(Product& p1, Product& p2){
    if (p1.getCode() > p2.getCode()){
        return &p2;
    } else {
        return &p1;
    }
}



