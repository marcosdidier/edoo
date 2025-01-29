#include <iostream>

int *splice(int a1[], int a2[], int len1, int len2, int pos){
    int size = len1 + len2;
    int *novoArray = new int [size];
    int segundaPartea1 = pos + 1;

    for (int i = 0; i <= pos; i++){
        novoArray[i] = a1[i];
    }

    for (int j = 0; j < len2; j++){
        novoArray[segundaPartea1 + j] = a2[j];
    }

    int s = (pos + len2 + 1);

    for (int k = pos + 1; k < len1; k++){
        novoArray[k + len2] = a1[k];
    }

    return novoArray;
}

int main(void){

    int a1 [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2 [5] = {10, 11, 12, 13, 14};

    int *a3 = splice(a1, a2, 10, 5, 7);

    for (int m = 0; m < 15; m++){
        std::cout << a3[m] << " ";
    }

    delete a3;

}