#include <iostream> 
int main(){

    int rows, cols;
    char symbol;

    std::cout << "how many rows: \n";
    std::cin >> rows;
    std::cout << "how many columns: \n";
    std::cin >> cols;

    std::cout << "enter symbol: \n"; 
    std::cin >> symbol; 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << symbol;
            
        }
        std::cout << '\n';
    }
}