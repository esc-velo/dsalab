// Circular Linked list : Traverse, Insert and Delete

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    Node* toDelete = NULL;

    do {
        if (temp->data == value) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (toDelete == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (toDelete->next == toDelete) { 
        head = NULL;  // only one node
    } else {
        Node* prevNode = toDelete->prev;
        Node* nextNode = toDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if (toDelete == head)
            head = nextNode;
    }
    free(toDelete);
    printf("Node deleted.\n");
}

// Traverse
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Traverse\n2. Insert at Beginning\n3. Insert at End\n4. Delete a Node\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
