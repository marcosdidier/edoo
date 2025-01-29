// A program containing errors!
/*# include <iostream>, <string>
# include <stdlib>
# void srand( seed);

int main() {
  string message "\nLearn from your mistakes!";
  cout << message << endl;
  int len = length( message);
  cout << "Length of the string: " << len << endl;
  // And a random number in addition:
  int a, b;
  a = srand(12.5);
  b = rand( a );
  cout << "\nRandom number: " << b << endl;
 return 0;
}*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main (void){
    string message = "\nLearn from your mistakes!";
    cout << message << endl;
    int len = message.length();
    cout << "Length of the string: " << len << endl;
    // And a randon number in addition:

    int a, b;
    srand(12);
    b = rand();

    cout << "\nRandom number: " << b << endl;

    return 0;

}


