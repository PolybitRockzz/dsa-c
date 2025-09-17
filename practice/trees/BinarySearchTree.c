#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}


// Search BST using binary search property. Returns 1 if found, 0 otherwise.
int search(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (value == root->data) return 1;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}


// Validate BST: ensure all nodes follow min/max constraints.
int validateUtil(struct Node* node, int min, int max) {
    if (node == NULL) return 1;
    if (node->data <= min || node->data >= max) return 0;
    return validateUtil(node->left, min, node->data) && validateUtil(node->right, node->data, max);
}

int validate(struct Node* root) {
    return validateUtil(root, INT_MIN, INT_MAX);
}


// Function to calculate the height of a tree
int height(struct Node* node) {
    if (node == NULL)
        return -1;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}


// Inorder traversal (will print sorted order for BST)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


// Function to print the depth of a node
void printDepth(struct Node* node, int level) {
    if (node != NULL) {
        printf("Node %d is at depth %d\n", node->data, level);
        printDepth(node->left, level + 1);
        printDepth(node->right, level + 1);
    }
}


int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Validate BST\n");
        printf("4. Inorder (print sorted)\n");
        printf("5. Height\n");
        printf("6. Print depths\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) { while(getchar()!= '\n'); break; }
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1) { while(getchar()!= '\n'); break; }
                if (search(root, value)) printf("%d found in BST\n", value);
                else printf("%d not found\n", value);
                break;
            case 3:
                if (validate(root)) printf("Tree is a valid BST\n");
                else printf("Tree is NOT a valid BST\n");
                break;
            case 4:
                printf("Inorder (sorted): ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 6:
                printDepth(root, 0);
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
