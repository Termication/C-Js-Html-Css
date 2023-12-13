#include <iostream>
#include <string>

class Increment{
private:
    int bodycount;
public:
    Increment(int b  = 0){
        bodycount = b;
    }
void Print(){
    std::cout << "My bodycount is" << bodycount << std::endl;
}

void operator++(){
    ++bodycount;
}
void operator++(int){
    bodycount++;}


};

int main(){
    Increment ob(12);
    ++ob;
    ob++;
    ob.Print();
    
}