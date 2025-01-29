#include <iostream>



int main(void){

    int i = -2;
    int x = -4 * i++ -6 % 4;

    std::cout << x;


    return 0;
}