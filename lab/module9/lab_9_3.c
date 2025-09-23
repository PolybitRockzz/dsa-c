#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* curr = root;
    while (curr->left) curr = curr->left;
    return curr;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* curr = root;
    while (curr->right) curr = curr->right;
    return curr;
}

// Delete a node from BST and return new root
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Two children: get inorder successor (smallest in right subtree)
            struct Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int isLeaf(struct Node* node) {
    return node && node->left == NULL && node->right == NULL;
}

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (isLeaf(root)) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// depth of a node (root at depth 0). returns -1 if not found.
int nodeDepth(struct Node* root, int key) {
    int depth = 0;
    struct Node* curr = root;
    while (curr) {
        if (key == curr->data) return depth;
        else if (key < curr->data) curr = curr->left;
        else curr = curr->right;
        depth++;
    }
    return -1;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return 0;

    struct Node* root = NULL;
    if (n > 0) printf("Enter elements of BST: ");
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) return 0;
        root = insert(root, x);
    }

    int option;
    do {
        printf("\nMAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Largest\n");
        printf("3. Smallest\n");
        printf("4. Height (depth)\n");
        printf("5. Count leaf nodes\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        if (scanf("%d", &option) != 1) break;

        switch (option) {
            case 1: {
                int v;
                printf("Enter element to insert in BST: ");
                if (scanf("%d", &v) != 1) break;
                root = insert(root, v);
                printf("Inserted %d\n", v);
                break;
            }
            case 2: {
                struct Node* m = findMax(root);
                if (m) printf("Largest element in BST=%d\n", m->data);
                else printf("BST is empty\n");
                break;
            }
            case 3: {
                struct Node* m = findMin(root);
                if (m) printf("Smallest element in BST=%d\n", m->data);
                else printf("BST is empty\n");
                break;
            }
            case 4: {
                int key;
                printf("Enter node value to find height (depth): ");
                if (scanf("%d", &key) != 1) break;
                int d = nodeDepth(root, key);
                if (d >= 0) printf("Height (depth) of node %d = %d\n", key, d);
                else printf("%d not found in BST\n", key);
                break;
            }
            case 5: {
                int cnt = countLeaves(root);
                printf("Number of leaf nodes = %d\n", cnt);
                break;
            }
            case 6: {
                int key;
                printf("Enter element to delete: ");
                if (scanf("%d", &key) != 1) break;
                root = deleteNode(root, key);
                printf("After deletion, inorder: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 7: break;
            default: printf("Invalid option\n");
        }

    } while (option != 7);

    return 0;
}
