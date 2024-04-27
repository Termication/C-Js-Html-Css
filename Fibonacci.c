#include <stdio.h>

void fib(int n){

    int i, first = 0, second = 1, third;
    printf("\n%d", first);

    for(i=0; i < n; i++){
        third = first + second;
        first = second;
        second = third;
        printf("\n%d" , first);
    }
}

int main(){
    fib(13);
}