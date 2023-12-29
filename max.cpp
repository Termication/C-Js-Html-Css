#include <iostream>

int main(){
    int arr[] = {12,16,5,8,7};

    int max;
    int min;
    max = arr[0];

    for(int i = 0; i < 5; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    min = arr[0];
    for(int i = 0; i < 5; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    std::cout << "The maximum number: " << max << std::endl;
    std::cout << "The minimum number: " << min << std::endl;

}