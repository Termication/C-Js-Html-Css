#include <iostream>

bool Isaprime(int no){
    if(no == 1){
        return true;
    }
    if(no == 2 || no == 3){
        return true;
    }
    if(no < 0){
        return false;
    }
    if(no == 5 || no == 7){
        return true;
    }
    if(no % 2 == 0 || no % 3 == 0){
        return false;
    }
    if(no % 5 == 0 || no % 7 == 0){
        return false;
    }
    return true;
}
int main (){
    int input;
    std::cout << "Enter a Number: " << std::endl;
    std::cin >> input;

    int number = Isaprime(input);

    if(number == true){
        std::cout << "yebooo" << std::endl;
    }else{
        std::cout << "Aowah " << std::endl;
    }

    
}