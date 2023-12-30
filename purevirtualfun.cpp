#include <iostream>


class instrument{

    public:
        void virtual MakeSound(){
            std::cout << "Instrument is playing\n";
        }
};
class Accordion:public instrument{
    public:
        void MakeSound(){
            std::cout << "Playing Accordion\n";
        }
};

int main(void){

    instrument* make = new Accordion();

    make->MakeSound();

     system("pause>0");
}