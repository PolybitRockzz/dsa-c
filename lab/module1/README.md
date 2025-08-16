# Module 1

Date: Jul 25, 2025

### [Question 1](./lab_1_1.c)

**Question:**

Write a program to read two numbers and compare the numbers using function call by address.

**Sample Input:**
```
Enter two numbers: 50  80
```
**Sample Output:**
```
50 is smaller than 80
```

**Sample Input:**
```
Enter two numbers: 40  10
```
**Sample Output:**
```
40 is greater than 10
```

**Sample Input:**
```
Enter two numbers: 50  50
```
**Sample Output:**
```
Both numbers are same
```

### [Question 2](./lab_1_2.c)

**Question:**

Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

**Sample Input:**
```
Enter size of the array: 5
Enter array elements: 3  9  7  4  8
```
**Sample Output:**
```
Sum = 10
```

### [Question 3](./lab_1_3.c)

**Question:**

Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: `emp-id`, `name`, `designation`, `basic_salary`, `hra%`, `da%`. Display the information of employees with gross salary. Use array of structure.

**Sample Input:**
```
Enter no.of employees: 2
Enter employee 1 information:
Avneesh
Professor
10000
15%
45%
Enter employee 2 information:
Avantika
Professor
20000
10%
35%
```
**Sample Output:**
```
Employee Information:
 
Name: Suchismita
Designation: Professor
Basic Salary:10000
HRA %: 15%
DA %: 45%
Gross Salary: 16000
 
Name: Sarita
Designation: Professor
Basic Salary: 20000
HRA %: 10%
DA %: 35%
Gross Salary: 29000
```

### [Question 4](./lab_1_4.c)

**Question:**

Write a menu driven program to create a structure to represent complex number and perform the following operation using function:
 
1. addition of two complex number (call by value)
2. multiplication of two complex number (call by address)

**Sample Input/Output:**
```
Enter complex number 1: 3  4
Enter complex number 2: 4  5
 
MENU
1. addition
2. multiplication
Enter your choice: 1

Sum=7+9i
Enter your choice: 2
 
Sum=4+19i
```