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
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            printf("Vertices %d & %d are Adjacent ? (Y/N) :", i+1, j+1);
            if (scanf(" %c", &ans) != 1) ans = 'N';
            if (ans == 'Y' || ans == 'y') mat[i * n + j] = 1; else mat[i * n + j] = 0;
        }
    }
    printf("\n Vertex          In_Degree       Out_Degree      Total_Degree\n");
    for (int i = 0; i < n; ++i) {
        int indeg = 0, outdeg = 0;
        for (int j = 0; j < n; ++j) {
            outdeg += mat[i * n + j];
            indeg += mat[j * n + i];
        }
        int total = indeg + outdeg;
        printf("%6d %16d %16d %16d\n", i+1, indeg, outdeg, total);
    }
    free(mat);
    return 0;
}
