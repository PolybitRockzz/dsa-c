#include <stdio.h>
#include <stdlib.h>

// Bubble sort: sorts arr of size n in ascending order (call by reference)
void bubbleSort(int arr[], int n) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// Print array elements separated by spaces
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int *arr = (int*)malloc(sizeof(int) * n);
    if (!arr) return 2;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
