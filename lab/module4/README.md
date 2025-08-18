# Module 4

Date: Aug 12, 2025

### [Question 1](./lab_4_1.c)

**Question:**

Write a program to create a single linked list of n nodes and perform the following menu-based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list

**Sample Input/Output:**
```
Enter number of nodes: 7
Enter the elements: 17  23  47 11  78  92  51
MENU:
1. Insert the node at a position
2. Delete a node from specific position
3. Count
4. Traversal
5. Exit
Enter choice: 1
Enter element: 66
Enter position: 2
Node inserted
Enter choice: 4
The list is: 17-> 66->23-> 47-> 11-> 78-> 92-> 51
Enter the choice: 3
The total number of nodes: 8
```

### [Question 2](./lab_4_2.c)

**Question:**

In addition to *Question 1*, perform following operations using function on the single linked list:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list

**Sample Input/Output:**
```
Enter number of nodes: 7
Enter the elements: 17  23  47 11  78  92  51
MENU:
1. Insert the node at a position
2. Delete a node from specific position
3. Count
4. Traverse
5. Search
6. Sort
7. Reverse
8. Exit
Enter choice: 1
Enter element: 66
Enter position: 2
Node inserted
Enter choice: 4
The list is: 17-> 66->23-> 47-> 11-> 78-> 92-> 51
Enter the choice: 5
Enter element to be searched: 23
Element found at node-3
Enter the choice: 7
Reverse list: 51->92->78->11->47->23->66->17
```

### [Question 3](./lab_4_3.c)

**Question:**

Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations.

**Sample Input:**
```
Polynomial-1:
Enter the Maximum power of x: 2
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1: 3
 
Enter the coefficient of degree 0:2
Polynomial-2:
Enter the Maximum power of x: 3
Enter the coefficient of degree 3: 5
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1:6
Enter the coefficient of degree 0:10
```
**Sample Output:**
```
Sum: 5x^3+8x^2+9x^1+12x^0
```
