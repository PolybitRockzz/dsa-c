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

Node* insert_at_position(Node *head, int val, int pos) {
    // pos is 1-based. Insert at position pos (1 means at head)
    if (pos < 1) return head;
    Node *newn = create_node(val);
    if (!newn) return head;
    if (pos == 1) {
        newn->next = head;
        return newn;
    }
    Node *cur = head;
    int i = 1;
    while (cur && i < pos - 1) {
        cur = cur->next;
        ++i;
    }
    if (!cur) {
        free(newn);
        return head;
    }
    newn->next = cur->next;
    cur->next = newn;
    return head;
}

Node* delete_at_position(Node *head, int pos, int *success) {
    *success = 0;
    if (!head || pos < 1) return head;
    if (pos == 1) {
        Node *tmp = head->next;
        free(head);
        *success = 1;
        return tmp;
    }
    Node *cur = head;
    int i = 1;
    while (cur->next && i < pos - 1) {
        cur = cur->next;
        ++i;
    }
    if (!cur->next) return head;
    Node *t = cur->next;
    cur->next = t->next;
    free(t);
    *success = 1;
    return head;
}

int count_nodes(Node *head) {
    int cnt = 0;
    while (head) { ++cnt; head = head->next; }
    return cnt;
}

void traverse(Node *head) {
    if (!head) {
        printf("The list is empty\n");
        return;
    }
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

    Node *head = NULL, *tail = NULL;
    if (n > 0) {
        printf("Enter the elements: ");
        for (int i = 0; i < n; ++i) {
            int x; if (scanf("%d", &x) != 1) return 1;
            Node *p = create_node(x);
            if (!p) { fprintf(stderr, "Memory error\n"); return 1; }
            if (!head) head = tail = p;
            else { tail->next = p; tail = p; }
        }
    }

    while (1) {
        int choice;
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: {
                int elem, pos;
                printf("Enter element: "); if (scanf("%d", &elem) != 1) { break; }
                printf("Enter position: "); if (scanf("%d", &pos) != 1) { break; }
                int before = count_nodes(head);
                head = insert_at_position(head, elem, pos);
                int after = count_nodes(head);
                if (after > before) printf("Node inserted\n");
                else printf("Insertion failed\n");
                break;
            }
            case 2: {
                int pos; printf("Enter position: "); if (scanf("%d", &pos) != 1) { break; }
                int success = 0;
                head = delete_at_position(head, pos, &success);
                if (success) printf("Element deleted\n"); else printf("Deletion failed (invalid position)\n");
                break;
            }
            case 3: {
                int cnt = count_nodes(head);
                printf("The total number of nodes: %d\n", cnt);
                break;
            }
            case 4: {
                traverse(head);
                break;
            }
            case 5:
                goto end_menu;
            default:
                printf("Invalid choice\n");
        }
    }

end_menu:
    while (head) {
        Node *t = head;
        head = head->next;
        free(t);
    }
    return 0;
}
