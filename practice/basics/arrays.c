#include <stdio.h>

int main() {
    // Array Initialization and Index Access
    printf("Array Initialization and Index Access:\n");
    int myArray[5] = {1, 2, 3, 4, 5};

    // Accessing elements using indices
    printf("Element at index 2: %d\n", myArray[2]);

    // Looping to Access and Print Array Elements
    printf("\nLooping to Access and Print Array Elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Mutating Array Elements
    printf("\nMutating Array Elements:\n");
    myArray[3] = 99;
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Multi-Dimensional Array
    printf("\nMulti-Dimensional Array:\n");
    int multiDimArray[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Accessing elements using indices
    printf("Element at row 1, column 2: %d\n", multiDimArray[1][2]);

    // Looping to Access and Print Multi-Dimensional Array Elements
    printf("\nLooping to Access and Print Multi-Dimensional Array Elements:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", multiDimArray[i][j]);
        }
        printf("\n");
    }

    // The return statement indicates the end of the main function.
    return 0;
}
