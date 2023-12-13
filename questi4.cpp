#include <iostream>
#include <utility>

using namespace std;

int twice(int numb1, int numb2){

    numb1 *=2;
    numb2 *=2; 

    return std::make_pair(numb1, numb2);

}

int main(){
    int numbA, numbB;
    int resultA,resultB;

    cout << "Enter First Number You Want To Multiply By 2" << endl;
    cin >> numbA;
    cout << "Enter Second Number You Want To Multiply By 2" << endl;
    cin >> numbB;

    resultA, resultB = twice(numbA, numbB);

    cout << "First number X2 is " << resultA << endl;
    cout << "Second number X2 is " << resultB << endl;

}