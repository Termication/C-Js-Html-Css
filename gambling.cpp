#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    int playerBet, coinFlip;
    int balance = 100;

    srand(time(0));

    while (balance > 0){
        std::cout << "Current Balance " << balance << std::endl;
        std::cout << "Enter Your Bet 1 for Heads And 2 For Tails " << std::endl;
        std::cin >> playerBet;

        coinFlip = rand() % 2;

        if (playerBet == coinFlip){
            std::cout << "You Win" << std::endl;
            balance += 10;
        } else {
            std::cout << "Sorry No win " << std::endl;
            balance -= 10;
        }
    }
    std::cout << "Game over, Your final balance is " << balance << std::endl;
}