#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // seed random number generator
    int secretNumber = rand() % 100 + 1; // random number between 1 and 100
    int guess = 0;
    int numGuesses = 0;

    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (guess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        numGuesses++;

        if (guess > secretNumber) {
            std::cout << "Your guess is too high." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Your guess is too low." << std::endl;
        }
    }

    std::cout << "Congratulations! You guessed the number in " << numGuesses << " tries." << std::endl;

    return 0;
}
