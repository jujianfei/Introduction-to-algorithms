#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int leftflag,rightflag;//flag=0代表是正常的指针，flag=1代表是线索指针
    TreeNode(int x) : val(x), left(NULL), right(NULL) {leftflag=rightflag=0;}
};
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


TreeNode*pre;//全局变量用来存放刚刚遍历的节点
void Inthreading(TreeNode* &root){//建立中序线索化的算法
    if(root){
        Inthreading(root->left);
        if(!(root->left)){
            root->leftflag=1;
            root->left=pre;
        }
        if(pre&&!(pre->right)){//这里注意一开始pre是空的,直接进行->运算会发生RE
            pre->rightflag=1;
            pre->right=root;
        }
        pre=root;
        Inthreading(root->right);
    }
}

void InorderTraverse_thread(TreeNode*header){
    TreeNode* p;
    p=header->left;//p现在指向原来的树的根
    while(p!=header){
        while(p->leftflag==0){//循环到原来树的最左边的那个数
            p=p->left;
        }
        cout<<p->val<<" ";
        while(p->rightflag==1&&p->right!=header){//一直遍历那些是线索的节点，一直到某个节点的右边指针域不是线索为止
            p=p->right;
            cout<<p->val<<" ";
        }
        p=p->right;
    }
}
int main(){
    vector<string> res;
    test(res);
    int cur=0;
    TreeNode*root;
    build(root,cur,res);


    //比较好的一种方法是建立一个头节点
    TreeNode* header=new TreeNode(-1);
    header->left=root;
    header->leftflag=1;//后期更改的时候不能忘了更改标记
    header->rightflag=1;
    pre=header;
    Inthreading(root);//最左边的点的前驱已经指向了header
    //header的右边的指针
    header->right=pre;
    pre->right=header;
    pre->rightflag=1;


    InorderTraverse_thread(header);


}
