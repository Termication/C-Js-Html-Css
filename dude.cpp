#include <iostream>

int main(){

   double a, b, c;
   std::cout << "Enter a, b, c for ur triagnal: \n";
   std::cin >> a;
   std::cin >> b;
   std::cin >> c;


   if(a==b && b==c){
    std::cout << "Equilateral triangle";
   }
   else if(a!=b && a!=c && b!=c){
    std::cout << " Scalene triangle";
   }
   else if(a==b && a!=c && b!=c){
    std::cout << "isosceles";
   }
   return 0;

}