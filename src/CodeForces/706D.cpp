#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (100007)
using namespace std;

struct Node{
    int val;
    Node * left, *right;
    Node() { val = 0;
        left = right = NULL;
    }
};

Node* root;

void addnum(int num, int k, Node* & root) {

    if (!root) {
        root = new Node();

    }
    root->val ++;
    if (k==30) {
            return;
    }
    int flag = num & (1<<(29-k));
    if (flag) {
        addnum(num, k+1, root->left);
    } else {
        addnum(num, k+1, root->right);
    }
}

void eraser(int num, int k, Node*& root) {

    root->val --;
    if (root->val == 0) {
        root = NULL;
        return;
    }
    if (k == 30) return;

    int flag = num & (1<<(29-k));
    if (flag) {
        eraser(num, k+1, root->left);
    } else {
        eraser(num, k+1, root->right);
    }


}

int match(int x) {
    int res = 0;
    int k = 0;
    Node* p = root;
    while (k!=30) {
       int flag = x & (1<<(29-k));
        if (flag==0) {
            if (p->left) {
                res = res | (1<<(29-k));
                p = p->left;
            } else {
                p = p->right;
            }
        } else {
            if (p->right) {
                res = res | (1<<(29-k));
                p = p->right;
            } else {
                p = p->left;
            }
        }
        k++;
    }
    return res;
}

map<int, int> mp;

int main() {
    //freopen("in.txt", "r", stdin);
    int q;
    scanf("%d", &q);
    char type;
    int num;
    addnum(0, 0, root);
    mp[0] = 1;
    getchar();
    for (int i=0; i<q; i++) {
        cin >> type >> num ;
        if (type == '+') {
            if (mp.find(num)!=mp.end()) mp[num] ++;
            else {
                mp[num] = 1;
                addnum(num, 0, root);
            }
        } else if (type == '-') {
            if (mp[num]==1) {
                mp.erase(num);
                eraser(num, 0, root);
            } else {
                mp[num]--;
            }
        } else {
            cout << match(num) << endl;
        }
    }

}
