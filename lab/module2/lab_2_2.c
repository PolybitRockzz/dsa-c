#include <stdio.h>
#include <stdlib.h>

int count_nonzero(int *mat, int n) {
    int cnt = 0;
    for (int i = 0; i < n * n; ++i) if (mat[i] != 0) ++cnt;
    return cnt;
}

void print_strict_upper(int *mat, int n) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; ++i) {
        // only print rows that have elements above diagonal
        if (i >= n - 1) break;
        // indent with 4 spaces per row as sample
        for (int s = 0; s < i * 4; ++s) putchar(' ');
        for (int j = i + 1; j < n; ++j) {
            printf("%d", mat[i * n + j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
}

void print_adjacent_diagonals(int *mat, int n) {
    // elements just above main diagonal (i,i+1)
    printf("Elements just above main diagonal: ");
    if (n <= 1) {
        printf("None\n");
    } else {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d", mat[i * n + (i + 1)]);
            if (i < n - 2) printf(" ");
        }
        printf("\n");
    }

    // elements just below main diagonal (i+1,i)
    printf("Elements just below main diagonal: ");
    if (n <= 1) {
        printf("None\n");
    } else {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d", mat[(i + 1) * n + i]);
            if (i < n - 2) printf(" ");
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    printf("Enter size of the square matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *mat = (int *)malloc(n * n * sizeof(int));
    if (!mat) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &mat[i * n + j]) != 1) {
                fprintf(stderr, "Invalid input\n");
                free(mat);
                return 1;
            }
        }
    }

    int nonzero = count_nonzero(mat, n);
    printf("\nNonzero elements : %d\n", nonzero);

    print_strict_upper(mat, n);
    printf("\n");
    print_adjacent_diagonals(mat, n);

    free(mat);
    return 0;
}
