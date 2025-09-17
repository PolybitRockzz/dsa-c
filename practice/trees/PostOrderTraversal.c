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

// Recursive postorder traversal
void postorderRec(struct Node* root) {
    if (root == NULL) return;
    postorderRec(root->left);
    postorderRec(root->right);
    printf("%d ", root->data);
}

// Iterative postorder traversal using two stacks (arrays)
void postorderIter(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }

    while (top2 != -1) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

int main() {
    // Constructing the same sample tree used in other traversal files
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Postorder traversal (recursive): ");
    postorderRec(root);
    printf("\n");

    // printf("Postorder traversal (iterative): ");
    // postorderIter(root);
    // printf("\n");

    return 0;
}

