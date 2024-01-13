#include <stdio.h>

void encrypt(char message[]){
    
    for (int i = 0; message[i] != '\0'; i++){

        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = (message[i] - 1 - 'a') % 28 + 'a' ;

        }

    }
}
int main(){
    char message[100] = {"this was fun and we should do that again"};

    encrypt(message);

    printf("encrypted message: %s", message);
}