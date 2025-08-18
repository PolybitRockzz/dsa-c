#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triple;

int cmp_triple(const void *a, const void *b) {
    const Triple *ta = (const Triple *)a;
    const Triple *tb = (const Triple *)b;
    if (ta->row != tb->row) return ta->row - tb->row;
    return ta->col - tb->col;
}

int main(void) {
    int rows, cols, terms;
    printf("Enter sparse matrix in 3-tuple format\n");
    if (scanf("%d %d %d", &rows, &cols, &terms) != 3) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    Triple *triples = NULL;
    if (terms > 0) {
        triples = (Triple *)malloc(terms * sizeof(Triple));
        if (!triples) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    for (int i = 0; i < terms; ++i) {
        if (scanf("%d %d %d", &triples[i].row, &triples[i].col, &triples[i].val) != 3) {
            fprintf(stderr, "Invalid triple input\n");
            free(triples);
            return 1;
        }
    }

    for (int i = 0; i < terms; ++i) {
        int tmp = triples[i].row;
        triples[i].row = triples[i].col;
        triples[i].col = tmp;
    }

    if (terms > 1) qsort(triples, terms, sizeof(Triple), cmp_triple);

    printf("\nTranspose of sparse matrix:\n");
    printf("R   C   Element\n");
    printf("%d   %d   %d\n", cols, rows, terms);
    for (int i = 0; i < terms; ++i) {
        printf("%d   %d   %d\n", triples[i].row, triples[i].col, triples[i].val);
    }

    free(triples);
    return 0;
}
