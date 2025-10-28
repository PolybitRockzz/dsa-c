#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int *mat, int *vis) {
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; ++i) if (mat[v * n + i] && !vis[i]) dfs(i, n, mat, vis);
}

int main() {
    int n;
    printf("Enter number of vertex: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *mat = malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; ++i) mat[i] = 0;
    printf("Enter adjacency matrix (rows of 0/1, space-separated):\n");
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (scanf("%d", &mat[i * n + j]) != 1) return 0;
    int *vis = calloc(n, sizeof(int));
    int start;
    printf("Enter start vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) { free(mat); free(vis); return 0; }
    printf("\nDepth First Search: ");
    dfs(start, n, mat, vis);
    printf("\n");
    free(mat);
    free(vis);
    return 0;
}
