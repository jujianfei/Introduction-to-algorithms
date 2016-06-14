#ifndef AVL_TREE_H_
#define AVL_TREE_H_

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

 private:
     struct AVLTreeNode {
         T key;
         int height;
         AVLTreeNode* left;
         AVLTreeNode* right;

         AVLTreeNode(const T& k, AVLTreeNode* l = NULL, AVLTreeNode * r = NULL, int h = 0)
             : key(k), left(l), right(r), height(h) {}
     };

     AVLTreeNode *root_; //根节点

     int GetHeight(AVLTreeNode* p) const {
         return p == NULL ? -1 : p->height;//这样一来，叶子节点的值就是0了
     }

     void Insert(AVLTreeNode* &p, const T& k);
     void Remove(AVLTreeNode* &p, const T& k);

     void RotateWithLeftChild(AVLTreeNode* &z);
     void RotateWithRightChild(AVLTreeNode* &z);

     void DoubleWithLeftChild(AVLTreeNode* &z);
     void DoubleWithRightChild(AVLTreeNode* &z);

     AVLTreeNode* FindMin(AVLTreeNode* p) const;
};
#endif