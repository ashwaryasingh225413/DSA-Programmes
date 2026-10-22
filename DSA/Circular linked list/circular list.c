#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Points to itself to make it circular
    } else {
        struct Node* temp = *head;
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;     // Link the last node to the new node
        newNode->next = *head;    // Point the new node back to the head
    }
}

// Function to delete a node with a specific value
void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // Case 1: If the node to be deleted is the head node
    if (temp->data == value) {
        // If there is only one node in the list
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            return;
        }
        
        // If there are multiple nodes, find the last node to update its link
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        
        *head = temp->next;       // Move head to the next node
        last->next = *head;       // Link the last node to the new head
        free(temp);
        return;
    }

    // Case 2: If the node to be deleted is in the middle or at the end
    while (temp->next != *head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value is found
    if (temp->data == value) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

// Function to traverse and print the circular linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(head)\n"); // Indicates that the list loops back to the head
}

// Function to create a circular linked list from an array of values
void createList(struct Node** head, int values[], int size) {
    for (int i = 0; i < size; i++) {
        insert(head, values[i]);
    }
}

// Main function to test the operations
int main() {
    struct Node* head = NULL;

    // Create the circular linked list with initial values
    int values[] = {10, 20, 30, 40};
    createList(&head, values, 4);

    printf("Circular Linked list after creation:\n");
    traverse(head);

    // Insert a new node with value 50
    insert(&head, 50);
    printf("\nCircular Linked list after inserting 50:\n");
    traverse(head);

    // Delete a node with value 20
    delete(&head, 20);
    printf("\nCircular Linked list after deleting 20:\n");
    traverse(head);

    // Try to delete a non-existent node
    printf("\nTry to delete a non-existent node (100):\n");
    delete(&head, 100);

    // Final list traversal
    printf("\nFinal Circular Linked List:\n");
    traverse(head);

    return 0;
}
