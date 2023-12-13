#include <iostream>
#include <string>

int main (){

    std::string name = "Karabo";

    for(int i = (name.length() - 1); i >= 0; i--){
        std::cout << name[i] << std::endl;
    }

    std::cout << sizeof(name);

}