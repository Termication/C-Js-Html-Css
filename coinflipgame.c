#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a coin flip (returns 0 for heads, 1 for tails)
int flipCoin() {
    return rand() % 2;
}

int main() {
    int userGuess, coinResult;

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("Welcome to the Coin Flipping Game!\n");
    printf("Make a guess (0 for heads, 1 for tails): ");
    scanf("%d", &userGuess);

    // Check if the user input is valid
    if (userGuess != 0 && userGuess != 1) {
        printf("Invalid input. Please enter 0 for heads or 1 for tails.\n");
        return 1; // Exit with an error code
    }

    // Simulate the coin flip
    coinResult = flipCoin();

    // Display the result
    printf("Coin result: %s\n", (coinResult == 0) ? "Heads" : "Tails");

    // Check if the user's guess matches the coin result
    if (userGuess == coinResult) {
        printf("Congratulations! You guessed correctly.\n");
    } else {
        printf("Sorry, you guessed incorrectly.\n");
    }

    return 0;
}
