#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) return NULL;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive preorder traversal
void preorderRec(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRec(root->left);
    preorderRec(root->right);
}

// Iterative preorder traversal using a stack
void preorderIter(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

int main() {
    // Constructing the same sample tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Preorder traversal (recursive): ");
    preorderRec(root);
    printf("\n");

    // printf("Preorder traversal (iterative): ");
    // preorderIter(root);
    // printf("\n");

    return 0;
}
