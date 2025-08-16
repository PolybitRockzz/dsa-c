#include <stdio.h>

// Custom Function: String Length
int customStrlen(const char* str) {
    // Iterate through the characters until the null terminator is encountered
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Custom Function: Check if a Number is Prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;  // Numbers less than or equal to 1 are not prime
    }

    // Check for factors from 2 to the square root of the number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Found a factor, not a prime number
        }
    }

    return 1;  // No factors found, prime number
}

int main() {
    // Example: Using customStrlen
    char greeting[] = "Hello, C!";
    printf("Length of Greeting: %d\n", customStrlen(greeting));

    // Example: Using isPrime
    int number = 19;
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    // The return statement indicates the end of the main function.
    return 0;
}
