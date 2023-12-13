#include <iostream>

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);
int main(){

    std::string cardNumber;
    int result = 0;

    std::cout << "Enter card number: ";
    std::cin >> cardNumber

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber)

    return 0;

}