#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (printf("Enter number of vertex: "), scanf("%d", &n) != 1 || n <= 0) return 0;
    int *mat = malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; ++i) mat[i] = 0;
    if (printf("Enter Adjacency Matrix:\n"), 1) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (scanf("%d", &mat[i * n + j]) != 1) { free(mat); return 0; }
    }
    int start;
    printf("Enter start vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) { free(mat); return 0; }
    int *vis = calloc(n, sizeof(int));
    int *q = malloc(n * sizeof(int));
    int head = 0, tail = 0;
    q[tail++] = start;
    vis[start] = 1;
    printf("\nBreadth First Search: ");
    while (head < tail) {
        int v = q[head++];
        printf("%d ", v);
        for (int i = 0; i < n; ++i) {
            if (mat[v * n + i] && !vis[i]) { vis[i] = 1; q[tail++] = i; }
        }
    }
    printf("\n");
    free(mat);
    free(vis);
    free(q);
    return 0;
}
