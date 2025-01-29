#include <iostream>
#include "article.h"
#include <iomanip>

using namespace std;

int Article::counter = 0;

Article obj1(22, "pipoca", 37.50);

void test();

int main(void){

    Article obj2(37, "tenis", 22.27);

    /*obj1.print();
    obj1.getName();
    obj1.setName("Mike");
    obj1.print();*/

    obj2.print();
    obj2.getName();
    obj2.setName("Jezé");
    obj2.setPrice(21525612);
    obj2.print();



    //test();
    //test();

    Article* obj5 = (&obj2);

    obj5->print();

    obj5->setName("Maskeiko");

    obj2.print();



    cout << "Número de artigos depois de 2 chamadas da função test: " << Article::getObjectCount() << endl;


    return 0;
}
    
void test(){
    Article obj3(467, "gesso", 49.99);
    static Article obj4(321, "bola", 54.67);

    obj3.print();
    obj3.getName();
    obj3.setName("Eh ugue");
    obj3.setPrice(212.14);
    obj3.print();

    obj4.print();
    obj4.getName();
    obj4.setNumber(14);
    obj4.setName("raiinbow");
    obj4.setPrice(22.22);
    obj4.print();

}