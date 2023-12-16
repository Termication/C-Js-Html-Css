#include <stdio.h>

int main(void){
    char name[25];

    printf("what's your name?\n");
    scanf("%s", &name);
    fgets(name, 25, stdin);

    printf("okay your name is %s", name);
}