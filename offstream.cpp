#include <iostream>
#include <fstream>

int main(){

    std::ifstream tynnia("kabe.txt");

    int id;
    std::string name;
    double money;

    while(tynnia >> id >> name >> money){
        std::cout << id << ' ' << name << ' ' << money << std::endl; 
    }
    tynnia.close();
}


