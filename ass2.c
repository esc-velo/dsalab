#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));;
    newNode->data = val;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertNode(int val, int pos) {
    Node* newNode = createNode(val);

    // Case 1: Empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Case 2: Insert at head
    if (pos <= 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
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
}

int findMid() {
    if (head == NULL) {
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    int n, val;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &val);
        insertNode(val, i+1);
    }
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    int mid = findMid();

    if (mid != -1) {
        printf("\n%d is middle element", mid);
        return 0;
    }

    return 1;
}