#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

    double number = 23.987;

    cout << right               
         << fixed               
         << setprecision(2)     
         << setw(12)            
         << number              
         << endl;

    double number2 = -123.456;

    cout << scientific << setprecision(4) << setw(10) << number2 << endl;

    

    return 0;
}