#include <stdio.h>
#include <stdlib.h>

// Singly Linked List : insertion, deletion and traversing

typedef struct Node{
    int data;
    struct Node* ptr;
} Node;

int main() {
    
    Node* head = NULL;   // start with empty list
    Node* temp;
    Node* newNode;
    int choice, val, key, n, i;

    printf("Enter number of elements in linked list: ");
    scanf("%d", &n);

    // Create list initially
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->ptr = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->ptr != NULL)
                temp = temp->ptr;
            temp->ptr = newNode;
        }
    }

    // Menu-driven operations
    do {
        printf("\n--- MENU ---\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete a Node\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Traverse
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    temp = head;
                    i = 1;
                    while (temp != NULL) {
                        printf("Element %d: %d\n", i++, temp->data);
                        temp = temp->ptr;
                    }
                }
                break;

            case 2:  // Insert at beginning
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                newNode = (Node*)malloc(sizeof(Node));
                newNode->data = val;
                newNode->ptr = head;
                head = newNode;
                break;

            case 3:  // Insert at end
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                newNode = (Node*)malloc(sizeof(Node));
                newNode->data = val;
                newNode->ptr = NULL;
                if (head == NULL) {
                    head = newNode;
                } else {
                    temp = head;
                    while (temp->ptr != NULL)
                        temp = temp->ptr;
                    temp->ptr = newNode;
                }
                break;

            case 4:  // Delete a node
                printf("Enter value to delete: ");
                scanf("%d", &key);
                temp = head;
                Node* prev = NULL;

                // If head itself needs to be deleted
                if (temp != NULL && temp->data == key) {
                    head = temp->ptr;
                    free(temp);
                    break;
                }

                // Search for node to delete
                while (temp != NULL && temp->data != key) {
                    prev = temp;
                    temp = temp->ptr;
                }

                if (temp == NULL) {
                    printf("Element %d not found!\n", key);
                } else {
                    prev->ptr = temp->ptr;
                    free(temp);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}