#include <iostream>
#include <string>

int searchArray(std::string fruits[], int size, std::string elements){

    for(int i = 0; i < size; i++){
        if(fruits[i] == elements){
            return i;
        }
        
    }
    return -1;
}

int main(){

    std::string fruits [] = {"banna", "apple", "apricot", "pineapple", "orange"};
    int size;
    size = sizeof(fruits)/sizeof(fruits[0]);
    int index;

    std::string myFruit;
    std::cout << "Enter Name Of Fruit To Search: " << std::endl;
    std::getline(std::cin, myFruit);

    index = searchArray(fruits, size, myFruit);

    if(index != -1){
        std::cout << myFruit << " Found At Index " << index << std::endl;
    }else{
        std::cout << myFruit << " Not Found" << std::endl;
    }


}