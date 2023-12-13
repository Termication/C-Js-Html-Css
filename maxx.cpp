#include <iostream>

void max_int(int input1, int input2, int& output){
    if(input1>input2){
        output = input1;
    }else{
        output = input2;
    }
}

int main(){
    int out_int;
    int in1{7};
    int in2{6};
    int max_int(in1,  in2, out_int);
    std::cout << "max  output " << out_int << std::endl;
}