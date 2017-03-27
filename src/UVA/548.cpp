// 6424624_AC_80ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;
#define N 10007
#define INF 0x3f3f3f3f


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int inorder[N],postorder[N];
string lines;
int n;
int miner = INF;
int res = INF;

void  StringToVec(const std::string &s, int type){
    std::stringstream sout;
    sout << s;
    n = 0;
    int tmp;
    if (type == 1) {
        while(sout >> tmp) {inorder[n++] = tmp;}
    } else {
       while(sout >> tmp) {postorder[n++] = tmp;}
    }
}

TreeNode* buildTree(int* in, int n, int* pre, int m) {
    //将一个序列分成三部分，递归解决
    if(n==0) return NULL;
    TreeNode* root = new TreeNode(-1);
    root->val = pre[n-1];
    int index;
    for(index=0; index<n; index++){
        if(in[index] == pre[n-1]) break;
    }

    int leftsize = index;
    int rightsize = n - 1 - leftsize;

    root->left = buildTree(in, leftsize, pre, leftsize);
    root->right = buildTree(in+index+1, rightsize, pre+leftsize, rightsize);
    return root;
}



void ans(TreeNode* root, int now_value) {
   if (root->left == nullptr && root->right == nullptr) {
        if (now_value + root->val < miner) {
            miner = now_value + root->val;
            res = root->val;
        } else if(now_value + root->val == miner) {
            if (root->val < now_value) {
                res = root->val;
            }
        } else {
            return;
        }
   }
   if (root->left) {
        ans(root->left, now_value + root->val);
   }
   if (root->right) {
        ans(root->right, now_value + root->val);
   }
}




int main() {
    //freopen("in.txt", "r", stdin);
    int flag = 1;
    while (getline(cin, lines)) {
        StringToVec(lines, flag);
        flag = 3 - flag;
        if (flag == 1){
            TreeNode *root = buildTree(inorder,n,postorder,n);
            miner = INF;
            ans(root, 0);
            cout << res << endl;

        }
    }
}
