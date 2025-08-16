#include <stdio.h>

int main() {
    int number = 42;
    int *ptr;  // Declare a pointer variable

    // Assign the address of 'number' to the pointer
    ptr = &number;

    // Display the value and address of 'number' using the pointer
    printf("Value of 'number': %d\n", *ptr);  // Dereferencing the pointer
    printf("Address of 'number': %p\n", ptr);

    // The return statement indicates the end of the main function.
    return 0;
}
