#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Size of circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  // First insertion
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d enqueued into queue.\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No element to dequeue.\n");
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}