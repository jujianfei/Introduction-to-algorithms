#include <bits/stdc++.h>
#ifndef AVL_TREE_H_
#define AVL_TREE_H_
using namespace std;
template<typename T>
class AVLTree {
public:
    AVLTree():root_(NULL){}
    AVLTree(const AVLTree &rhs){} //复制和赋值函数没有定义
    AVLTree& operator=(const AVLTree &rhs){}
    ~AVLTree(){}

    void Insert(const T& k) {
        Insert(root_, k);
    }

    void Remove(const T& k) {
     Remove(root_, k);
    }



    struct AVLTreeNode {
     T key;
     int height;
     AVLTreeNode* left;
     AVLTreeNode* right;
     int size;
     AVLTreeNode(const T& k, AVLTreeNode* l = NULL, AVLTreeNode * r = NULL, int h = 0)
         : key(k), left(l), right(r), height(h) { size = 1; }
    };

    AVLTreeNode *root_; //根节点
    AVLTreeNode* get_root() { return root_; }
    int GetHeight(AVLTreeNode* p) const {
     return p == NULL ? -1 : p->height; //这样一来，叶子节点的值就是0了
    }

    void Insert(AVLTreeNode* &p, const T& k);
    void Remove(AVLTreeNode* &p, const T& k);

    void RotateWithLeftChild(AVLTreeNode* &z);
    void RotateWithRightChild(AVLTreeNode* &z);

    void DoubleWithLeftChild(AVLTreeNode* &z);
    void DoubleWithRightChild(AVLTreeNode* &z);

    AVLTreeNode* FindMin(AVLTreeNode* p) const;

    // you can add any feature here...
    // TODO:
    int Size(AVLTreeNode* root) {
        if (!root) return 0;
        else return root->size;
    }

};
#endif
