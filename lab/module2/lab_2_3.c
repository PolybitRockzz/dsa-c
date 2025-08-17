#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triple;

int main(void) {
    int r, c;
    printf("Enter size of the sparse matrix: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        fprintf(stderr, "Invalid matrix size\n");
        return 1;
    }

    printf("Enter elements of sparse matrix: ");
    int total = r * c;

    Triple *triples = NULL;
    int count = 0;
    int cap = 0;

    for (int i = 0; i < total; ++i) {
        int x;
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(triples);
            return 1;
        }
        if (x != 0) {
            if (count >= cap) {
                int newcap = (cap == 0) ? 8 : cap * 2;
                Triple *tmp = (Triple *)realloc(triples, newcap * sizeof(Triple));
                if (!tmp) {
                    fprintf(stderr, "Memory allocation failed\n");
                    free(triples);
                    return 1;
                }
                triples = tmp;
                cap = newcap;
            }
            triples[count].row = i / c;
            triples[count].col = i % c;
            triples[count].val = x;
            ++count;
        }
    }

    printf("sparse matrix in 3-tuple format\n");
    printf("%d   %d   %d\n", r, c, count);
    for (int i = 0; i < count; ++i) {
        printf("%d   %d   %d\n", triples[i].row, triples[i].col, triples[i].val);
    }

    free(triples);
    return 0;
}
