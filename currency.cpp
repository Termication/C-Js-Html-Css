#include <iostream>
#include <iomanip>


int main(){

    float $number, Rnumber, currency$, currencyR, rate1;
    int option;

    rate1 = 18.36;

    currency$ = (Rnumber/rate1); 

    currencyR = ($number * rate1);

    std::cout << std::endl;
    std::cout << "What would you like to convert to \n";
    std::cout << "1. To USD\n";
    std::cout << "2. To ZAR\n";
    std::cin >> option;


    switch(option){
        case 1 : std::cout << "Convert To USD Dollars \n";
             std::cout << "Enter YOUR RANDS \n";
             std::cin >> Rnumber;
             std::cout << std::setprecision(4);
             std::cout << "Your rands in USD is  " << (Rnumber/rate1) << std::endl;
             break;

        case 2 : std::cout << "Convert to ZAR \n";
            std::cout << "Enter YOUR $ \n";
            std::cin >> Rnumber;
            std::cout << std::setprecision(4);
            std::cout << "Your USD in Rands is " << (Rnumber*rate1) << std::endl;
            break;
    }
    








}