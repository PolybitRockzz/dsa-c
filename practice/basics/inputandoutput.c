#include <stdio.h>

int main() {
    // Declare variables to store user input
    int userAge;
    float userHeight;

    // Prompt user for input
    printf("Enter your age: ");

    // Use scanf to read an integer, note the use of & before the variable
    scanf("%d", &userAge);

    // Prompt user for another input
    printf("Enter your height in meters: ");

    // Use scanf to read a floating-point number, note the use of & before the variable
    scanf("%f", &userHeight);

    // Display user's information using printf
    printf("You entered:\n");
    printf("Age: %d years\n", userAge);
    printf("Height: %.2f meters\n", userHeight);

    // The return statement indicates the end of the main function.
    return 0;
}
