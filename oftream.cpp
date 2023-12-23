#include <iostream>
#include <fstream>

using namespace std;

int main(){
    cout << "Opening data.txt for appending data\n";
    ofstream fout;
    fout.open("data.txt, ios::app");
    if (fout.fail()){
        cout << "failed to open\n";
        exit(1);
    }
    fout << "i like this type of data\n";

    fout.close();
}