#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->data = val;
    p->next = NULL;
    return p;
}

int main(void) {
    int n;
    printf("Enter no.of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; ++i) {
        int val;
        printf("Enter info of node%d: ", i);
        if (scanf("%d", &val) != 1) {
            // free any allocated nodes
            Node *t = head;
            if (t) {
                do {
                    Node *nx = t->next;
                    free(t);
                    t = nx;
                } while (t != head);
            }
            return 1;
        }
        Node *p = create_node(val);
        if (!p) { fprintf(stderr, "Memory error\n"); return 1; }
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }

    if (tail) tail->next = head; // make circular

    // display
    if (!head) {
        printf("Linkedlist: \n");
    } else {
        printf("Linkedlist: ");
        Node *p = head;
        do {
            printf("%d  ", p->data); // two spaces as in sample
            p = p->next;
        } while (p != head);
        printf("\n");
    }

    // free nodes
    if (head) {
        Node *cur = head->next;
        head->next = NULL; // break the circle to ease freeing
        while (cur) {
            Node *nx = cur->next;
            free(cur);
            cur = nx;
        }
        free(head);
    }
    return 0;
}
