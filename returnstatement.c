#include <stdio.h>


float area(float a){

    float areaa = a * a;

    return areaa;

}
int main(void){

    float side = 3.15;

    printf("%lf",area(side));
}
