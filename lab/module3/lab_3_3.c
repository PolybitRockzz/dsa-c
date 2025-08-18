#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int degree;
    printf("Enter maximum degree of x: ");
    if (scanf("%d", &degree) != 1 || degree < 0) {
        fprintf(stderr, "Invalid degree\n");
        return 1;
    }
    int n = degree + 1;

    int *p1 = (int *)malloc(n * sizeof(int));
    int *p2 = (int *)malloc(n * sizeof(int));
    int *res = (int *)malloc(n * sizeof(int));
    if (!p1 || !p2 || !res) {
        fprintf(stderr, "Memory allocation failed\n");
        free(p1); free(p2); free(res);
        return 1;
    }

    printf("Enter Polynomial-1 from lowest degree to highest degree : ");
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &p1[i]) != 1) {
            fprintf(stderr, "Invalid input for polynomial 1\n");
            free(p1); free(p2); free(res);
            return 1;
        }
    }

    printf("Enter Polynomial-2: ");
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &p2[i]) != 1) {
            fprintf(stderr, "Invalid input for polynomial 2\n");
            free(p1); free(p2); free(res);
            return 1;
        }
    }

    for (int i = 0; i < n; ++i) res[i] = p1[i] + p2[i];

    printf("\nResultant Polynomial: ");
    int printed = 0;
    for (int i = degree; i >= 0; --i) {
        int coef = res[i];
        if (coef == 0) continue;
        if (printed > 0) {
            if (coef > 0) printf("+");
        }
        
        printf("%d", coef);
        printf("x^%d", i);
        printed = 1;
    }
    if (!printed) printf("0");
    printf("\n");

    free(p1); free(p2); free(res);
    return 0;
}
