#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
void reverseLinkedList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store next node
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    // Update the head to point to the last node (which is now the first node)
    *head_ref = prev;
}

// Function to insert a new node at the beginning
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set data of new node
    new_node->data = new_data;
    // Make next of new node as head
    new_node->next = (*head_ref);
    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test functions
int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Insert some nodes
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Linked list before reversal: \n");
    printList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    printf("Linked list after reversal: \n");
    printList(head);

    return 0;
}
