#include <iostream>

int searchArray(int numbers[], int size, int indexes){

    for(int i = 0; i < size; i++){
        if(numbers[i]==indexes){
            return i;
        }
    }
    return -1;

}
int main(){

    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int index;
    int size;
    size = sizeof(numbers)/sizeof(numbers[0]);
    int myNum;

    std::cout << "enter Number You Wanna Search through The Index: " << std::endl;
    std::cin >> myNum;

    index = searchArray(numbers,size,myNum);

    if(index != -1 ){
        std::cout << myNum << " Was Found At Index " << index << std::endl;
    }else{
        std::cout << "Index Not Found! " << std::endl;
    }



}