#include<bits/stdc++.h>
using namespace std;
#define RED 0
#define BLACK 1
struct Node{
    int val;
    bool color;
    Node*left,*right;
    Node(){
        val=-1;
        color=RED;
        left=right=NULL;
    }
};


Node* rotate_left(Node*h){
    if(h->right==NULL)return h;
    Node* x=h->right;
    h->right=x->left;
    x->left=h;
    x->color=h->color;
    h->color=RED;
    return x;
}

Node* rotate_right(Node*h){
    if(h->left==NULL)return h;
    Node*x=h->left;
    h->left=x->right;
    x->right=h;
    x->color=h->color;
    h->color=RED;
    return x;
}


void filpcolors(Node*root){
    root->color=RED;
    root->left->color=BLACK;
    root->right->color=BLACK;
}
bool isRed(Node*root){
    if(!root)return false;
    return root->color==RED;
}

class RBTree{
public:
    Node*root;
public:

    RBTree(){
        root=NULL;
    }

    void show(){
        dfs(root);
    }

    void dfs(Node*root){
        if(root){
            dfs(root->left);
            cout<<root->val<<endl;
            dfs(root->right);
        }
    }

    void Put(int val){

        root=put_aid(root,val);
        root->color=BLACK;

    }

    Node* put_aid(Node*&root,int val){
        if(!root){
            cout<<"alloc_node "<<val<<endl;
            root=new Node();
            root->val=val;
            root->color=RED;
            return root;
        }else{
            if(root->val==val) {}//已经存在了直接跳过
            else if(root->val<val){//右子树中插入
                root->right=put_aid(root->right,val);
            }else{
                root->left=put_aid(root->left,val);
            }

            if(isRed(root->right)&&!isRed(root->left)) {root=rotate_left(root);}
            if(isRed(root->left)&&isRed(root->left->left)) {root=rotate_right(root);}
            if(isRed(root->left)&&isRed(root->right)) {filpcolors(root);}
            return root;

        }
    }
};


int main(){
    RBTree t;
    t.Put(3);
    t.Put(4);
    t.Put(5);
    t.Put(6);
    t.Put(8);
    t.Put(88);
    cout<<t.root->val<<endl;
}
