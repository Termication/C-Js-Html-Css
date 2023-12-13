#include <iostream>

int sum(int a, int b){
    int result = a + b;
    std::cout << "results " << result << std::endl;
    return result;
}

int main(){
    int a{30};
    int b{2};

    int result = sum(a,b);
    std::cout << "result 2" << &result << std::endl;
    std::cout << "result 2" << result << std::endl;
}