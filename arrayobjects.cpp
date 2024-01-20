#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    char gender;
    float grade;

    // Constructor with initialization list
    Student(string Name, int Age, char Gender, float Grade) 
        : name(Name), age(Age), gender(Gender), grade(Grade) {}

    // Default constructor
    Student() : name(""), age(0), gender(' '), grade(0.0) {}
};

int main() {
    // Student s1; // You can create an object using the default constructor if needed

    // Initializing an array of objects
    Student students[3] = {{"Innocent", 27, 'm', 12}, {"Elon", 25, 'm', 10}, {"Kane", 10, 'm', 9}};

    // Accessing and printing information about each student
    for (int i = 0; i < 3; i++) {
        cout << "STUDENT " << i << " - Name: " << students[i].name << ", Age: " << students[i].age << endl;
    }

    return 0;
}
