#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int seed;

    // Read an integer between 0 and 65535 to seed the random number generator
    cout << "Enter an integer between 0 and 65535: ";
    cin >> seed;

    // Check if the seed is in the valid range
    if (seed < 0 || seed > 65535) {
        cout << "Invalid input. Please enter a number between 0 and 65535." << endl;
        return 1; // Exit the program if input is invalid
    }

    // Seed the random number generator
    srand(seed);

    // Output 20 random numbers between 1 and 100
    cout << "20 random numbers between 1 and 100: " << endl;
    for (int i = 0; i < 20; i++) {
        // Generate a random number between 1 and 100
        int randomNum = rand() % 100 + 1;
        cout << randomNum << " ";
    }

    cout << endl;

    return 0;
}