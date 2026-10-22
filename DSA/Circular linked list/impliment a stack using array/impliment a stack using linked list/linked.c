#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct StackLinkedList {
    struct Node* top;
};

// Function to initialize the stack
void initStackLinkedList(struct StackLinkedList* stack) {
    stack->top = NULL; // Initialize top as NULL (empty stack)
}

// Check if the stack is empty
int isEmptyLinkedList(struct StackLinkedList* stack) {
    return stack->top == NULL;
}

// Push element onto the stack
void pushLinkedList(struct StackLinkedList* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    
    printf("Pushed %d to stack\n", value);
}

// Pop element from the stack
int popLinkedList(struct StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        struct Node* temp = stack->top;
        int poppedValue = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return poppedValue;
    }
}

// Peek the top element of the stack
int peekLinkedList(struct StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->top->data;
    }
}

// Display the elements in the stack
void displayStackLinkedList(struct StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        struct Node* temp = stack->top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}




