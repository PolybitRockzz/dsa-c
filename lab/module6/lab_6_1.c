#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = item;
    printf("%d pushed into stack.\n", item);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

void traverse(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack: \n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; --i) {
        printf("%d  ", s->items[i]);
    }
    printf("\n");
}

int main(void) {
    Stack st;
    initStack(&st);

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        int option;
        if (scanf("%d", &option) != 1) break;

        switch (option) {
            case 1: {
                int x;
                printf("Enter element to be pushed into the stack: ");
                if (scanf("%d", &x) != 1) break;
                push(&st, x);
                break;
            }
            case 2: {
                int val = pop(&st);
                if (val != -1) printf("%d deleted from Stack\n", val);
                break;
            }
            case 3: {
                printf("Stack empty: %s\n", isEmpty(&st) ? "True" : "False");
                break;
            }
            case 4: {
                printf("Stack full: %s\n", isFull(&st) ? "True" : "False");
                break;
            }
            case 5: {
                traverse(&st);
                break;
            }
            case 6:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
