// 呵呵，居然WA在了这儿，就是这书处理，找不到头的时候，输出的是 0 1啊，不是 n 1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int b, e, w;
    Node(int b, int e, int w): b(b), e(e), w(w) {}
    Node() {}
    bool operator < (const Node &n2) const {
        return w < n2.w;
    }
};

map<int,Node> mp;

int n;
int head;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> head;

    int ans = head;
    int b, e, w;
    for (int i=0; i<n; i++) {
        cin >> b >> w >> e;
        mp[b] = Node(b, e, w);
    }

    vector<Node> ret;
    // may be can not find head

    if (mp.find(head) == mp.end()) {
        printf("%d %d\n",0 ,-1);
        return 0;
    }


    int cnt = 0;
    while (head != -1) {
        ret.push_back(mp[head]);
        int nextid = mp[head].e;
        head = nextid;
        cnt ++;
    }

    vector<Node> & v = ret;
    sort(v.begin(), v.end());


    if (v.size()==0) {
        printf("%d %05d\n", v.size(), ans);
    } else {
        printf("%d %05d\n", v.size(), v[0].b);
        for (int i=0; i<v.size()-1; i++) {
            printf("%05d %d %05d\n", v[i].b, v[i].w, v[i+1].b);
        }
        int t = v.size();
        printf("%05d %d %d\n", v[t-1].b, v[t-1].w, -1);
    }



}
