#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 3

typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

void initializeQuestions(Question questions[]) {
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "A. Paris");
    strcpy(questions[0].options[1], "B. London");
    strcpy(questions[0].options[2], "C. Berlin");
    strcpy(questions[0].options[3], "D. Madrid");
    questions[0].correct_option = 0;

    // Add more questions similarly
}

void presentQuestion(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", question.options[i]);
    }
}

int getAnswer() {
    char answer[2];
    printf("Enter your answer (A, B, C, or D): ");
    scanf("%1s", answer);

    switch (answer[0]) {
        case 'A':
        case 'a':
            return 0;
        case 'B':
        case 'b':
            return 1;
        case 'C':
        case 'c':
            return 2;
        case 'D':
        case 'd':
            return 3;
        default:
            printf("Invalid input. Please enter A, B, C, or D.\n");
            return -1;
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    initializeQuestions(questions);

    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        presentQuestion(questions[i]);
        int userAnswer = getAnswer();

        if (userAnswer == questions[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", 'A' + questions[i].correct_option);
        }

        printf("\n");
    }

    printf("Quiz completed. Your score: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}
