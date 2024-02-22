#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node {
    char data[100];
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* CreateNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->data, data); // Copy data into the node
    newNode->next = NULL; // Set the next pointer to NULL
    return newNode;
}

// Function to insert a new node with data in sorted order
void InsertSorted(struct Node** headRef, char* data) {
    struct Node* newNode = CreateNode(data);
    if (*headRef == NULL || strcmp(data, (*headRef)->data) < 0) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next != NULL && strcmp(data, current->next->data) > 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the elements of the linked list
void PrintList(struct Node* head) {
    printf("Linked list elements: ");
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void FreeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head; // Store the current node
        head = head->next; // Move to the next node
        free(temp); // Free the memory of the current node
    }
}

int main() {
    struct Node* head = NULL; // Initialize the head pointer to NULL
    char data[100];

    // Insert elements into the linked list
    printf("Enter elements to insert (enter 'stop' to stop):\n");
    while (1) {
        printf("Enter element: ");
        scanf("%s", data);
        if (strcmp(data, "stop") == 0) {
            break;
        }
        InsertSorted(&head, data); // Pass the address of the head pointer to InsertSorted function
    }

    // Print the elements of the linked list
    PrintList(head);

    // Free memory allocated for the linked list
    FreeList(head);

    return 0;
}
