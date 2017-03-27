## 二叉搜索树的模板实现

```C++
#ifndef BITREESEARCHST
#define BITREESEARCHST
#include<stdio.h>
#include<iostream>
#include<set>
#include<stdexcept>
#include<cstdlib>
using namespace std;
template<typename Key,typename Value>
class BitreeSearchST{
public:
    struct Node{
        Key key;
        Value value;
        int sz;
        Node*lchild,*rchild;
        Node(){sz=0;lchild=rchild=NULL;}
        Node(Key key,Value value,int sz):key(key),value(value),sz(sz){lchild=rchild=NULL;}
    };

    BitreeSearchST<Key,Value>(){root=NULL;}
    void Put(Key key,Value value);
    Value Get(Key key);

    bool Isempty(){return root==NULL;}
    int Size(Node*p);
    Key Min(){
        if(!root) throw runtime_error("ST is empty!");
        cout<<Min_aid(root)->key<<endl;
        cout<<"wtf"<<endl;
    }

    Key Max();
    Key Floor(Key key);
    Key Ceiling(Key key);
    int Rank(Key key);
    bool Contains(Key key);
    Key Select(int k);
    void Delete(Key key);
    int Size(Key lo,Key hi);
    set<Key> Keys(Key lo,Key hi);
    set<Key> Keys();
    void Clear();
    ~BitreeSearchST<Key,Value>(){}

    void Test();

    Node*root;
    void Test_aid(Node*p);
    Node* Put_aid(Node*p,Key key,Value value);
    Value Get_aid(Node*p,Key key);
    Node* Min_aid(Node*p);
    Node* Delete_min_aid(Node*p);
    Node* Delete_aid(Node*p,Key key);
    void Keys(Node*p,Key lo,Key hi,set<Key>&s);
    Node* Floor_aid(Node*p,Key key);
    int Rank_aid(Node*p,Key key);
};

/**************测试****************/
template<typename Key,typename Value>
void BitreeSearchST<Key,Value>::Test(){
    if(!root){
        cout<<"empty!"<<endl;
        return;
    }
    Test_aid(root);
    cout<<endl;
}
template<typename Key,typename Value>
void BitreeSearchST<Key,Value>::Test_aid(Node*p){
    if(!p)return;
    Test_aid(p->lchild);
    cout<<p->key<<" "<<p->value<<" "<<endl;
    Test_aid(p->rchild);
}
/***********************测试*************************/
template<typename Key,typename Value>
void BitreeSearchST<Key,Value>::Put(Key key,Value value){
    root=Put_aid(root,key,value);
}
template<typename Key,typename Value>
typename BitreeSearchST<Key,Value>::Node* BitreeSearchST<Key,Value>::Put_aid(Node*p,Key key,Value value){
    if(!p) return new Node(key,value,1);
    if(p->key==key)p->key=key;
    else if(p->key<key)p->rchild=Put_aid(p->rchild,key,value);
    else p->lchild=Put_aid(p->lchild,key,value);
    p->sz=Size(p->lchild)+Size(p->rchild)+1;
    return p;
}
/***************************************/
template<typename Key,typename Value>
Value BitreeSearchST<Key,Value>::Get_aid(Node*p,Key key){
     if(!p) return Value();
     if(p->key==key) return p->value;
     else if(p->key>key) return Get_aid(p->lchild,key);
     else return Get_aid(p->rchild,key);
}

template<typename Key,typename Value>
Value BitreeSearchST<Key,Value>::Get(Key key){
     return Get_aid(root,key);
}

/***************************/
template<typename Key,typename Value>
int BitreeSearchST<Key,Value>::Size(Node*p){
    if(!p)return 0;
    else return Size(p->lchild)+Size(p->rchild)+1;
}
/********************************/
template<typename Key,typename Value>
typename BitreeSearchST<Key,Value>::Node* BitreeSearchST<Key,Value>::Min_aid(Node*p){
    if(!(p->lchild))return p;
    return Min_aid(p->lchild);
}

/************************************/
template<typename Key,typename Value>
typename BitreeSearchST<Key,Value>::Node* BitreeSearchST<Key,Value>::Delete_min_aid(Node*p){
    if(p->lchild==NULL){
        return p->rchild;
    }else{
        p->lchild = Delete_min_aid(p->lchild);
    }
    p->sz=Size(p->lchild)+Size(p->rchild)+1;
    return p;
}

/*******************************/
template<typename Key,typename Value>
void BitreeSearchST<Key,Value>::Delete(Key key){
    root=Delete_aid(root,key);
}
template<typename Key,typename Value>
typename BitreeSearchST<Key,Value>::Node* BitreeSearchST<Key,Value>::Delete_aid(Node*p,Key key){
    if(!p)return NULL;
    if(p->key<key){
        p->rchild=Delete_aid(p->rchild,key);
    }else if(p->key>key){
        p->lchild=Delete_aid(p->lchild,key);
    }else{

        if(p->lchild==NULL)return p->rchild;
        if(p->rchild==NULL)return p->lchild;
        Node*t=p;
        p=Min_aid(p->rchild);
        p->rchild=Delete_min_aid(t->rchild);
        p->lchild=t->lchild;//这里先右后左的顺序十分重要
    }
    p->sz=Size(p->lchild)+Size(p->rchild)+1;
    return p;
}
/*****************************************/
template<typename Key,typename Value>
void BitreeSearchST<Key,Value>::Keys(Node*p,Key lo,Key hi,set<Key>&s){
    if(p==NULL)return;
    if(p->key<lo)Keys(p->rchild,lo,hi,s);
    if(p->key>hi)Keys(p->rchild,lo,hi,s);
    if(p->key>=lo&&p->key<=hi)s.insert(p->key);
}
template<typename Key,typename Value>
set<Key> BitreeSearchST<Key,Value>::Keys(Key lo,Key hi){
    set<Key> s;
    Keys(root,lo,hi,s);
    return s;
}


/******************************************/
template<typename Key,typename Value>
Key BitreeSearchST<Key,Value>::Floor(Key key){
    Node*tmp=Floor_aid(root,key);
    if(!tmp){
        cout<<"empty"<<endl;
        return Key();
    }else{
        return tmp->key;
    }

}
template<typename Key,typename Value>
typename BitreeSearchST<Key,Value>::Node* BitreeSearchST<Key,Value>::Floor_aid(Node*p,Key key){
    if(p==NULL)return NULL;
    if(p->key==key)return p;
    if(p->key>key) return Floor_aid(p->lchild,key);
    if(p->key<key){
        Node*t=Floor_aid(p->rchild,key);
        if(t==NULL)return p;
        else return t;
    }
}

template<typename Key,typename Value>
int BitreeSearchST<Key,Value>::Rank(Key key){
    return Rank_aid(root,key);
}
template<typename Key,typename Value>
int BitreeSearchST<Key,Value>::Rank_aid(Node*p,Key key){
    if(p==NULL)return 0;
    if(p->key>key) return Rank_aid(p->lchild,key);
    else if(p->key<key) return Rank_aid(p->rchild,key)+Rank_aid(p->lchild,key)+1;
    else return Size(p->lchild);
}

#endif // BITREESEARCHST


/*
注：删除算法，对于不是根节点的节点，我们可以采用一种比较好理解的方法
先找出右子树中的最小值，用这个最小值替换这个值然后递归的删除

template<typename T>
void Remove(TreeNode* &p, const T& k) {
    if (p == NULL) return;
    if (p->key > k) {
        Remove(p->left, k);
    }else if (p->key < k) {
        Remove(p->right, k);
    } else if (p->left != NULL && p->right != NULL) {
        p->key = FindMin(p->right)->key; //用右子树最小节点键值代替要删除节点的键值
        Remove(p->right, p->key);
    } else {
        TreeNode* temp = p;
        p = p->left ? p->left : p->right;
        delete temp; 
    }
}
*/

```
