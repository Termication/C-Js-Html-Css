#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 5

// Define the maximum length of a question or answer
#define MAX_LENGTH 100

// Function to display a question and its options
void displayQuestion(char question[MAX_LENGTH], char options[4][MAX_LENGTH]) {
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
}

// Function to get user input for the answer
int getAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

int main() {
    // Questions and answers
    char questions[MAX_QUESTIONS][MAX_LENGTH] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "What is the largest mammal?",
        "Who wrote 'Romeo and Juliet'?",
        "What is the square root of 64?"
    };

    char options[MAX_QUESTIONS][4][MAX_LENGTH] = {
        {"A. London", "B. Paris", "C. Berlin", "D. Rome"},
        {"A. Earth", "B. Mars", "C. Venus", "D. Jupiter"},
        {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Hippopotamus"},
        {"A. Charles Dickens", "B. William Shakespeare", "C. Jane Austen", "D. Mark Twain"},
        {"A. 4", "B. 6", "C. 8", "D. 10"}
    };

    int correctAnswers[MAX_QUESTIONS] = {2, 2, 1, 2, 3}; // Correct answers (1-4)

    // Variables for scoring
    int score = 0;
    int totalQuestions = 0;

    printf("Welcome to the Quiz Game!\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // Display the current question
        displayQuestion(questions[i], options[i]);

        // Get user's answer
        int userAnswer = getAnswer();

        // Check if the answer is correct
        if (userAnswer >= 1 && userAnswer <= 4) {
            if (userAnswer == correctAnswers[i]) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %c.\n", 'A' + correctAnswers[i] - 1);
            }
            totalQuestions++;
        } else {
            printf("Invalid answer. Skipping question.\n");
        }

        // Add a newline for better readability
        printf("\n");
    }

    // Display final score
    printf("Quiz completed!\n");
    printf("Your score: %d/%d\n", score, totalQuestions);

    return 0;
}
