#include <iostream>

class person {
  private:

   std::string name;
   int age;
  public:
    void setName(std::string n){
        name = n;
    }


    void setAge(int a){
        age = a;
    }

    void printInfo(){
        std::cout << "name: " << name << std::endl;
        std::cout << "age: " << age << std::endl;
    }
};
int main(){
    person KayBee;
    KayBee.setName("Kaybee");
    KayBee.setAge(25);
    person lala;
    lala.setName("lala");
    lala.setAge(13);
    KayBee.printInfo();
    lala.printInfo();

    return 0;

}
