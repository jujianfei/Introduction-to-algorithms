// 二分水题

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    string id;
    int val;
    bool operator < (const Node &n1) const { return val < n1.val; }
};


vector<Node> v;

int n, b, e;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        Node tmp;
        cin >> tmp.name >> tmp.id >> tmp.val;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cin >> b >> e;


    Node lo, hi;
    lo.val = b, hi.val = e;
    vector<Node>::iterator p = lower_bound(v.begin(), v.end(), lo);
    vector<Node>::iterator q = upper_bound(v.begin(), v.end(), hi);

    if (p == q) {
        cout << "NONE" << endl;
        return 0;
    }


    p--; q--;
    for (; q!=p; q--) {
        cout << q->name << " " << q->id << endl;
    }





}

