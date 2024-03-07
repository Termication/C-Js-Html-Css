#include <iostream>
#include <cstdlib>
#include <ctime>

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

    // Function to shuffle the list
    void shuffle() {
        srand(time(0));
        Node<T>* current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        for (int i = 0; i < length; i++) {
            int j = rand() % (i + 1);
            current = head;
            for (int k = 0; k < i; k++) {
                current = current->next;
            }
            Node<T>* temp = head;
            for (int k = 0; k < j; k++) {
                temp = temp->next;
            }
            swap(current->data, temp->data);
        }
    }

    // Function to find the middle element of the list
    Node<T>* findMiddle() {
        if (head == nullptr) {
            return nullptr;
        }
        Node<T>* slow = head;
        Node<T>* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to check if the list is a palindrome
    bool isPalindrome() {
        Node<T>* middle = findMiddle();
        if (middle == nullptr) {
            return true;
        }
        Node<T>* current = middle;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        Node<T>* tail = prev;
        current = head;
        while (tail != nullptr) {
            if (current->data != tail->data) {
                return false;
            }
            current = current->next;
            tail = tail->next;
        }
        return true;
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
    dll.append(4);
    dll.append(5);
    
    cout << "Original List: ";
    dll.display();

    dll.shuffle();
    cout << "Shuffled List: ";
    dll.display();

    Node<int>* middle = dll.findMiddle();
    cout << "Middle Element: " << middle->data << endl;

    cout << "Is Palindrome: " << (dll.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}
