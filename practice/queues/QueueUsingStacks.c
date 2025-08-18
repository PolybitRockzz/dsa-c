#include <stdio.h>

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

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

Stack reverse(Stack *s1) {
    Stack s2;
    initStack(&s2);
    for (int i = s1->top; i >= 0; i--) {
        push(&s2, s1->items[i]);
    }
    return s2;
}

int main() {
    Stack stack1, stack2;

    initStack(&stack1);
    initStack(&stack2);

    while (1) {
        printf("QUEUE USING TWO STACKS\n");
        printf("1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int item;
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                push(&stack1, item);
                while (!isEmpty(&stack2)) {
                    pop(&stack2);
                }
                free(&stack2);
                stack2 = reverse(&stack1);
                break;
            }
            case 2: {
                int item = pop(&stack2);
                if (item != -1) {
                    printf("%d dequeued from queue.\n", item);
                }
                while (!isEmpty(&stack1)) {
                    pop(&stack1);
                }
                free(&stack1);
                stack1 = reverse(&stack2);
                break;
            }
            case 3: {
                int item = peek(&stack2);
                if (item != -1) {
                    printf("Front element is: %d\n", item);
                }
                break;
            }
        }
    }

    return 0;
}