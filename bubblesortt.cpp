#include <iostream>

using namespace std;

int main(void){

    int temp;

    int arr[8] = {20,1,2,9,5,3,7};

    for(int i = 0; i<8; i++ ){
        for(int j =i+1; j <8; j++){
            if(arr[j] < arr[i]){
                arr[i] = temp;
                arr[i] = arr[j];
                temp = arr[j];
            }
        }
    }
    for (int i = 0; i < 8; i++){
        cout << i;
    }
    cout << endl;
}