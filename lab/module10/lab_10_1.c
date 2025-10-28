#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of vertex: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *mat = malloc(n * n * sizeof(int));
    if (!mat) return 0;
    for (int i = 0; i < n * n; ++i) mat[i] = 0;
    char ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            printf("Vertices %d & %d are Adjacent ? (Y/N) :", i + 1, j + 1);
            if (scanf(" %c", &ans) != 1) ans = 'N';
            if (ans == 'Y' || ans == 'y') {
                mat[i * n + j] = 1;
                mat[j * n + i] = 1;
            } else {
                mat[i * n + j] = 0;
                mat[j * n + i] = 0;
            }
        }
    }
    printf("\n Vertex          Degree\n");
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) degree += mat[i * n + j];
        printf("     %d           %d\n", i + 1, degree);
    }
    free(mat);
    return 0;
}

