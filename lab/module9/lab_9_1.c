#include <stdio.h>
#include <stdlib.h>

// Node for BST (linked list style)
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

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("Enter elements of BST: ");
    struct Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) return 0;
        root = insert(root, x);
    }

    printf("BST Created:\n\n");

    int option;
    do {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        if (scanf("%d", &option) != 1) break;

        switch (option) {
            case 1:
                printf("Preorder: "); preorder(root); printf("\n");
                break;
            case 2:
                printf("Postorder: "); postorder(root); printf("\n");
                break;
            case 3:
                printf("Inorder: "); inorder(root); printf("\n");
                break;
            case 4: {
                int key;
                printf("Enter element to search: ");
                if (scanf("%d", &key) != 1) break;
                if (search(root, key)) printf("%d found in BST\n", key);
                else printf("%d not found\n", key);
                break;
            }
            case 5:
                break;
            default:
                printf("Invalid option\n");
        }

    } while (option != 5);

    return 0;
}
