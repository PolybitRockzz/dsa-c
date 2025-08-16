#include <stdio.h>

int main() {
    // Declare two variables for user input
    int num1, num2;

    // Prompt user for input
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // Relational Operators
    printf("Relational Operators:\n");
    printf("%d > %d is %d\n", num1, num2, num1 > num2);
    printf("%d < %d is %d\n", num1, num2, num1 < num2);
    printf("%d >= %d is %d\n", num1, num2, num1 >= num2);
    printf("%d <= %d is %d\n", num1, num2, num1 <= num2);
    printf("%d == %d is %d\n", num1, num2, num1 == num2);
    printf("%d != %d is %d\n", num1, num2, num1 != num2);

    // Ternary Operator
    printf("\nTernary Operator:\n");
    int result = (num1 > num2) ? num1 : num2;
    printf("The larger number is: %d\n", result);

    // The return statement indicates the end of the main function.
    return 0;
}
