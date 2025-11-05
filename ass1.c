#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int eventId;
    struct Node* prev;
    struct Node* next;
} Node;

// empty list & no matching nodes handle

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->eventId = val;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void remNode(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* ptr = head;
    int found = 0;

    while (ptr != NULL) {

        if (ptr->eventId == val) {
            found = 1;
            Node* temp = ptr;
            Node* nextNode = ptr->next;

            if (ptr == head) {
                head = ptr->next;
                if (head != NULL) { // if new head is a node and not null
                    head->prev = NULL;
                }
            }
            else {
                ptr->prev->next = ptr->next;
                if (ptr->next != NULL) { // if ptrs next is a node and not null
                    ptr->next->prev = ptr->prev;
                }
            }
            free(ptr);
            ptr = nextNode;
        }
        else {
            ptr = ptr->next;
        }
    }
    if (found == 1) {
        printf("All occurences of node with value %d are deleted.\n", val);
    }
    else {
        printf("%d not found in the list.\n", val);
    }
}

void insertNode(int val, int pos) {
    Node* newNode = createNode(val);

    // Case 1: Empty list
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at position 1 (list was empty).\n", val);
        return;
    }

    // Case 2: Insert at head
    if (pos <= 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("Inserted %d at position 1.\n", val);
        return;
    }

    // Case 3: Insert at middle or end
    Node* ptr = head;
    int current = 1;

    while (ptr->next != NULL && current < pos - 1) {
        ptr = ptr->next;
        current++;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;

    printf("Inserted %d at position %d.\n", val, pos);
}

void display() {
    Node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->eventId);
        ptr = ptr->next;
    }
}

int main () {
    int choice;
    while (1){
        printf("\n1. Insert an element at a given position\n2. Delete all occurences of an element\n3. Display elements\n4. Exit\nEnter: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int val, pos;
                printf("Enter the insertion element and position of insertion: ");
                scanf("%d %d", &val, &pos);
                insertNode(val,pos);
                break;
            }
            case 2: {
                int val;
                printf("Enter element to remove all its occurences: ");
                scanf("%d", &val);
                remNode(val);
                break;
            }
            case 3:
                display();
                break;
            case 4: {
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
            }
        }
    }
}