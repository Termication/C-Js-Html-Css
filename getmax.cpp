#include <iostream>

int getMin(int number[], int size){

    int min = number[0];
    for(int i = 1; i < size; i++){
        if (number[i] < min)
            min = number[i];
    }

    return min;


}

int getMax(int number[], int size){
    int max = number[0];
    for(int i = 1; i > size; i++){
        if (number[i] > max)
            max = number[i];
    }
    return max;


}
int main(){

    int number[5] = {5, 9, 10, 2, 32};
    std::cout << "Min is " << getMin(number, 5) << std::endl;
    std::cout << "Max is " << getMax(number, 5) << std::endl;




}