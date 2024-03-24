#include <stdio.h>
#include <stdlib.h>

// Define a stack structure
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

// Function to reverse the stack
void reverseStack(Stack *stack) {
    if (isEmpty(stack)) {
        return; // Nothing to reverse
    }

    // Create a temporary stack
    Stack tempStack;
    initialize(&tempStack);

    // Push all elements of original stack to temporary stack
    while (!isEmpty(stack)) {
        push(&tempStack, pop(stack));
    }

    // Push all elements of temporary stack back to original stack
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    // Print original stack
    printf("Original stack:\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    // Reverse the stack
    reverseStack(&stack);

    // Print reversed stack
    printf("Reversed stack:\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}
