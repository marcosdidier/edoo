#include <iostream>
#include "date.h"

int main(void){

    Date data1;
    data1.init(21, 05, 2005);
    data1.print();

    Date data2;
    data2.init();
    data2.print();

    return 0;
}