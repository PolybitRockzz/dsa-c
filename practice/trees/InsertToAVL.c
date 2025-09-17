#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // new node is initially at height 1
    return node;
}

// Right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // Perform normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else  // Equal data is not allowed in BST
        return node;

    // Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If the node is unbalanced, there are 4 cases

    // Case 1: Left Left (LL)
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right (RR)
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right (LR)
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node* root = NULL;

    /* Constructing tree shown in many AVL examples
       Inserting 10, 20, 30, 40, 50, 25 will trigger rotations */
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i)
        root = insert(root, values[i]);

    printf("Preorder traversal of the constructed AVL tree: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}
