#include "AvlTree.h"

int main()
{
  
    AvlTree<float>* tree = new AvlTree<float>();
    // 添加节点
    tree->root = tree->insertAVLNode(tree->root, 1.1);
    tree->root = tree->insertAVLNode(tree->root, 0.6);
    tree->root = tree->insertAVLNode(tree->root, 0.5);
    tree->root = tree->insertAVLNode(tree->root, 1.0);
    tree->root = tree->insertAVLNode(tree->root, 2.0);
    tree->root = tree->insertAVLNode(tree->root, 1.5);
    tree->root = tree->insertAVLNode(tree->root, 1.7);
    
    std::cout << "Current AVL Tree Height:";
    std::cout << tree->root->height << std::endl;
    
    std::cout << "InOrder:";
    tree->inorderAVLTree(tree->root);
    std::cout << std::endl;
    tree->root = tree->insertAVLNode(tree->root, 1.0);
    tree->root = tree->removeAVLNode(tree->root, 0.5);
    std::cout << "Current AVL Tree Heigh:";
    std::cout << tree->root->height << std::endl;
    std::cout << "InOrder:";
    tree->inorderAVLTree(tree->root);
    return 0;
}