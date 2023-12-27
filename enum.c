#include <stdio.h>

enum Day{ Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};

int main(void){

    enum Day today = 5;

    printf("%d\n", today);

    if(today == 6 || today == 7){
        printf("It's Weekend, Lets Party\n");
    }
    else{
        printf("Its A Working Week\n");
    }
}