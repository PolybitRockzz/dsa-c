#include <stdio.h>

// Define a struct named 'Person'
struct Person {
    char name[50];
    int age;
    float height;
};

// Introduce typedef for a more concise declaration
typedef struct Person Person;

int main() {
    // Declare and Initialize a struct variable
    struct Person person1;
    // Initialize struct members
    strcpy(person1.name, "John");
    person1.age = 25;
    person1.height = 1.75;

    // Accessing and Printing Struct Members
    printf("Person 1:\nName: %s\nAge: %d\nHeight: %.2f meters\n\n", person1.name, person1.age, person1.height);

    // Using Typedef for a more concise declaration
    Person person2;  // 'Person' instead of 'struct Person'
    // Initialize struct members
    strcpy(person2.name, "Alice");
    person2.age = 30;
    person2.height = 1.65;

    // Accessing and Printing Struct Members
    printf("Person 2:\nName: %s\nAge: %d\nHeight: %.2f meters\n", person2.name, person2.age, person2.height);

    // The return statement indicates the end of the main function.
    return 0;
}
