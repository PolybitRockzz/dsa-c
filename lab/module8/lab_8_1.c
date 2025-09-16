#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int size_deque;
int dq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % size_deque);
}

int isEmpty() {
    return front == -1;
}

void insertRight(int val) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (isEmpty()) { front = rear = 0; dq[rear] = val; }
    else { rear = (rear + 1) % size_deque; dq[rear] = val; }
}

void insertLeft(int val) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (isEmpty()) { front = rear = 0; dq[front] = val; }
    else { front = (front - 1 + size_deque) % size_deque; dq[front] = val; }
}

int deleteLeft(int *val) {
    if (isEmpty()) return 0;
    *val = dq[front];
    if (front == rear) { front = rear = -1; }
    else { front = (front + 1) % size_deque; }
    return 1;
}

int deleteRight(int *val) {
    if (isEmpty()) return 0;
    *val = dq[rear];
    if (front == rear) { front = rear = -1; }
    else { rear = (rear - 1 + size_deque) % size_deque; }
    return 1;
}

void displayDeque() {
    if (isEmpty()) { printf("Deque: \n"); return; }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d  ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % size_deque;
    }
    printf("\n");
}

void inputRestrictedMenu() {
    while (1) {
        printf("\nInput restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Peek left/right\n");
        printf("5. Display\n");
        printf("6. Back\n");
        printf("Enter choice: ");
        int ch; if (scanf("%d", &ch) != 1) break;
        if (ch == 1) {
            int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
            insertRight(x);
        } else if (ch == 2) {
            int val; if (deleteLeft(&val)) printf("%d deleted\n", val); else printf("Deque is empty\n");
        } else if (ch == 3) {
            int val; if (deleteRight(&val)) printf("%d deleted\n", val); else printf("Deque is empty\n");
        } else if (ch == 4) {
            if (isEmpty()) { printf("Deque is empty\n"); }
            else { printf("Left: %d, Right: %d\n", dq[front], dq[rear]); }
        } else if (ch == 5) {
            displayDeque();
        } else if (ch == 6) {
            break;
        } else printf("Invalid choice\n");
    }
}

void outputRestrictedMenu() {
    while (1) {
        printf("\nOutput restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Peek left/right\n");
        printf("5. Display\n");
        printf("6. Back\n");
        printf("Enter choice: ");
        int ch; if (scanf("%d", &ch) != 1) break;
        if (ch == 1) {
            int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
            insertRight(x);
        } else if (ch == 2) {
            int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
            insertLeft(x);
        } else if (ch == 3) {
            int val; if (deleteLeft(&val)) printf("%d deleted\n", val); else printf("Deque is empty\n");
        } else if (ch == 4) {
            if (isEmpty()) { printf("Deque is empty\n"); }
            else { printf("Left: %d, Right: %d\n", dq[front], dq[rear]); }
        } else if (ch == 5) {
            displayDeque();
        } else if (ch == 6) {
            break;
        } else printf("Invalid choice\n");
    }
}

int main(void) {
    printf("Enter deque size (max %d): ", MAX);
    if (scanf("%d", &size_deque) != 1 || size_deque <= 0 || size_deque > MAX) return 1;

    while (1) {
        printf("\nDeque Modes\n");
        printf("1. Input-restricted Deque\n");
        printf("2. Output-restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter mode: ");
        int mode; if (scanf("%d", &mode) != 1) break;
        switch (mode) {
            case 1: inputRestrictedMenu(); break;
            case 2: outputRestrictedMenu(); break;
            case 3: return 0;
            default: printf("Invalid mode\n");
        }
    }
    return 0;
}
