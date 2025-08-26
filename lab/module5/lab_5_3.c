#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int val;
    struct Node *next;
} Node;

Node* create_node(int r, int c, int v) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->row = r; p->col = c; p->val = v; p->next = NULL;
    return p;
}

int main(void) {
    int r, c;
    printf("Enter size of the sparse matrix: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    printf("Enter elements of sparse matrix: ");
    int total = r * c;

    // head node will store (row=r, col=c, val=nonzero_count)
    Node *head = create_node(r, c, 0);
    if (!head) { fprintf(stderr, "Memory error\n"); return 1; }
    Node *tail = head;

    for (int i = 0; i < total; ++i) {
        int x;
        if (scanf("%d", &x) != 1) { fprintf(stderr, "Invalid input\n");
            // free list
            Node *t = head; while (t) { Node *nx = t->next; free(t); t = nx; }
            return 1;
        }
        if (x != 0) {
            int rr = i / c;
            int cc = i % c;
            Node *n = create_node(rr, cc, x);
            if (!n) { fprintf(stderr, "Memory error\n"); return 1; }
            tail->next = n;
            tail = n;
            head->val += 1; // increment nonzero count
        }
    }

    // print in 3-tuple format
    printf("sparse matrix in 3-tuple format\n");
    printf("%d   %d   %d\n", head->row, head->col, head->val);
    for (Node *p = head->next; p != NULL; p = p->next) {
        printf("%d   %d   %d\n", p->row, p->col, p->val);
    }

    // free list
    Node *t = head;
    while (t) { Node *nx = t->next; free(t); t = nx; }
    return 0;
}
