#include <iostream>
#include <string>

int main(){

    char op;
    std::string strngOne = "10";
    std::string strngTwo = "2";
    int strn1 =  stoi(strngOne);
    int strn2 =  stoi(strngTwo); 

    std::cout << "enter operator" << std::endl;
    std::cin >> op;

    switch(op){

        case '+' : std::cout << strn1 + strn2 << std::endl; break;
        case '-' : std::cout << strn1 - strn2 << std::endl; break;
        case '*' : std::cout << strn1 * strn2 << std::endl; break;
        case '/' : std::cout << strn1 / strn2 << std::endl; break;
    
    }
}