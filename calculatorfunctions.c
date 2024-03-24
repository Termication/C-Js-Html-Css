#include <stdio.h>

void sub(int a, int b){
    printf("sub of %d - %d = %d\n", a, b, a-b);
    
}

void sum(int a, int b){
    printf("sum of %d + %d = %d\n", a, b, a+b);
    
}

void div(int a, int b){
    printf("div of %d / %d = %d\n", a, b, a/b);
    
}

void mul(int a, int b){
    printf("mul of %d x %d = %d\n", a, b, a*b);
    
}
int main(){
    int choice, a, b;
    void (*fptr[4])(int, int) = {sub, sum, div, mul};

    printf("enter numb a: ");
    scanf("%d",&a);

    printf("enter choice operator: ");
    scanf("%d", &choice);

    printf("enter numb b: ");
    scanf("%d",&b);

    (*fptr[choice])(a, b);


}