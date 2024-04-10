#include <iostream>
#include <list>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    // Creating a linked list using std::list container
    std::list<Node> linkedList;

    // Inserting elements into the linked list
    linkedList.push_back(Node(1));
    linkedList.push_back(Node(2));
    linkedList.push_back(Node(3));
    linkedList.push_back(Node(4));

    // Displaying elements of the linked list
    std::cout << "Linked List elements:" << std::endl;
    for (const auto& node : linkedList) {
        std::cout << node.data << " ";
    }
    std::cout << std::endl;

    return 0;
}
