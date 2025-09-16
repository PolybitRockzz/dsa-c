#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->data = val; p->next = NULL; return p;
}

Node* push(Node *top, int val) {
    Node *n = create_node(val);
    if (!n) return top;
    n->next = top;
    return n;
}

Node* pop(Node *top, int *popped, int *success) {
    *success = 0;
    if (!top) return top;
    *popped = top->data;
    Node *next = top->next;
    free(top);
    *success = 1;
    return next;
}

int isEmpty(Node *top) {
    return top == NULL;
}

void traverse(Node *top) {
    if (!top) { printf("Stack: \n"); return; }
    printf("Stack: ");
    Node *p = top;
    while (p) { printf("%d  ", p->data); p = p->next; }
    printf("\n");
}

int main(void) {
    Node *top = NULL;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n2. Pop\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        int opt; if (scanf("%d", &opt) != 1) break;
        switch (opt) {
            case 1: {
                int x; printf("Enter element to be pushed into the stack: "); if (scanf("%d", &x) != 1) break;
                top = push(top, x);
                break;
            }
            case 2: {
                int val, success = 0;
                top = pop(top, &val, &success);
                if (success) printf("%d deleted from Stack\n", val);
                else printf("Stack is empty\n");
                break;
            }
            case 3: {
                printf("Stack empty: %s\n", isEmpty(top) ? "True" : "False");
                break;
            }
            case 4: {
                traverse(top); break;
            }
            case 5:
                goto end;
            default: printf("Invalid option\n");
        }
    }
end:
    while (top) { Node *t = top; top = top->next; free(t); }
    // mark todo 1 completed
    (void)0;
    return 0;
}
