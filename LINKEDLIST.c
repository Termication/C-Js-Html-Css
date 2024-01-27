#include <stdio.h>
#include <stdio.h>



struct Node {
    int data;
    struct Node* next;
};
struct Node* head // global var, pointer to node, can be accessed anywhere

void Insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    
}

int main (){
    head = NULL; // empty list;

    printf("How many numbers?\n");

    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("Enter a number: \n");
        scanf("%d", &x);
        Insert(x);
        Print()
    }
} 