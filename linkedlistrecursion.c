#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void Print(struct Node* p){

    if (p == NULL) return; // exit condtion
    Print(p->next);
    printf("%d ", p->data); // first print the value in the node
    
}

struct Node* Insert(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) 
    {
        head = temp;
    } 
    else 
    {
        struct Node* temp1 = head;
        while (temp1->next != NULL) 
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

int main(){
    struct Node* head = NULL; // local variable
    head = Insert(head, 2);
    head = Insert(head, 8);
    head = Insert(head, 5);
    head = Insert(head, 9);
    head = Insert(head, 3);
    head = Insert(head, 1);
    Print(head);

}


