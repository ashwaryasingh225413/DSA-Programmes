#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// Stack implementation using Array
struct StackArray {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStackArray(struct StackArray* stack) {
    stack->top = -1; // Initialize top of stack
}

// Check if the stack is full
int isFullArray(struct StackArray* stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmptyArray(struct StackArray* stack) {
    return stack->top == -1;
}

// Push element onto the stack
void pushArray(struct StackArray* stack, int value) {
    if (isFullArray(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++stack->top] = value; // Increment top and push element
        printf("Pushed %d to stack\n", value); // Comment se alag kiya
    }
}

// Pop element from the stack
int popArray(struct StackArray* stack) {
    if (isEmptyArray(stack)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack->arr[stack->top--]; // Pop element and decrement top
    }
}

// Peek the top element of the stack
int peekArray(struct StackArray* stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Display the elements in the stack
void displayStackArray(struct StackArray* stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}
