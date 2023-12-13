#include <iostream>
#include <string>

class Employee{
    public:
      virtual void monthlySalary(){
        std::cout << "Monthly  salary that individual receive " << std::endl;
      }

};

class Professor : public Employee{
    public:
      virtual void monthlySalary() {
        std::cout << "Receive R100K " << std::endl;
      }
};

class Doctor : public Employee{
    public:
       virtual void monthlySalary() {
        std::cout << "Receive R70K " << std::endl;
      }
};

class Forextrader : public Employee{
    public:
       virtual void monthlySalary() {
        std::cout << "I make more than R500K " << std::endl;
      }

};

void Salary(Employee* S){
    S->monthlySalary();
}
int main(){

    Employee* worker;
    


    Professor Prof;
    Doctor Dr;
    Forextrader Fx;

    std::cout << std::endl;


    worker = &Prof;
    worker->monthlySalary();

    worker = &Fx;
    worker->monthlySalary();

    worker = &Dr;
    worker->monthlySalary();

    std::cout << std::endl;

    Salary(&Fx);
    std::cout << std::endl;
    std::cout <<"size of Employee " << sizeof(Employee) << std::endl;
    std::cout <<"size of Professor " << sizeof(Professor) << std::endl;






}