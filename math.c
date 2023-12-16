#include <math.h>
#include <stdio.h>

int main(void){
    int numb1,numb2;
    char op;
    printf("enter operator to use\n");
    scanf("%c", &op);
    printf("enter number 1: \n");
    scanf("%d",&numb1);
    printf("enter number 2: \n");
    scanf("%d",&numb2);

    

    switch(op){
        case '-': printf("results = %d\n", (numb1 - numb2)); break;
        case '+': printf("results = %d\n", (numb1 + numb2)); break;
        case '/': printf("results = %d\n", (numb1 / numb2)); break;
        case '*': printf("results = %d\n", (numb1 * numb2)); break;
    }
}