#include <iostream>

int main(){
    int size = 5;
    int arr [size] ={4,7,8,9,6};

    for (int i = 0; i < 5; i++){
        std::cout << arr[i] << std::endl;
    }
    size--;
    std::cout << "The last array index is: " << size << std::endl;
}