#include <iostream>

using namespace std;

int main(void){
    int i,j,p,temp,min;
    int arr[10] = {2,3,6,9,11,8,0,7};

    cout << "\n Unsorted0";

    for(int i = 0; i < 10; i ++){
        cout << arr[i];
    }
    cout << "\t" << endl;

    for(int i= 0; i < 10; i++){
        min = arr[i];
        p = i;
        for(j = i+1; j<10; j++){
            if(min > arr[j]){
                min = arr[j];
                p=j;

            }
        }
        temp = arr[i];
        arr[i]= arr[p];
        arr[p]=temp;
    }
    for(i = 0; i<10; i++){
        cout << arr[i];
    }
    cout << endl;


}