#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* createTree(int arr[], int i, int n) {
    struct Node* root = NULL;

    if (i < n) {
        root = newNode(arr[i]);
        root->left = createTree(arr, 2 * i + 1, n);
        root->right = createTree(arr, 2 * i + 2, n);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = createTree(arr, 0, n);

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}