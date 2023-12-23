#include <iostream>
#include <cmath>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

class NumberGame {
public:
    void playGame();
    
private:
    double getUserInput();
    double generateRandomNumber();
    double calculateResult(double num1, double num2);
    int determineWinner(double userNum, double computerNum, double result);
};

void NumberGame::playGame() {
    // Get input from the user
    double userNum = getUserInput();

    // Generate a random number for the computer
    double computerNum = generateRandomNumber();

    // Calculate the result
    double result = calculateResult(userNum, computerNum);

    // Determine the winner
    int winner = determineWinner(userNum, computerNum, result);

    // Display the results
    std::cout << "Your number: " << userNum << "\n";
    std::cout << "Computer's number: " << computerNum << "\n";
    std::cout << "The average multiplied by 0.8 is: " << result << "\n";

    if (winner == 0) {
        std::cout << "It's a tie!\n";
    } else if (winner == 1) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

double NumberGame::getUserInput() {
    std::cout << "Enter a number between 0 and 100: ";
    double num;
    std::cin >> num;

    // Validate the input
    while (num < 0 || num > 100) {
        std::cout << "Invalid input. Please enter a number between 0 and 100: ";
        std::cin >> num;
    }

    return num;
}

double NumberGame::generateRandomNumber() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 0 and 100
    return std::rand() % 101;
}

double NumberGame::calculateResult(double num1, double num2) {
    return (num1 + num2) / 2 * 0.8;
}

int NumberGame::determineWinner(double userNum, double computerNum, double result) {
    double userDifference = std::fabs(userNum - result);
    double computerDifference = std::fabs(computerNum - result);

    if (userDifference < computerDifference) {
        return 1; // User wins
    } else if (computerDifference < userDifference) {
        return 2; // Computer wins
    } else {
        return 0; // It's a tie
    }
}

int main() {
    NumberGame game;
    game.playGame();

    return 0;
}
