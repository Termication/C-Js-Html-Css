#include <iostream>


int main(){
    int userPin = 4869, pin,  Wrongs = 0;
    do{
    
        std::cout << "Enter Pin: \n";
        std::cin >> pin;
        if(userPin != pin){
            Wrongs++;
            std::cout << "Wrong Pin " << std::endl;
        }

    }while(Wrongs < 3 && userPin != pin);

    if(Wrongs < 3){
        std::cout << "Loading...." << std::endl;
    }else{
        std::cout << "Blocked" << std::endl;
    }
}
