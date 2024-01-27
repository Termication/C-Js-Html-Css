#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // global var, pointer to node, can be accessed anywhere

void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head; // Update the next pointer to point to the current head
    head = temp;       // Update the head to the newly created node
}

void Print() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL; // empty list;

    printf("How many numbers?\n");

    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter a number: \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
