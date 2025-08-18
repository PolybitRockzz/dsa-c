#include <stdio.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front; // index of front element
    int rear;  // index of last element
    int count; // number of elements
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = item;
    q->count++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return val;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return;
    }
    int idx = q->front;
    for (int i = 0; i < q->count; ++i) {
        printf("%d", q->items[idx]);
        if (i < q->count - 1) printf(" ");
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    while (1) {
        printf("STACK USING TWO QUEUES\n");
        printf("1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: {
                int item;
                printf("Enter the element to push: ");
                if (scanf("%d", &item) != 1) break;
                if (isFull(&q1) && !isEmpty(&q2)) {
                    printf("Stack is full\n");
                    break;
                }
                enqueue(&q2, item);
                while (!isEmpty(&q1)) {
                    int v = dequeue(&q1);
                    enqueue(&q2, v);
                }
                q1 = q2;
                initQueue(&q2);
                printf("%d pushed into stack.\n", item);
                break;
            }
            case 2: {
                int item = dequeue(&q1);
                if (item == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("%d popped from stack.\n", item);
                }
                break;
            }
            case 3: {
                int item = peek(&q1);
                if (item == -1) printf("Stack is empty\n");
                else printf("Top element is: %d\n", item);
                break;
            }
            case 4: {
                displayQueue(&q1);
                break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
