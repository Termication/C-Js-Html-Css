#include <iostream>

class Babe{
    public:

      int ageCalculator(){
       return age = (presentYear - year);
      }

       int age;
       int year;
       int presentYear{2023};
};



int main(){

    Babe Print;

    std::cout << "Enter The Year You Were Born In \n";
    std::cin >> Print.year;
    std::cout << "You Are "<< Print.ageCalculator() << " old!! \n";

}