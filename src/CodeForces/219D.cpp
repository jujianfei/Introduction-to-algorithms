#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 0x3f3f3f3f

int dp[N];
int dpred[N];
int redall = 0;

struct Node {
    int id;
    int c;
    Node(int id, int c) :id(id), c(c) {}
    Node() {}
};

vector<Node> G[N];
int n;
vector<Node> tr[N];

void dfs(int u, int w, int red, int depth) {
    dp[u] = depth;
    dpred[u] = red;

    for (auto x: G[u]) {
        int id = x.id;
        int c = x.c;
        if (id == w) continue;

        if (c == 0) {
            dfs(id, u, red+1, depth+1);
            redall++;
        } else {
            dfs(id, u, red, depth+1);
        }
    }

}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int b, e;
    for (int i=1; i<=n-1; i++) {
        cin >> b >> e;
        G[b].push_back(Node(e, 1));
        G[e].push_back(Node(b, 0));
    }

    dfs(1, -1, 0, 0);


    vector<int> ret;
    int miner = INF;
    for (int i=1; i<=n; i++) {
        int tmp = redall - 2 * dpred[i] + dp[i];
        if (tmp < miner) {
            miner = tmp;
            ret.clear();
            ret.push_back(i);
        } else if (tmp == miner) {
            ret.push_back(i);
        } else {

        }
    }


    cout << miner << endl;
    for (auto x: ret) {
        cout << x << " ";
    }

}