#include "freshfood.h"

FreshFood::FreshFood() : Product(), peso(0.0), pesoPorKilo(0.0) {}

FreshFood::FreshFood(long barcode, const string& name, double peso, double pesoPorKilo) 
: Product(barcode,name){
    this->peso = peso;
    this->pesoPorKilo = pesoPorKilo;
}

FreshFood::~FreshFood(){
    cout << "O produto de nome " << getName() << " foi destruído" << endl;
}

void FreshFood::setPeso(double peso) { this->peso = peso; }

double FreshFood::getPeso() const { return peso; }

void FreshFood::setPesoPorKilo(double pesoPorKilo){ this->pesoPorKilo = pesoPorKilo; }

double FreshFood::getPesoPorKilo() const { return pesoPorKilo; }

void FreshFood::scanner(){
    long barcode;
    string name;
    double peso;
    double pesoPorKilo;

    cout << "Você escolheu alimento FRESCO!" << endl;
    cout << "Digite na seguinte ordem o código de barras, o nome, o peso e o peso por quilo do produto que deseja cadastrar: " << endl;
    cin >> barcode >> name >> peso >> pesoPorKilo;
    cout << endl;
    setCode(barcode);
    setName(name);
    setPeso(peso);
    setPesoPorKilo(pesoPorKilo);
}

void FreshFood::print()const{
    cout << "Nome do produto: " << getName() << endl;
    cout << "Código de barra do produto: " << getCode() << endl;
    cout << "Peso do produto: " << getPeso() << endl;
    cout << "Peso por quilo do produto: " << getPesoPorKilo() << endl;
    cout << endl;

}