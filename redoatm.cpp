#include <iostream>

void showMenu(){
    std::cout << "_______________MENU_______________\n";
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "__________________________________\n";

}
int Pinsystem(){
        int userPin = 4869, pin, Wrongs = 0;
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

int main(){
    Pinsystem();


    int option;
    double Balance = 500;


    do{
        showMenu();
        std::cout << "Option : " << std::endl;
        std::cin >> option;
        system("cls");


    switch(option){
        case 1: std::cout << "Your Balance Is: " << Balance << std::endl; break;
        case 2: std::cout << "How Much Money Would You Like To Deposit: " << std::endl;
           double depositMoney;
           std::cin >> depositMoney;
           Balance += depositMoney;
           break;
        case 3: std::cout << "How Much Money Would You Like To Withdraw: " << std::endl;
           double withdrawMoney;
           std::cin >> withdrawMoney;
        
           if(withdrawMoney <= Balance){
            Balance -= withdrawMoney;

           }else{
            std::cout << "Insuffient Funds\n";
           }
           break;
        
    }
    }while(4!=option);
        std::cout << "THANK YOU FOR BANKING WITH US\n";
    



}