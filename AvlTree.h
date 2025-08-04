#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>

template <typename T>
class AvlTree {

    struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(const T& value):data(value), left(nullptr), right(nullptr), height(1) {}   
};
    
   
  
public:
    AVLNode* root;

    AvlTree():root(nullptr){};
    ~AvlTree(){};


    int maxHeight(AVLNode* l, AVLNode* r)
    {
        if(l == nullptr && r == nullptr)
        {
            return 0;
        }
        if(l == nullptr)
        {
            return r->height;
        }
        if(r == nullptr)
        {
            return l->height;
        }
        return r->height > l->height ? r->height : l->height; 

    }
    
    int height(AVLNode* node)
    {
        if(nullptr == node) return 0;
        // std::cout << node->height<<std::endl;
        return node->height;
    }

    // 右旋
    AVLNode* rightRotation(AVLNode* head){
        AVLNode* newHead = head->left;
        head->left = newHead->right;
        newHead->right = head;
        head->height = 1 + maxHeight(head->left, head->right);
        newHead->height = 1 + maxHeight(newHead->left, newHead->right);

        return newHead;
    }

    // 左旋
    AVLNode* leftRotation(AVLNode* head)
    {
        AVLNode* newHead = head->right;
        head->right = newHead->left;
        newHead->left = head;
        head->height = 1 + maxHeight(head->left, head->right);
        newHead->height = 1 + maxHeight(newHead->left, newHead->right);

        return newHead;
    }

    AVLNode* insertAVLNode(AVLNode* node, const T& value){
        if(node == nullptr){
            node = new AVLNode(value);
            return node;
        }
        // 节点插入
        if(value > node->data)
        {
            // 插入节点
            node->right = insertAVLNode(node->right, value);
        }else 
        {
            node->left = insertAVLNode(node->left, value);
        }
        
        node->height = 1 + maxHeight(node->left, node->right);

        // 保持平衡
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        
        int b = lHeight - rHeight;

        if(b > 1)
        {
            if(value < node->left->data)
            {
                return rightRotation(node);
            }else
            {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }
        }else if(b < -1)
        {
            if(value > node->right->data)
            {
                return leftRotation(node);
            }else
            {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }
        }
        return node;
    }


    AVLNode* removeAVLNode(AVLNode* node, const T& value)
    {
        if(nullptr == node)
            return node;
        
        //节点删除 
        if(value < node->data)
            node->left = removeAVLNode(node->left, value);
        else if(value > node->data)
            node->right = removeAVLNode(node->right, value);
        else
        {
            if(node->left == nullptr)
            {
                AVLNode* r = node->right;
                delete node;
                node =  r;
            }else if(node->right == nullptr)
            {
                AVLNode* l = node->left;
                delete node;
                node = l;
            }else
            {
                AVLNode* r = node->right;
                while(r->left != nullptr) r = r->left;
                node->data = r->data;
                node->right = removeAVLNode( node->right, r->data);
            }
        }

        if(nullptr == node) return nullptr;

        node->height = 1 + maxHeight(node->left, node->right);
        
        // 保持平衡
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        int b = lHeight - rHeight;

        if(b > 1)
        {
            if(height(node->left->left) > height(node->left->right))
            {
                return rightRotation(node);
            }else
            {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }

        }else if(b < -1)
        {
            if(height(node->right->right) > height(node->right->left))
            {
                return leftRotation(node);
            }else
            {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }
        } 

        return node;
    }

    AVLNode* searchAVLNode(AVLNode* node, const T& value)
    {
        if(node == nullptr)
            return nullptr;
        if(node->data == value)
            return node;  
        searchAVLNode(node->left, value);
        searchAVLNode(node->right, value);
    }

    void inorderAVLTree(AVLNode* node)
    {
        if(nullptr == node)
            return;
        inorderAVLTree(node->left);
        std::cout << node->data << " ";
        inorderAVLTree(node->right);
    }
};



#endif