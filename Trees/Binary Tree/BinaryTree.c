#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data; 
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory used by the binary tree
void freeBinaryTree(struct TreeNode* root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    freeBinaryTree(root);

    return 0;
}
