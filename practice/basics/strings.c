#include <stdio.h>
#include <string.h>

int main() {
    // String Initialization
    printf("String Initialization:\n");
    char greeting1[] = "Hello, C!";
    char greeting2[12] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'C', '!', '\0'};

    // Print Strings
    printf("Greeting 1: %s\n", greeting1);
    printf("Greeting 2: %s\n\n", greeting2);

    // String Length
    printf("String Length:\n");
    printf("Length of Greeting 1: %zu\n", strlen(greeting1));
    printf("Length of Greeting 2: %zu\n\n", strlen(greeting2));

    // String Concatenation
    printf("String Concatenation:\n");
    char firstName[] = "John";
    char lastName[] = "Doe";
    char fullName[20];

    strcpy(fullName, firstName);  // Copy the first name
    strcat(fullName, " ");       // Concatenate a space
    strcat(fullName, lastName);   // Concatenate the last name

    printf("Full Name: %s\n\n", fullName);

    // String Comparison
    printf("String Comparison:\n");
    char word1[] = "apple";
    char word2[] = "banana";

    if (strcmp(word1, word2) == 0) {
        printf("%s and %s are equal.\n", word1, word2);
    } else {
        printf("%s and %s are not equal.\n", word1, word2);
    }

    // The return statement indicates the end of the main function.
    return 0;
}
