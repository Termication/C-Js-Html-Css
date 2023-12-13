#include <iostream>
#include <fstream>

main(){
    std::ofstream Out;
    std::ifstream in;
    Out.open("Out.dat");
    in.open("In.dat");

    if(in.fail()){
        std::cout << "FAILED In " << std::endl;
    }
    if(Out.fail()){
        std::cout << "FAILED Out " << std::endl;
    }
    
    int nub, nuc, nud;

    in >> nub >> nuc >> nud;
    Out << "The sum of numbers is " << (nub + nuc + nud);

    Out.close();
    in.close();
}