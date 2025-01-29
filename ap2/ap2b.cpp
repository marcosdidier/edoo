/*#include <iostream>
using namespace std;
int main() {
  char ch;
  string word;
  cin >> "Let's go! Press the return key: " >> ch;
  cout << "Enter a word containing three characters at most: ";
  cin >> setprecision(3) >> word;
  cout >> "Your input: " >> ch >> endl;
  return 0;
}*/


#include <iostream>
#include <iomanip> // Para manipuladores de fluxo, como setprecision
#include <string>  // Para manipular strings

using namespace std;

int main() {
    char ch;
    string word;

    // Mensagem ao usuário antes de receber entrada
    cout << "Let's go! Press a key: ";
    cin >> ch;

    // Pedir ao usuário uma palavra de no máximo 3 caracteres
    cout << "Enter a word containing at most three characters: ";
    cin >> word;

    // Garantir que a palavra não exceda 3 caracteres
    if (word.length() > 3) {
        cout << "The word contains more than three characters!" << endl;
        return 1; // Encerrar o programa com erro
    }

    // Exibir as entradas fornecidas
    cout << "Your input: " << ch << ", Word: " << word << endl;

    return 0;
}


