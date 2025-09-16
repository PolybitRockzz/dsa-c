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

int isEmpty(Node *front) { return front == NULL; }

void traverse(Node *front) {
    if (!front) { printf("Queue: \n"); return; }
    printf("Queue: ");
    Node *p = front; while (p) { printf("%d  ", p->data); p = p->next; }
    printf("\n");
}

int main(void) {
    Node *front = NULL, *rear = NULL;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        int opt; if (scanf("%d", &opt) != 1) break;
        switch (opt) {
            case 1: {
                int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
                Node *n = create_node(x);
                if (!n) { fprintf(stderr, "Memory error\n"); return 1; }
                if (!front) front = rear = n; else { rear->next = n; rear = n; }
                break;
            }
            case 2: {
                if (!front) { printf("Queue is empty\n"); break; }
                Node *t = front; front = front->next;
                free(t);
                if (!front) rear = NULL;
                printf("Element deleted\n");
                break;
            }
            case 3: {
                printf("Queue empty: %s\n", isEmpty(front) ? "True" : "False");
                break;
            }
            case 4: {
                traverse(front); break;
            }
            case 5:
                // free list
                while (front) { Node *t = front; front = front->next; free(t); }
                return 0;
            default: printf("Invalid option\n");
        }
    }
    // cleanup
    while (front) { Node *t = front; front = front->next; free(t); }
    return 0;
}
