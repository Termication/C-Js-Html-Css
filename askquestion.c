#include <stdio.h>

// Function to display a question and get the user's answer
int askQuestion(const char *question, const char *option1, const char *option2, const char *option3, int correctAnswer) {
    int userAnswer;
    
    printf("%s\n", question);
    printf("1. %s\n", option1);
    printf("2. %s\n", option2);
    printf("3. %s\n", option3);
    printf("Your answer (1-3): ");
    scanf("%d", &userAnswer);

    if (userAnswer == correctAnswer) {
        printf("Correct!\n\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %d. Better luck next time!\n\n", correctAnswer);
        return 0;
    }
}

int main() {
    int score = 0;

    printf("Welcome to the Quiz App!\n");

    // Question 1
    score += askQuestion("What is the capital of France?", "Paris", "London", "Berlin", 1);

    // Question 2
    score += askQuestion("Which planet is known as the Red Planet?", "Mars", "Venus", "Jupiter", 1);

    // Question 3
    score += askQuestion("What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", 2);

    // Display final score
    printf("Your final score is: %d out of 3\n", score);

    return 0;
}
