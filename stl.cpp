#include <iostream>
#include <vector> // Include the vector header file

using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Print the elements of the vector
    cout << "Vector elements: ";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    // Accessing elements using iterators
    cout << "Vector elements using iterators: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using range-based for loop
    cout << "Vector elements using range-based for loop: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    // Size of the vector
    cout << "Size of the vector: " << myVector.size() << endl;

    // Check if the vector is empty
    cout << "Is the vector empty? " << (myVector.empty() ? "Yes" : "No") << endl;

    // Clear the vector
    myVector.clear();

    // Check if the vector is empty after clearing
    cout << "Is the vector empty after clearing? " << (myVector.empty() ? "Yes" : "No") << endl;

    return 0;
}
