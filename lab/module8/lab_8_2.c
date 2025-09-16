#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

Node* create_node(int data, int priority) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->data = data; p->priority = priority; p->next = NULL; return p;
}

// insert in sorted order by priority (ascending — lower number = higher priority)
Node* enqueue(Node *head, int data, int priority) {
    Node *n = create_node(data, priority);
    if (!n) return head;
    if (!head || priority < head->priority) {
        n->next = head; return n;
    }
    Node *cur = head;
    while (cur->next && cur->next->priority <= priority) cur = cur->next;
    n->next = cur->next; cur->next = n; return head;
}

Node* dequeue(Node *head, int *data, int *priority, int *success) {
    *success = 0;
    if (!head) return head;
    Node *t = head; *data = t->data; *priority = t->priority; head = head->next; free(t); *success = 1; return head;
}

void display(Node *head) {
    if (!head) { printf("Priority Queue: (empty)\n"); return; }
    printf("Priority Queue:\n");
    printf("Priority   Item\n");
    Node *p = head;
    while (p) {
        printf("%d              %d\n", p->priority, p->data);
        p = p->next;
    }
}

int main(void) {
    Node *head = NULL;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter option: ");
        int opt; if (scanf("%d", &opt) != 1) break;
        if (opt == 1) {
            int item, pr; printf("Enter element: "); if (scanf("%d", &item) != 1) break;
            printf("Enter priority: "); if (scanf("%d", &pr) != 1) break;
            head = enqueue(head, item, pr);
        } else if (opt == 2) {
            int data, pr, success=0; head = dequeue(head, &data, &pr, &success);
            if (success) printf("%d dequeued (priority %d)\n", data, pr);
            else printf("Queue is empty\n");
        } else if (opt == 3) {
            display(head);
        } else if (opt == 4) {
            break;
        } else printf("Invalid option\n");
    }
    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
