#include "avl_tree.h"
#include <iostream>
using std::cout;
int main() {
    AVLTree<int> avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    std::cout << "Inorder traversal of the AVL tree: ";
    avlTree.inorder();

    return 0;
}
