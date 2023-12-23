#include <stdio.h>

int findmax(int a, int b, int c){

    int maxium;

    if(a > b && a > c ){
        return a;
    }
    else if(b > a && b > c){
        
        return b;
    }
    else{
        return c;
    }
    
}
int main(void){
    
    int max = findmax(36,80,12);

    printf("max is : %d", max);

}