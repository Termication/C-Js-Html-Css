#include <iostream>
#include <fstream>
int getTheirWants();
void displayItems(int x);
int main(){
    int whatTheyWant;

    whatTheyWant = getTheirWants();

    while(whatTheyWant != 4){
        switch(whatTheyWant){
            case 1: 
               displayItems(1);
               break;
            case 2: 
               displayItems(2);
               break;
            case 3: 
               displayItems(3);
               break;
        }
        whatTheyWant = getTheirWants();
    }std::cout << "thank you for playing\n";

}

int getTheirWants(){

    int choice;

    std::cout << "1 for plain iteams " << std::endl;
    std::cout << "2 for helpful iteams " << std::endl;
    std::cout << "3 for harmful iteams " << std::endl;
    std::cout << "4 Quit " << std::endl;
    


    std::cin >> choice;
    return choice;

}

void displayItems(int x){

    std::ifstream tynnia("kabe.txt");

    std::string name;
    double power;

    if(x==1){
        while(tynnia >> name >> power){
            if(power == 0){
                std::cout << name << ' ' << power << std::endl;
            }
        }
    }

        if(x==2){
        while(tynnia >> name >> power){
            if(power > 0){
                std::cout << name << ' ' << power << std::endl;
            }
        }
    }
        if(x==3){
        while(tynnia >> name >> power){
            if(power < 0){
                std::cout << name << ' ' << power << std::endl;
            }
        }
    }
}
