#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    srand(time(0));

    
    int randomNumber = rand() % 100 + 1;

   
    std::cout << "Guess the number between 1 and 100: ";
    int userGuess;
    std::cin >> userGuess;

    
    while (userGuess != randomNumber) {
        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else {
            std::cout << "Too low! Try again: ";
        }
        std::cin >> userGuess;
    }

   
    std::cout << "Congratulations! You guessed the correct number.\n";

    return 0;
}