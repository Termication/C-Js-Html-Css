#include <stdio.h>
#include <string.h>

int main(void){

    printf("what's your name\n");

    char name [20];
    fgets(name, 25, stdin);
    name[strlen(name)-1] = '\0';

    while(strlen(name) == 0){
        printf("enter valid name\n");
        printf("what's your name\n");
        fgets(name, 25, stdin);
        name[strlen(name)-1] = '\0';

    }
    printf("\nhello  %s", name);
    return 0;

}