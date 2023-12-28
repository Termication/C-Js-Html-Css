#include <iostream>
#include <cstdlib>
#include <ctime>

class NumberGuessingGame {
private:
    int answer;
    int guess;
    int guesses;

public:
    NumberGuessingGame() {
        guesses = 0;
        srand(time(0));
        answer = (rand() % 100 + 1);
    }

    void playGame() {
        do {
            std::cout << "\nEnter Your Guess: ";
            std::cin >> guess;

            if (guess > answer) {
                std::cout << "\nYou guessed too high";
            } else if (guess < answer) {
                std::cout << "You guessed too low";
            } else {
                std::cout << "\nYou are CORRECT!";
            }

            guesses++;

        } while (answer != guess);

        std::cout << "\nThe answer is: " << answer << "\n";
        std::cout << "You guessed " << guesses << " times\n";
    }
};

int main() {
    NumberGuessingGame game;
    game.playGame();

    return 0;
}
