#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

// Function to choose a random word from an array
char* chooseRandomWord(char* words[], int numWords) {
    int randomIndex = rand() % numWords;
    return words[randomIndex];
}

// Function to display the current state of the word
void displayWordState(const char* word, const char* guessedLetters) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");
}

// Function to check if the player has guessed all the letters
int allLettersGuessed(const char* word, const char* guessedLetters) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (strchr(guessedLetters, word[i]) == NULL) {
            return 0; // Not all letters guessed
        }
    }

    return 1; // All letters guessed
}

int main() {
    char* words[] = {"programming", "hangman", "computer", "language", "challenge"};
    int numWords = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));

    char* wordToGuess = chooseRandomWord(words, numWords);
    int wordLength = strlen(wordToGuess);

    char guessedLetters[MAX_WORD_LENGTH] = "";
    char guess;

    int incorrectTries = 0;

    printf("Welcome to Hangman!\n");

    do {
        printf("\nWord: ");
        displayWordState(wordToGuess, guessedLetters);

        printf("Enter your guess: ");
        scanf(" %c", &guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;
        guessedLetters[strlen(guessedLetters)] = '\0';

        if (strchr(wordToGuess, guess) != NULL) {
            printf("Correct guess!\n");
        } else {
            printf("Incorrect guess. Try again.\n");
            incorrectTries++;
        }

        if (allLettersGuessed(wordToGuess, guessedLetters)) {
            printf("\nCongratulations! You guessed the word: %s\n", wordToGuess);
            break;
        }

        printf("Incorrect tries left: %d\n", MAX_TRIES - incorrectTries);

    } while (incorrectTries < MAX_TRIES);

    if (incorrectTries == MAX_TRIES) {
        printf("\nSorry, you ran out of tries. The word was: %s\n", wordToGuess);
    }

    return 0;
}
