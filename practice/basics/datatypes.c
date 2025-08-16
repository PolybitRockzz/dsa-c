#include <stdio.h>

void myFunction();

int main() {
    // Integer data type
    int myInteger = 42;
    printf("Integer: %d\n", myInteger);

    // Floating-point data type
    float myFloat = 3.14;
    printf("Float: %f\n", myFloat);

    // Character data type
    char myChar = 'A';
    printf("Character: %c\n", myChar);

    // Double data type
    double myDouble = 1234.5678;
    printf("Double: %lf\n", myDouble);

    // Array data type
    int myArray[3] = {1, 2, 3};
    printf("Array: %d, %d, %d\n", myArray[0], myArray[1], myArray[2]);

    // String data type (using an array of characters)
    char myString[] = "Hello, C!";
    printf("String: %s\n", myString);

    myFunction();

    // The return statement indicates the end of the main function.
    return 0;
}

// Void data type (used with functions that return nothing
void myFunction() {
    printf("This function does not return anything.\n");
}
