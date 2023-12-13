#include <iostream>


class house{
 public:
    int Volume = 0, Length = 0;

 
    void setData(int v, int l){
        Volume = v;
        Length = l;
    }

    void Area(){
        std::cout << "Area Is Equal To " << Volume * Length << std::endl;


    }

};
int main(){

    house h1;

    h1.setData(52, 10);
    h1.Area();
}