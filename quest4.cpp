#include <iostream>

using namespace std;

bool isEqual(char a, char b){

    if (a==b){
        return true;
    }else{
        return false;
    }
}

main (){

    char c1, c2;

    cout << "Enter the first character: " << endl;
    cin >> c1;
    cout << " Enter the Second character: " << endl;
    cin >> c2;

    if (isEqual(c1, c2)) {
        std::cout << "The characters are the same." << std::endl;
    } else {
        std::cout << "The characters are different." << std::endl;
    }
}