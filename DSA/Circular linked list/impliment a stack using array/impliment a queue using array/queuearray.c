#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct QueueArray {
    int arr[MAX];
    int front;
    int rear;
};

void initQueueArray(struct QueueArray* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFullArray(struct QueueArray* queue) {
    return queue->rear == MAX - 1;
}

int isEmptyArray(struct QueueArray* queue) {
    return queue->front == -1;
}

void enqueueArray(struct QueueArray* queue) {
    int value;
    if (isFullArray(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeueArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int dequeuedValue = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("Dequeued element: %d\n", dequeuedValue);
    return dequeuedValue;
}

int peekArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    printf("Front element is: %d\n", queue->arr[queue->front]);
    return queue->arr[queue->front];
}

void displayQueueArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct QueueArray q;
    initQueueArray(&q);
    int choice;
    while (1) {
        printf("\n--- QUEUE USING ARRAY ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueueArray(&q); break;
            case 2: dequeueArray(&q); break;
            case 3: peekArray(&q); break;
            case 4: displayQueueArray(&q); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
