// 真是一道好题啊，做了一个小时，都怪自己太弱
// 这里实际上仍然有优化的空间
// 这个函数应当有更简单的实现方式

#include <bits/stdc++.h>
using namespace std;
#define N 1007

int a[N];


struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) {
        val = value;
        left = right = NULL;
    }
    Node() {left = right = NULL;}

};

double lg(double x) {
    return log(x)*1.0 / log(2);
}

bool is_2_n_1(int x) {
    for (int k=2; k<15; k++) {
        if ((1<<k)-1 == x) return true;
    }
    return false;
}

// 1-x这么多个数构建完全二叉树，中间的那个数字的编号是多少
int get(int x) {
    if (is_2_n_1(x)) {

        int layer = lg(x+1.001);


        return ((1<<(layer-1)));
    } else {
        int prelayer = floor(lg(x)); // 3
        int layer = ceil(lg(x)); // 4
        int down = x - ((1<<prelayer) - 1); // 3
        int oririghter = (1 << (prelayer - 1) ) - 1;
        //cout << down << " " << oririghter << endl;
        int half = (1<<(prelayer-1));

        if (down <= half) {
            return x - oririghter;
        } else {
            oririghter = oririghter + (down - half);
            return x - oririghter;
        }

    }
}

void build(Node*& root, int lo, int hi) {
    if (lo > hi) return;
    if (lo == hi) {
        root = new Node(a[lo]);
        return;
    } else {
        int n = hi - lo + 1;
        int x = get(n);
        int indexer = lo + x - 1;
        root = new Node(a[indexer]);
        build(root->left, lo, indexer-1);
        build(root->right, indexer+1, hi);
    }
}



int main() {



   // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    Node* root;
    build(root, 0, n-1);

    vector<int> ret;
    ret.push_back(root->val);
    deque<Node*> pq;
    pq.push_back(root);
    while (pq.empty()==false) {
        Node* fro = pq.front();
       // cout << "now " << fro->val << endl;
        pq.pop_front();
        if (fro->left) {
            pq.push_back(fro->left);
            //cout << "---get " << fro->left->val << endl;
            ret.push_back(fro->left->val);
        }
        if (fro->right) {
            pq.push_back(fro->right);
            //cout << "---get " << fro->right->val << endl;
            ret.push_back(fro->right->val);
        }
    }

    for (int i=0; i<ret.size()-1; i++) cout << ret[i] << " "; cout <<ret[ret.size()-1] << endl;


}
