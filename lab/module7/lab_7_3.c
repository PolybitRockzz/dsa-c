#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    printf("Enter Queue size: ");
    if (scanf("%d", &size) != 1 || size <= 0) return 1;

    int *cq = (int*)malloc(size * sizeof(int));
    if (!cq) { fprintf(stderr, "Memory allocation failed\n"); return 1; }

    int front = -1, rear = -1;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("\nEnter option: ");
        int opt; if (scanf("%d", &opt) != 1) break;

        switch (opt) {
            case 1: {
                // is full when next position of rear equals front
                int next = (rear + 1) % size;
                if (next == front) { printf("Queue is full\n"); break; }
                int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
                if (front == -1) { front = rear = 0; cq[rear] = x; }
                else {
                    rear = (rear + 1) % size; cq[rear] = x;
                }
                break;
            }
            case 2: {
                if (front == -1) { printf("Queue is empty\n"); break; }
                // delete element
                int deleted = cq[front];
                if (front == rear) { front = rear = -1; }
                else front = (front + 1) % size;
                printf("Element deleted\n");
                break;
            }
            case 3: {
                printf("Queue Empty: %s\n", (front == -1) ? "True" : "False");
                break;
            }
            case 4: {
                int next = (rear + 1) % size;
                printf("Queue Full: %s\n", (next == front) ? "True" : "False");
                break;
            }
            case 5: {
                if (front == -1) { printf("CQueue: \n"); break; }
                printf("CQueue: ");
                int i = front;
                while (1) {
                    printf("%d  ", cq[i]);
                    if (i == rear) break;
                    i = (i + 1) % size;
                }
                printf("\n");
                break;
            }
            case 6:
                free(cq);
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    free(cq);
    return 0;
}
