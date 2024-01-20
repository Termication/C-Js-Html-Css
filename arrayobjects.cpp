#include <iostream>

using namespace std;

class Student{
  public:
    string name;
    int age;
    char gender;
    float grade;

    Student(string Name, int Age, char Gender, float Grade){
        Name = name;
        Age = age;
        Gender = gender;
        Grade = grade;
    }
};

int main(){

    /*
    -what is arrays of objects
    -how are they different from arraysof primitive data types
    -why and when should you use objects in the arrays
    -how do you access individual objects int the array
    -how do you access and modify object properties in the array
    -how to use loops to perform operations on arrays of objects
    -most common errors that can happen 
    */
   int luckynumbers[5] = {1,4,5,2,10};

   //Student s1;

   /*s1.name = "Innocent";
   s1.age = 25;
   s1.gender = 'm';
   s1.grade = 12;*/

   Student students[3] = {{"innocent", 27, 'm', 12},{"Elon", 25, 'm', 10}, {"Kane", 10, 'm', 9}};

}