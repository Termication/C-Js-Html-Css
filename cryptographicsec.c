#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //pseudo rando numbers

    srand(time(0));

    int number1 = (rand()) % 7;
    int number2 = (rand()) % 7;
    int number3 = (rand()) % 7;
    int number4 = (rand()) % 7;

    printf("%d \n", number1);
    printf("%d \n", number2);
    printf("%d \n", number3);
    printf("%d \n", number4);

    if(number1 == 3 && number2 == 5){
        printf("You made it\n");
    }
    else if(number4 == 6){
        printf("You have something\n");
    }
    else{
        printf("try again\n");
    }
}