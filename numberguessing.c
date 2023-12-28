#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int main(void){
    int guesses=0, answer,guess;

    srand(time(0));

    answer = (rand() % 100 + 1);

    do{
        printf("\n Enter Your Guess: ");
        scanf("%d", &guess);

        if(guess > answer){
            printf("\n You guessed too high");
        }else if(guess < answer){
            printf("you guessed too low");
        }else{
            printf("\n You are CORRECT!");
        }
        guesses++;

    }while(answer != guess);

    printf("You guessed %d times ", guesses);


}