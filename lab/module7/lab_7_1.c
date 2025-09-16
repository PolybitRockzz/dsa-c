#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    printf("Enter the size of Queue: ");
    if (scanf("%d", &size) != 1 || size <= 0) return 1;

    int *queue = (int *)malloc(size * sizeof(int));
    if (!queue) { fprintf(stderr, "Memory allocation failed\n"); return 1; }

    int front = -1, rear = -1;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("\nEnter option: ");
        int opt; if (scanf("%d", &opt) != 1) break;

        switch (opt) {
            case 1: {
                if (rear == size - 1) { printf("Queue is full\n"); break; }
                int x; printf("Enter element: "); if (scanf("%d", &x) != 1) break;
                if (front == -1) front = 0;
                queue[++rear] = x;
                break;
            }
            case 2: {
                if (front == -1 || front > rear) { printf("Queue is empty\n"); break; }
                // delete element
                int deleted = queue[front++];
                printf("Element deleted\n");
                if (front > rear) { front = rear = -1; }
                break;
            }
            case 3: {
                if (front == -1) printf("Queue empty: True\n"); else printf("Queue empty: False\n");
                break;
            }
            case 4: {
                if (rear == size - 1) printf("Queue full: True\n"); else printf("Queue full: False\n");
                break;
            }
            case 5: {
                if (front == -1) { printf("Queue: \n"); break; }
                printf("Queue: ");
                for (int i = front; i <= rear; ++i) printf("%d  ", queue[i]);
                printf("\n");
                break;
            }
            case 6:
                free(queue);
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    free(queue);
    return 0;
}
