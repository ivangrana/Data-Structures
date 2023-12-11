#ifndef AVL_TREE_H
#define AVL_TREE_H

template <typename T>
class AVLNode {
public:
    T key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T value);
};

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    int getHeight(AVLNode<T>* node);
    int getBalanceFactor(AVLNode<T>* node);
    void updateHeight(AVLNode<T>* node);
    AVLNode<T>* rotateRight(AVLNode<T>* y);
    AVLNode<T>* rotateLeft(AVLNode<T>* x);
    AVLNode<T>* insertNode(AVLNode<T>* node, T key);
    void inorderTraversal(AVLNode<T>* root);

public:
    AVLTree();
    void insert(T key);
    void inorder();
};

#endif  // AVL_TREE_H
