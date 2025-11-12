#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    reverse(infix);

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
