#include <iostream>

using namespace std;

// Node class representing each element in the doubly linked list
template<typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    // Constructor
    Node(T val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void append(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to insert a node at a specific position
    void insertAtPosition(T val, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        if (position == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        int count = 0;
        while (count < position - 1 && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to display the list
    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the list in reverse order
    void displayReverse() {
        Node<T>* temp = head;
        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Function to reverse the list
    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList<int> dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.insertAtPosition(5, 1); // Insert 5 at position 1
    dll.display(); // Output: 1 5 2 3
    dll.reverse();
    dll.display(); // Output: 3 2 5 1
    dll.displayReverse(); // Output: 1 5 2 3
    return 0;
}
