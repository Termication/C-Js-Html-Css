#include <iostream>

using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete a node with given value from the list
    void deleteNode(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                if (current == head) {
                    head = head->next;
                }
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.display(); // Output: 1 2 3
    dll.deleteNode(2);
    dll.display(); // Output: 1 3
    return 0;
}
