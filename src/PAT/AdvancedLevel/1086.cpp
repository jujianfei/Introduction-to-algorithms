//通过栈，递归的构建二叉树，刚开始初始化的时候除了点问题，找了好久的原因
#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> v;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v, Node* l = NULL, Node* r = NULL) {
        val = v;
        left = l;
        right = r;
    }
    Node() {}
};


void build(Node*& root, int &cur) {

    if (cur >= n) {
        return;
    }

    if (v[cur] == -1) {
        cur ++;
        return;
    }

    int val = v[cur++];
    root = new Node(val);
    build(root->left, cur);
    build(root->right, cur);

}


vector<int> res;
void dfs(Node* root) {
    if (root) {
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    int tmp;
    cin >> tmp;
    string s;
    int t;
    while (cin >> s) {
        n ++;
        if (s == "Push") {
            cin >> t;
            v.push_back(t);
        } else {
            v.push_back(-1);
        }

    }



    int cur = 0;
    Node* root = NULL;
    build(root, cur);

    dfs(root);

    for (int i=0; i<res.size()-1; i++) cout << res[i] << " "; cout << res[res.size()-1] << endl;
}
