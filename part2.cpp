#include <iostream>

class Square{

public: 
  
    int length = 0;
    int breadth = 0;
    
    void showData(){
        std::cout << "Square length " << length << std::endl;
        std::cout << "Square breadth " << breadth << std::endl;
    }
};
class Rectange : public Square{
public:

};

int main(){
    Square square;
    square.length = 5;
    square.breadth = 5;
    square.showData();
    Rectange rectangle;
    rectangle.length = 12;
    rectangle.breadth = 7;
    rectangle.showData();
}