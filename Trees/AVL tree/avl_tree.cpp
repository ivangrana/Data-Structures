#include "avl_tree.h"
#include <iostream>
#include <algorithm>

// Implementation of AVLNode methods
template <typename T>
AVLNode<T>::AVLNode(T value) : key(value), left(nullptr), right(nullptr), height(1) {}

// Implementation of AVLTree methods
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
int AVLTree<T>::getHeight(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalanceFactor(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T>* node) {
    if (node != nullptr) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

template <typename T>
AVLNode<T>* AVLTree<T>::insertNode(AVLNode<T>* node, T key) {
    if (node == nullptr) {
        return new AVLNode<T>(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        // Duplicate keys are not allowed in this implementation
        return node;
    }

    updateHeight(node);

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
void AVLTree<T>::inorderTraversal(AVLNode<T>* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

template <typename T>
void AVLTree<T>::insert(T key) {
    root = insertNode(root, key);
}

template <typename T>
void AVLTree<T>::inorder() {
    inorderTraversal(root);
}