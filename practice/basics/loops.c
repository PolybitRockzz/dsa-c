#include <stdio.h>

int main() {
    // For Loop
    printf("For Loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While Loop
    printf("While Loop:\n");
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // Do-While Loop
    printf("Do-While Loop:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");

    // The return statement indicates the end of the main function.
    return 0;
}
