#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node* create_node(int coeff, int pow) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->coeff = coeff;
    p->pow = pow;
    p->next = NULL;
    return p;
}

void append_node(Node **head_ref, Node **tail_ref, int coeff, int pow) {
    Node *n = create_node(coeff, pow);
    if (!n) return;
    if (!*head_ref) { *head_ref = *tail_ref = n; }
    else { (*tail_ref)->next = n; *tail_ref = n; }
}

Node* add_polynomials(Node *p1, Node *p2) {
    Node *res_head = NULL, *res_tail = NULL;
    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            int s = p1->coeff + p2->coeff;
            if (s != 0) append_node(&res_head, &res_tail, s, p1->pow);
            p1 = p1->next; p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            append_node(&res_head, &res_tail, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            append_node(&res_head, &res_tail, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1) { append_node(&res_head, &res_tail, p1->coeff, p1->pow); p1 = p1->next; }
    while (p2) { append_node(&res_head, &res_tail, p2->coeff, p2->pow); p2 = p2->next; }
    return res_head;
}

void print_polynomial(Node *head) {
    if (!head) { printf("0\n"); return; }
    int first = 1;
    while (head) {
        int c = head->coeff;
        int p = head->pow;
        if (!first) {
            if (c >= 0) printf("+");
        }
        printf("%d", c);
        printf("x^%d", p);
        first = 0;
        head = head->next;
    }
    printf(".\n");
}

void free_list(Node *head) {
    while (head) { Node *t = head; head = head->next; free(t); }
}

int main(void) {
    Node *p1 = NULL, *t1 = NULL;
    Node *p2 = NULL, *t2 = NULL;

    printf("Polynomial-1:\n");
    int max1;
    printf("Enter the Maximum power of x: ");
    if (scanf("%d", &max1) != 1 || max1 < 0) return 1;
    for (int i = max1; i >= 0; --i) {
        int coeff;
        printf("Enter the coefficient of degree %d: ", i);
        if (scanf("%d", &coeff) != 1) { free_list(p1); return 1; }
        if (coeff != 0) append_node(&p1, &t1, coeff, i);
    }

    printf("Polynomial-2:\n");
    int max2;
    printf("Enter the Maximum power of x: ");
    if (scanf("%d", &max2) != 1 || max2 < 0) { free_list(p1); return 1; }
    for (int i = max2; i >= 0; --i) {
        int coeff;
        printf("Enter the coefficient of degree %d: ", i);
        if (scanf("%d", &coeff) != 1) { free_list(p1); free_list(p2); return 1; }
        if (coeff != 0) append_node(&p2, &t2, coeff, i);
    }

    Node *res = add_polynomials(p1, p2);
    printf("\nSum: ");
    print_polynomial(res);

    free_list(p1); free_list(p2); free_list(res);
    return 0;
}
