#include <iostream>

void twice(int& num1, int& num2) {
    num1 *= 2;
    num2 *= 2;
}

int main() {
    int numbA, numbB;
    std::cout << "Enter the first number: ";
    std::cin >> numbA;
    std::cout << "Enter the second number: ";
    std::cin >> numbB;

    twice(numbA, numbB);

    std::cout << "Twice the first number: " << numbA << std::endl;
    std::cout << "Twice the second number: " << numbB << std::endl;

    return 0;
}
