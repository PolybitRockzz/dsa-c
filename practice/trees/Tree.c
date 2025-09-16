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
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of a tree
int height(struct Node* node) {
    if (node == NULL)
        return -1;  // Height of an empty tree is -1
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Height is the maximum of leftHeight or rightHeight plus 1
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
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
    // Constructing the tree from the ASCII art
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Height of the tree
    printf("Height of the tree: %d\n", height(root));

    // Depth of each node
    printDepth(root, 0);

    return 0;
}
