#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top >= MAX - 1) return;
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    char *e;
    char x;
    
    printf("Postfix: ");
    
    for (e = exp; *e != '\0'; e++) {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
    }
    
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix: %s\n", expression);
    infixToPostfix(expression);
    return 0;
}