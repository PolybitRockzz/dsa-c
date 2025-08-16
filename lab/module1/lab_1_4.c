#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int real;
    int imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex r;
    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;
    return r;
}

void multiply(const Complex *a, const Complex *b, Complex *res) {
    res->real = a->real * b->real - a->imag * b->imag;
    res->imag = a->real * b->imag + a->imag * b->real;
}

void print_result(const Complex *c) {
    printf("Sum=%d", c->real);
    if (c->imag >= 0)
        printf("+%di\n", c->imag);
    else
        printf("%di\n", c->imag);
}

int main(void) {
    Complex c1, c2, res;
    int choice;

    printf("Enter complex number 1: ");
    if (scanf("%d %d", &c1.real, &c1.imag) != 2) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    printf("Enter complex number 2: ");
    if (scanf("%d %d", &c2.real, &c2.imag) != 2) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    while (1) {
        printf("\nMENU\n");
        printf("1. addition\n");
        printf("2. multiplication\n");
        printf("3. exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            res = add(c1, c2);
            print_result(&res);
        } else if (choice == 2) {
            multiply(&c1, &c2, &res);
            print_result(&res);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
