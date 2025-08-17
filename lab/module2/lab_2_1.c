#include <stdio.h>
#include <stdlib.h>

void traverse(int *arr, int n) {
    if (n <= 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array Elements: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

int linear_search(int *arr, int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) return i + 1;
    }
    return -1;
}

int insertElement(int **arr_ptr, int *n_ptr, int elem, int pos) {
    int n = *n_ptr;
    if (pos < 1 || pos > n + 1) return 0;

    int *arr = *arr_ptr;
    int *tmp = (int *)realloc(arr, (n + 1) * sizeof(int));
    if (!tmp) return 0;
    arr = tmp;

    for (int i = n; i >= pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    *arr_ptr = arr;
    *n_ptr = n + 1;
    return 1;
}

int deleteElement(int **arr_ptr, int *n_ptr, int pos) {
    int n = *n_ptr;
    if (pos < 1 || pos > n) return 0;

    int *arr = *arr_ptr;
    for (int i = pos - 1; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    if (n - 1 == 0) {
        free(arr);
        *arr_ptr = NULL;
        *n_ptr = 0;
        return 1;
    }

    int *tmp = (int *)realloc(arr, (n - 1) * sizeof(int));
    if (!tmp && n - 1 > 0) return 0;
    *arr_ptr = tmp;
    *n_ptr = n - 1;
    return 1;
}

int main(void) {
    int n;
    printf("Enter size n : ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *arr = NULL;
    if (n > 0) {
        arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        printf("Enter Array elements: ");
        for (int i = 0; i < n; ++i) {
            if (scanf("%d", &arr[i]) != 1) {
                fprintf(stderr, "Invalid input\n");
                free(arr);
                return 1;
            }
        }
    }

    while (1) {
        int option;
        printf("***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        if (scanf("%d", &option) != 1) break;

        if (option == 1) {
            int elem, pos;
            printf("Element to insert: ");
            if (scanf("%d", &elem) != 1) {
                printf("Invalid element\n");
                continue;
            }
            printf("Enter Position: ");
            if (scanf("%d", &pos) != 1) {
                printf("Invalid position\n");
                continue;
            }
            if (insertElement(&arr, &n, elem, pos)) {
                printf("Element inserted\n");
            } else {
                printf("Insertion failed (invalid position or memory)\n");
            }
        } else if (option == 2) {
            int pos;
            printf("Enter Position to delete: ");
            if (scanf("%d", &pos) != 1) {
                printf("Invalid position\n");
                continue;
            }
            if (deleteElement(&arr, &n, pos)) {
                printf("Element deleted\n");
            } else {
                printf("Deletion failed (invalid position)\n");
            }
        } else if (option == 3) {
            int key;
            printf("Enter element to search: ");
            if (scanf("%d", &key) != 1) {
                printf("Invalid input\n");
                continue;
            }
            int pos = linear_search(arr, n, key);
            if (pos == -1) printf("Element not found\n");
            else printf("Element found at position %d\n", pos);
        } else if (option == 4) {
            traverse(arr, n);
        } else if (option == 5) {
            break;
        } else {
            printf("Invalid option\n");
        }
    }

    free(arr);
    return 0;
}
