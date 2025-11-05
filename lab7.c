#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("%d pushed to stack.\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice;
    printf("=== STACK USING ARRAY ===\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}