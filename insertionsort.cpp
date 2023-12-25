#include <iostream>

using namespace std;


int main(void){
    int num,temp,j;

    int arr[10];

    cout << "\n Enter the elements number: ";

    cin >> num;
    cout << "\n Enter the numbers now :";

    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= num - 1; i++){
        temp = arr[i];
        j = i - 1;

        while(temp < arr[j] && (j>0)){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]= temp;
        
    }
    for(int i = 0;i<num; i++){
        cout << arr[i];
    }
    cout << endl;
}