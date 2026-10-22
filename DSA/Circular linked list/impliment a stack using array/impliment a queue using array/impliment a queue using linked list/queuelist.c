#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct QueueLinkedList {
    struct Node* front;
    struct Node* rear;
};

void initQueueLinkedList(struct QueueLinkedList* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmptyLinkedList(struct QueueLinkedList* queue) {
    return queue->front == NULL;
}

void enqueueLinkedList(struct QueueLinkedList* queue) {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

int dequeueLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Dequeued element: %d\n", dequeuedValue);
    return dequeuedValue;
}

int peekLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    printf("Front element is: %d\n", queue->front->data);
    return queue->front->data;
}

void displayQueueLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct QueueLinkedList q;
    initQueueLinkedList(&q);
    int choice;
    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueueLinkedList(&q); break;
            case 2: dequeueLinkedList(&q); break;
            case 3: peekLinkedList(&q); break;
            case 4: displayQueueLinkedList(&q); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
