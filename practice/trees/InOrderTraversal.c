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

// Recursive inorder traversal
void inorderRec(struct Node* root) {
    if (root == NULL) return;
    inorderRec(root->left);
    printf("%d ", root->data);
    inorderRec(root->right);
}

// Iterative inorder traversal using a stack
void inorderIter(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
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

    printf("Inorder traversal (recursive): ");
    inorderRec(root);
    printf("\n");

    // printf("Inorder traversal (iterative): ");
    // inorderIter(root);
    // printf("\n");

    return 0;
}
