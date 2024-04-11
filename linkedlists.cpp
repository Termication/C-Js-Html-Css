#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class with operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to delete a node at a specific position
    void deleteAt(int position) {
        if (!head) {
            std::cerr << "List is empty. Deletion failed.\n";
            return;
        }
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        int currentPosition = 0;
        while (current && currentPosition != position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }
        if (!current) {
            std::cerr << "Invalid position. Deletion failed.\n";
            return;
        }
        previous->next = current->next;
        delete current;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to delete all nodes
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList linkedList;

    // Inserting elements into the linked list
    linkedList.insertEnd(1);
    linkedList.insertEnd(2);
    linkedList.insertEnd(3);
    linkedList.insertEnd(4);
    linkedList.insertEnd(5);

    // Displaying elements of the linked list
    std::cout << "Linked List elements: ";
    linkedList.display();

    // Deleting element at a specific position
    int positionToDelete = 2;
    linkedList.deleteAt(positionToDelete);
    std::cout << "After deleting node at position " << positionToDelete << ": ";
    linkedList.display();

    return 0;
}
