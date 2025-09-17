#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to find the node with the minimum value in a tree (in-order successor)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from a BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    // Recur down the tree to find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found

        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the in-order successor's value to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;

    // Build sample BST: insert 50,30,70,20,40,60,80
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); ++i)
        root = insert(root, vals[i]);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    // Delete a leaf
    root = deleteNode(root, 20);
    printf("After deleting 20 (leaf): ");
    inorder(root);
    printf("\n");

    // Delete node with one child
    root = deleteNode(root, 30);
    printf("After deleting 30 (one child): ");
    inorder(root);
    printf("\n");

    // Delete node with two children
    root = deleteNode(root, 50);
    printf("After deleting 50 (two children): ");
    inorder(root);
    printf("\n");

    return 0;
}
