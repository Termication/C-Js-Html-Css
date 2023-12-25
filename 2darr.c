#include <stdio.h>

int main(void){
    int prices[3][3]= {{2,3,1},{6,7,4},{3,5,8}};

    int rows = sizeof(prices)/sizeof(prices[0]);
    int cols = sizeof(prices[0])/sizeof(prices[0][0]);

    printf("We have %d rows\n", rows);
    printf("We have %d columns\n", cols);
    printf("\n");

    for(int i =0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d", prices[i][j]);
        }
        printf("\n");
    }
}