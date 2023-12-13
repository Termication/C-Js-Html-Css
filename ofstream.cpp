#include <iostream>
#include <fstream>

int main(){

    std::ofstream tynnia ("kabe.txt");
    
    if(tynnia.is_open()){
        std::cout << "open \n";
    }else{
        std::cout << "closed bruh \n";

    }

    tynnia << "i love her and she loves me\n";

    tynnia.close();
}