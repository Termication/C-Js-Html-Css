#include <iostream>

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class to manage the linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Creating a linked list and inserting elements
    LinkedList myList;
    myList.insertAtBeginning(4);
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    // Displaying the linked list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
