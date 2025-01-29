#include <iostream>
#include "fraction.h"

int main(void){

    Fraction f1(14, 3);
    Fraction f2(12, 7);

    f1+=f2;

    cout << f1 << endl;

    return 0;
}