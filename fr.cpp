#include <iostream>

int factorial(int numb){
   int result = 1;
   for(int i =1 ; i <= numb; i++){
    result *= i;
   }
   return result;
}
int main(){

    int facto = factorial(10);
    std::cout << " factorial of  " << facto;
}