#include <bits/stdc++.h>
using namespace std;
#define N 100004
#define INF 0x3f3f3f3f
int n;
int a[N];

struct Node{
    int id, w;
    Node(int id, int w):id(id), w(w) {}
    Node() {}
};

vector<Node> G[N];

int w[N];
int sz[N];

void dfs(int u, int fa) {
    int ans = 1;
    for (auto x: G[u]) {
        if (x.id == fa) continue;
        dfs(x.id, u);
        ans += sz[x.id];
        w[x.id] = x.w;
    }
    sz[u] = ans;
}


int ans = 0;

// 限定i点的值必须为 >= x
void get(int u, int tar, int fa) {

    if (a[u] < tar) {
        ans += sz[u];
        return;
    }

    for (auto x : G[u]) {
        int child = x.id;
        if (child == fa) continue;

        int no = max(tar + w[child], w[child]);
        get(child, no, u);


    }




}



int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];

    int b, w;
    for (int i=0; i<n-1; i++) {
        cin >> b >> w;
        G[i+2].push_back(Node(b, w));
        G[b].push_back(Node(i+2, w));
    }
    dfs(1, -1);
    get(1, -INF, -1);
    cout << ans << endl;



}