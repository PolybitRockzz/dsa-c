#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int sumPrimes(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) sum += arr[i];
    }
    return sum;
}

int main(void) {
    int n;
    printf("Enter size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
    }

    int sum = sumPrimes(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}
