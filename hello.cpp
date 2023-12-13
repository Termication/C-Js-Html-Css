#include <iostream>
#include <cmath>


int main(){
 
    char op;
    double number1;
    double number2;
    double result;


    std::cout << "##########Calculator##########\n";

    std::cout << "enter either (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter Number A: ";
    std::cin >> number1;

    std::cout << "Enter Number B: ";
    std::cin >> number2;

    switch(op){
        case '+':
           result = number1 + number2;
           std::cout << "result: " << result << '\n';
           break;

        case '*':
           result = number1 * number2;
           std::cout << "result: " << result << '\n';
           break;

        case '-':
           result = number1 - number2;
           std::cout << "result: " << result << '\n';
           break;

        case '/':
           result = number1 / number2;
           std::cout << "result: " << result << '\n';
           break;

        default :
           std::cout << "ERROR Encountered\n";
           break;
    }
   

}