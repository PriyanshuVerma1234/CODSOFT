#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int secretNumber = rand() % 100 + 1; // Generate a secret number between 1 and 100
    int guess;

    cout << "Guess the number between 1 and 100!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl; // Fixed the newline character
        } else {
            cout << "Congratulations! You guessed the right number." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
