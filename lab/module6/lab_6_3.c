#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) return;
    s->items[++s->top] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[s->top--];
}

char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return op == '^';
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        // Skip spaces
        if (isspace(c)) continue;
        
        // If operand, add to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        }
        // If operator
        else if (isOperator(c)) {
            while (!isEmpty(&s) && peek(&s) != '(' &&
                   (precedence(peek(&s)) > precedence(c) ||
                    (precedence(peek(&s)) == precedence(c) && !isRightAssociative(c)))) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    
    // Pop remaining operators
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
}

int main(void) {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    
    // Remove newline if present
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix: %s\n", postfix);
    
    return 0;
}
