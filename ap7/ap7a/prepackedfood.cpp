#include "prepackedfood.h"

PrePackedFood::PrePackedFood() : Product(), unitPrice(0.0) {}

PrePackedFood::PrePackedFood(long barcode, const string&name, double unitPrice) :
    Product(barcode, name)
{
    this->unitPrice = unitPrice;
}

PrePackedFood::~PrePackedFood(){
    cout << "O objeto " << getName() << " foi destruído" << endl;
}

void PrePackedFood::setUnitPrice(double x){ unitPrice = x; }

double PrePackedFood::getUnitPrice() const { return unitPrice; }

void PrePackedFood::scanner(){
    long barcode;
    string name;
    double unitPrice;


    cout << "Você escolheu alimento PRÉ-EMBALADO!" << endl;
    cout << "Digite na seguinte ordem o código de barras, o nome e o preço do produto que deseja cadastrar: " << endl;
    cin >> barcode >> name >> unitPrice;
    cout << endl;

    setCode(barcode);
    setName(name);
    setUnitPrice(unitPrice);

}

void PrePackedFood::print() const{
    cout << "Nome do produto: " << getName() << endl;
    cout << "Código de barra do produto: " << getCode() << endl;
    cout << "Preço unitário do produto: " << getUnitPrice() << endl;
    cout << endl;
}