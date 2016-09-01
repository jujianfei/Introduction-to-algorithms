#include "avl_tree.h"

//LL
template<typename T>
void AVLTree<T>::RotateWithLeftChild(AVLTreeNode* &z) {

    AVLTreeNode* y = z->left;
    z->left = y->right;
    y->right = z;
    z->height = max(GetHeight(z->left), GetHeight(z->right)) + 1;
    y->height = max(GetHeight(y->left), z->height) + 1;
    z = y;
//    if (z->left) {
//        z->left->size = Size(z->left->left) + Size(z->left->right) + 1;
//    }
//    if (z->right) {
//        z->right->size = Size(z->right->left) + Size(z->right->right) + 1;
//    }
//     z->size = Size(z->left) + Size(z->right) + 1;

}


//RR
template<typename T>
void AVLTree<T>::RotateWithRightChild(AVLTreeNode* &z) {

    AVLTreeNode* y = z->right;
    z->right = y->left;
    y->left = z;
    z->height = max(GetHeight(z->left), GetHeight(z->right)) + 1;
    y->height = max(GetHeight(y->right), z->height) + 1;
    z = y;

//    if (z->left) {
//        z->left->size = Size(z->left->left) + Size(z->left->right) + 1;
//    }
//    if (z->right) {
//        z->right->size = Size(z->right->left) + Size(z->right->right) + 1;
//    }
//    z->size = Size(z->left) + Size(z->right) + 1;
}



//LR
template<typename T>
void AVLTree<T>::DoubleWithLeftChild(AVLTreeNode* &z) {
    RotateWithRightChild(z->left);
    RotateWithLeftChild(z);
}

//RL
template<typename T>
void AVLTree<T>::DoubleWithRightChild(AVLTreeNode* &z) {
    RotateWithLeftChild(z->right);
    RotateWithRightChild(z);
}




template<typename T>
void AVLTree<T>::Insert(AVLTreeNode* &p, const T& k) {
    if (p == NULL) {
        p = new AVLTreeNode(k);
    } else if (k < p->key) { //左子树中插入
        Insert(p->left, k);
        if (GetHeight(p->left) - GetHeight(p->right) == 2) { //虽然每次都检查，但是只调整最后一次
            if (k < p->left->key) { //LL
                RotateWithLeftChild(p);
            } else { //LR
                DoubleWithLeftChild(p);
            }
        }
    } else if (k > p->key) {//在右子树中插入
        Insert(p->right, k);
        if (GetHeight(p->right) - GetHeight(p->left) == 2) {
            if (k > p->right->key) {//RR
                RotateWithRightChild(p);
            } else { //RL
                DoubleWithRightChild(p);
            }
        }
    }else {

    }

    p->height = max(GetHeight(p->left), GetHeight(p->right)) + 1;


}


template<typename T>
void AVLTree<T>::Remove(AVLTreeNode* &p, const T& k) {
    if (p == NULL) return;
    if (p->key > k) {
        Remove(p->left, k);
        if (GetHeight(p->right) - GetHeight(p->left) == 2) {
            if (p->right->right != NULL) {
                RotateWithRightChild(p);
            } else {
                DoubleWithRightChild(p);
            }
        }
    }else if (p->key < k) {
        Remove(p->right, k);
        if (GetHeight(p->left) - GetHeight(p->right) == 2) {
            if (p->left->left != NULL) {
                RotateWithLeftChild(p);
            } else {
                DoubleWithLeftChild(p);
            }
        }
    } else if (p->left != NULL && p->right != NULL) {
        p->key = FindMin(p->right)->key; //用右子树最小节点键值代替要删除节点的键值，与二叉搜索树类似
        Remove(p->right, p->key);
        if (GetHeight(p->left) - GetHeight(p->right) == 2) {
            if (p->left->left != NULL) {
                RotateWithLeftChild(p);
            } else {
                DoubleWithLeftChild(p);
            }
        }
    } else {
        AVLTreeNode* temp = p;
        p = p->left ? p->left : p->right;
        delete temp;
    }

    if (p != NULL) {
        p->height = max(GetHeight(p->left), GetHeight(p->right)) + 1;
    }
}


template<typename T>
typename AVLTree<T>::AVLTreeNode* AVLTree<T>::FindMin(AVLTreeNode* p) const {
    AVLTreeNode* t = p;
    while (t != NULL && t->left != NULL) {
        t = t->left;
    }
    return t;
}


int main() {
    AVLTree<int> a;
    a.Insert(1);
    a.Insert(2);
    a.Insert(10);
    a.Insert(20);
    a.Insert(254);
    a.Insert(24);
    a.Insert(1067);
    a.Insert(2056);

    cout << a.Size(a.get_root()) << endl;
}
