#include <iostream>
#include <string>

class Enemy {
public:  
    virtual void makeAttack() {
          std::cout << "Attack the noob " << std::end;
       }

};

class Normalenemy : public Enemy {
public:
    void makeAttack() override {
        std::cout << "fire fire fire M16 " << std::end;
        
       }
};

class Upperenemy : public Enemy {
public:
    void makeAttack() override {
        std::cout << "Strike strike  strike with the sword " << std::end;
        
       }
};
class Monsterenemy : public Enemy {
public:
    void makeAttack() override {
        std::cout << "Eat aet aet thew noobs " << std::end;
        
       }
};

int main(){
    Enemy* enemies;

    Normalenemy normal;
    Upperenemy upper;
    Monsterenemy monster;

    enemies = &normal;
    enemies->makeAttack;

}
