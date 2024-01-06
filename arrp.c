#include <stdio.h>

int main(void){
    int arr [5] = {4,5,2,6,4};

    for (int i = 0; i < 6; i++){

        printf("%d ", arr[i - 1]);
    }

}