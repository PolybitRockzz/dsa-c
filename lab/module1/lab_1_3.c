#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char designation[100];
    int basic_salary;
    int hra_perc;
    int da_perc;
} Employee;

int main(void) {
    int n;
    printf("Enter no.of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of employees\n");
        return 1;
    }

    Employee *emps = (Employee *)malloc(n * sizeof(Employee));
    if (!emps) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Enter employee %d information:\n", i + 1);
        if (scanf(" %99s", emps[i].name) != 1) {
            fprintf(stderr, "Invalid name\n");
            free(emps);
            return 1;
        }
        if (scanf(" %99s", emps[i].designation) != 1) {
            fprintf(stderr, "Invalid designation\n");
            free(emps);
            return 1;
        }
        if (scanf("%d", &emps[i].basic_salary) != 1) {
            fprintf(stderr, "Invalid basic salary\n");
            free(emps);
            return 1;
        }
        if (scanf("%d%%", &emps[i].hra_perc) != 1) {
            fprintf(stderr, "Invalid HRA percent (expect format like 15%)\n");
            free(emps);
            return 1;
        }
        if (scanf("%d%%", &emps[i].da_perc) != 1) {
            fprintf(stderr, "Invalid DA percent (expect format like 45%)\n");
            free(emps);
            return 1;
        }
    }

    printf("Employee Information:\n\n");
    for (int i = 0; i < n; ++i) {
        int basic = emps[i].basic_salary;
        int hra = (basic * emps[i].hra_perc) / 100;
        int da = (basic * emps[i].da_perc) / 100;
        int gross = basic + hra + da;

        printf("Name: %s\n", emps[i].name);
        printf("Designation: %s\n", emps[i].designation);
        printf("Basic Salary:%d\n", basic);
        printf("HRA %%: %d%%\n", emps[i].hra_perc);
        printf("DA %%: %d%%\n", emps[i].da_perc);
        printf("Gross Salary: %d\n\n", gross);
    }

    free(emps);
    return 0;
}
