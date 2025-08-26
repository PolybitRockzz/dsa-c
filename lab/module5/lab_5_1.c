#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* create_node(int val) {
    DNode *p = (DNode*)malloc(sizeof(DNode));
    if (!p) return NULL;
    p->data = val;
    p->prev = p->next = NULL;
    return p;
}

DNode* insert_at_position(DNode *head, int val, int pos) {
    if (pos < 1) return head;
    DNode *newn = create_node(val);
    if (!newn) return head;
    if (pos == 1) {
        newn->next = head;
        if (head) head->prev = newn;
        return newn;
    }
    DNode *cur = head;
    int i = 1;
    while (cur && i < pos - 1) { cur = cur->next; ++i; }
    if (!cur) { free(newn); return head; }
    newn->next = cur->next;
    newn->prev = cur;
    if (cur->next) cur->next->prev = newn;
    cur->next = newn;
    return head;
}

DNode* delete_at_position(DNode *head, int pos, int *success) {
    *success = 0;
    if (!head || pos < 1) return head;
    if (pos == 1) {
        DNode *tmp = head->next;
        if (tmp) tmp->prev = NULL;
        free(head);
        *success = 1;
        return tmp;
    }
    DNode *cur = head;
    int i = 1;
    while (cur && i < pos) { cur = cur->next; ++i; }
    if (!cur) return head;
    if (cur->prev) cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    free(cur);
    *success = 1;
    return head;
}

void traverse(DNode *head) {
    if (!head) { printf("The list is empty\n"); return; }
    printf("The list is: ");
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("-> ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    DNode *head = NULL, *tail = NULL;
    if (n > 0) {
        printf("Enter the elements: ");
        for (int i = 0; i < n; ++i) {
            int x; if (scanf("%d", &x) != 1) return 1;
            DNode *p = create_node(x);
            if (!p) { fprintf(stderr, "Memory error\n"); return 1; }
            if (!head) head = tail = p;
            else { tail->next = p; p->prev = tail; tail = p; }
        }
    }

    while (1) {
        int choice;
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: {
                int elem, pos; printf("Enter element: "); if (scanf("%d", &elem) != 1) break;
                printf("Enter position: "); if (scanf("%d", &pos) != 1) break;
                int before = 0, after = 0;
                DNode *tmp = head;
                while (tmp) { ++before; tmp = tmp->next; }
                head = insert_at_position(head, elem, pos);
                tmp = head; while (tmp) { ++after; tmp = tmp->next; }
                if (after > before) printf("Node inserted\n"); else printf("Insertion failed\n");
                break;
            }
            case 2: {
                int pos; printf("Enter position: "); if (scanf("%d", &pos) != 1) break;
                int success = 0;
                head = delete_at_position(head, pos, &success);
                if (success) printf("Element deleted\n"); else printf("Deletion failed (invalid position)\n");
                break;
            }
            case 3: {
                traverse(head); break;
            }
            case 5:
                goto end_menu;
            default:
                printf("Invalid choice\n");
        }
    }
end_menu:
    while (head) { DNode *t = head; head = head->next; free(t); }
    return 0;
}
