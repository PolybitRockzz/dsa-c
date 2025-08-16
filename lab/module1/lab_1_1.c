#include <stdio.h>

void compare(int *a, int *b) {
    if (*a < *b) {
        printf("%d is smaller than %d\n", *a, *b);
    } else if (*a > *b) {
        printf("%d is greater than %d\n", *a, *b);
    } else {
        printf("Both numbers are same\n");
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    compare(&num1, &num2);
    return 0;
}
