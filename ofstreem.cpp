#include <iostream>
#include <fstream>

int main (){
    std::ofstream tynnia("kabe.txt");

    std::cout << "Enter  players id, name and money " << std::endl;
    std::cout << "press  Ctrl+Z to quit" << std::endl;

    int idNumber;
    std::string name;
    double money;

    while(std::cin >> idNumber >> name >> money){
        tynnia << idNumber << ' ' << name << ' ' << money << std::endl;
}
}
