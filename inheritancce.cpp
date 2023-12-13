#include <iostream>

class Square{
protected:
    int length;
    int breadth;
public: 
    Square(int l, int b){
        length = l;
        breadth = b;
    }
    void showData(){
        std::cout << "Square  length " << length << std::endl;
        std::cout << "Square  breadth " << breadth << std::endl;
    }
};
class Rectangle : public Square{
    public:
      Rectangle(int l, int b){
        length = l;
        breadth = b;

      }


};

int main(){
    Square square(5, 5);
    square.showData();
    Rectangle rectangle(12, 7);
    rectangle.showData();
}