#include <stdio.h>

int main(void){
    for(int i = 1;  i <= 10; i++){
        for(int j =1; j <= 5; j++){
            printf("%d ", j*i);
        }
        printf("\n");
    }
    
}