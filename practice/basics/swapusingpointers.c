#include <stdio.h>

// Custom Function: Swap Two Values
void swapValues(int* a, int* b) {
    int temp = *a;  // Dereferencing pointer to get the value at address 'a'
    *a = *b;        // Assigning the value at address 'b' to the location 'a'
    *b = temp;      // Assigning the original value of 'a' (stored in 'temp') to the location 'b'
}

int main() {
    int num1 = 5, num2 = 10;

    // Display original values
    printf("Before Swap:\n");
    printf("num1: %d\nnum2: %d\n\n", num1, num2);

    // Swap values using the custom function
    swapValues(&num1, &num2);

    // Display values after swapping
    printf("After Swap:\n");
    printf("num1: %d\nnum2: %d\n", num1, num2);

    // The return statement indicates the end of the main function.
    return 0;
}
