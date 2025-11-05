#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to add an element (enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to remove an element (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = front;
    if (front == rear) { // only one element
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("%d dequeued from queue\n", temp->data);
    free(temp);
}

// Function to view the front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

// Function to display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter choice: ");
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}