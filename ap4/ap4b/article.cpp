#include <iostream>
#include <string>
#include <iomanip>
#include "article.h"

using namespace std;

Article::Article(long number, const string& name, double price){
    this->number = number;
    this->name = name;
    if (price < 0){
        this->price = 0.0;
    } else {
        this->price = price;
    }

    counter++;
    cout << "An object of type Article " << name << " is created." << endl;
    cout << "This is the " << counter << " Article." << endl;

}

void Article::print(){
    cout << setw(15) << "Número do produto: " << number << endl;
    cout << setw(15) << "Nome do produto: " << name << endl;
    cout << setw(15) << "Preço do produto: " << price << endl;
}

long Article::getNumber() const{
    return this->number;
}

string Article::getName() const{
    return this->name;
}

double Article::getPrice() const{
    return this->price;
}

void Article::setNumber(long number){
    this->number = number;
}

void Article::setName(const string& name){
    this->name = name;
}

void Article::setPrice(double price){
    if (price < 0){
        this->price = 0.0;
    } else{
    this->price = price;
    }
}

Article::~Article(){
    counter--;
    cout << "The object of type Article " << name << " is destroyed." << endl;
    cout << "There are still " << counter << " articles." << endl;
}
