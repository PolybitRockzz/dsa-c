#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triple;

int cmp_triple(const void *a, const void *b) {
    const Triple *x = (const Triple *)a;
    const Triple *y = (const Triple *)b;
    if (x->row != y->row) return x->row - y->row;
    return x->col - y->col;
}

int main(void) {
    int r1, c1, t1;
    int r2, c2, t2;
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    if (scanf("%d %d %d", &r1, &c1, &t1) != 3) {
        fprintf(stderr, "Invalid input for matrix 1\n");
        return 1;
    }

    Triple *a = NULL;
    if (t1 > 0) {
        a = (Triple *)malloc(t1 * sizeof(Triple));
        if (!a) { fprintf(stderr, "Memory error\n"); return 1; }
        for (int i = 0; i < t1; ++i) {
            if (scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val) != 3) {
                fprintf(stderr, "Invalid triple for matrix 1\n");
                free(a); return 1;
            }
        }
    }

    printf("Enter sparse matrix-2 in 3-tuple format\n");
    if (scanf("%d %d %d", &r2, &c2, &t2) != 3) {
        fprintf(stderr, "Invalid input for matrix 2\n");
        free(a); return 1;
    }

    if (r1 != r2 || c1 != c2) {
        fprintf(stderr, "Matrix dimensions must match\n");
        free(a); return 1;
    }

    Triple *b = NULL;
    if (t2 > 0) {
        b = (Triple *)malloc(t2 * sizeof(Triple));
        if (!b) { fprintf(stderr, "Memory error\n"); free(a); return 1; }
        for (int i = 0; i < t2; ++i) {
            if (scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].val) != 3) {
                fprintf(stderr, "Invalid triple for matrix 2\n");
                free(a); free(b); return 1;
            }
        }
    }

    int total = t1 + t2;
    Triple *all = NULL;
    if (total > 0) {
        all = (Triple *)malloc(total * sizeof(Triple));
        if (!all) { fprintf(stderr, "Memory error\n"); free(a); free(b); return 1; }
    }
    int idx = 0;
    for (int i = 0; i < t1; ++i) all[idx++] = a[i];
    for (int i = 0; i < t2; ++i) all[idx++] = b[i];

    free(a); free(b);

    if (idx > 1) qsort(all, idx, sizeof(Triple), cmp_triple);

    Triple *res = NULL;
    int res_cap = 0, res_cnt = 0;
    for (int i = 0; i < idx; ) {
        int rr = all[i].row;
        int cc = all[i].col;
        int sum = 0;
        int j = i;
        while (j < idx && all[j].row == rr && all[j].col == cc) {
            sum += all[j].val;
            ++j;
        }
        if (sum != 0) {
            if (res_cnt >= res_cap) {
                int nc = (res_cap == 0) ? 8 : res_cap * 2;
                Triple *tmp = (Triple *)realloc(res, nc * sizeof(Triple));
                if (!tmp) { fprintf(stderr, "Memory error\n"); free(all); free(res); return 1; }
                res = tmp; res_cap = nc;
            }
            res[res_cnt].row = rr;
            res[res_cnt].col = cc;
            res[res_cnt].val = sum;
            ++res_cnt;
        }
        i = j;
    }

    free(all);

    printf("\nResultant Matrix in 3-tuple format\n");
    printf("%d   %d   %d\n", r1, c1, res_cnt);
    for (int i = 0; i < res_cnt; ++i) {
        printf("%d   %d   %d\n", res[i].row, res[i].col, res[i].val);
    }

    free(res);
    return 0;
}
