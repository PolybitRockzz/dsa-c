#include <stdio.h>

int main() {
    // Declare variables for operands
    int num1 = 10, num2 = 5;

    // Addition
    int sum = num1 + num2;
    printf("Sum: %d\n", sum);

    // Subtraction
    int difference = num1 - num2;
    printf("Difference: %d\n", difference);

    // Multiplication
    int product = num1 * num2;
    printf("Product: %d\n", product);

    // Division
    float quotient = (float)num1 / num2; // Casting to float for precise division
    printf("Quotient: %.2f\n", quotient);

    // Modulo
    int remainder = num1 % num2;
    printf("Remainder: %d\n", remainder);

    // The return statement indicates the end of the main function.
    return 0;
}
