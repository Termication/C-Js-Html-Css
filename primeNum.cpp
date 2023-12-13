#include <iostream>

bool Isprime(int numb){
    if(numb ==1){
        return false; 
    }
     if(numb <= 3){
        return true;
    }
     if(numb % 2 == 0 || numb % 3 ==0){
        return false;
    }

    if(numb == 5 || numb == 7){
        return true;
    }    
    if(numb % 5 == 0  || numb % 7 == 0){
        return false;
    }
    return true;
}

// or

   for(int i = 2; i*i <= numb; i++){
    if(numb % i == 0){
        return false;
    }
}
int main(){
    std::cout << "Enter lower limit " << std::endl;
    int lower, upper;
    std::cin >> lower;
    std::cout << "Enter upper limit " << std::endl;
    std::cin >> upper;

    for(int i = lower; i <= upper; i++){
        if(Isprime(i)){
            std::cout << "Prime: " << i << " ";
        }
    }
    std::cout << std::endl;

}