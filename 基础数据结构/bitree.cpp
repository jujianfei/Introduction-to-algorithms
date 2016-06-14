#include<bits/stdc++.h>
#define N 1000
using namespace std;
//!****************************this section is for test************************
//transfer string to int
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}
void test(vector<string>&res){
    res.push_back("1");
    res.push_back("2");
    res.push_back("4");
    res.push_back("#");
    res.push_back("#");
    res.push_back("5");
    res.push_back("#");
    res.push_back("#");
    res.push_back("3");
    res.push_back("6");
    res.push_back("#");
    res.push_back("7");
    res.push_back("#");
    res.push_back("#");
    res.push_back("#");
}

//!***********************Build_the_binary_tree*********************************
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build(TreeNode*&root,int& cur,const vector<string>&v){
    if(v[cur][0]=='#'){
        root=NULL;
        cur++;
        return;
    }
    int value=StringTo<int>(v[cur++]);
    root=new TreeNode(value);
    build(root->left,cur,v);
    build(root->right,cur,v);
}

//!****************************inorderTraversal***********************************

struct Node{
    TreeNode*ptr;
    int flag;
    Node(){
        ptr=NULL;
        flag=0;
    }
    Node(TreeNode*p):ptr(p){flag=0;}
};

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        Node stack_[N];
        int cur=0;
        stack_[cur++]=Node(root);
        while(cur>0){
            TreeNode*back=stack_[cur-1].ptr;
            if(stack_[cur-1].flag==0){//never touch the left sub tree or rightsub tree.
                stack_[cur-1].flag=1;
                if(back->left==NULL){}
                else stack_[cur++]=Node(back->left);
            }else if(stack_[cur-1].flag==1){//left sub tree has been touched.
                res.push_back(back->val);
                cout<<back->val<<" ";
                stack_[cur-1].flag=2;
                if(back->right==NULL){}
                else stack_[cur++]=Node(back->right);
            }else{//left and right subtree have been touched ,pop this element from the stack.
                cur--;
            }
        }
        return res;
}

void inorderTraversal2(TreeNode*root){
    if(!root)return;
    vector<TreeNode*> stk;
    auto p=root;
    while(p||stk.empty()==false){
        if(p){
            stk.push_back(p);p=p->left;
        }else{
            p=stk.back();
            stk.pop_back();
            cout<<p->val<<" ";
            p=p->right;
        }
    }
}
//TODO:unimplemented
void postTraversal2(TreeNode*root){

}


//!****************************************************************************
int main(){
    vector<string> res;
    test(res);
    int cur=0;
    TreeNode*root;
    build(root,cur,res);
    inorderTraversal(root);
    cout<<endl;
    inorderTraversal2(root);

}
