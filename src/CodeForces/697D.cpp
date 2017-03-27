#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100005
vector<int> G[N];
int n;
int sz[N];
int bro[N];

void dfs(int i) {
    int ans = 1;
    for (auto x: G[i]) {
        dfs(x);
        ans += sz[x];
    }

    for (auto x: G[i]) {
        bro[x] = ans - sz[x] - 1;
    }

    sz[i] = ans;
}

// 关键是得到一个公式 E = E_fa + 1 + sz / 2
// sz 是兄弟子树的大小

double Ex[N];
double get(int fa) {
    for (auto u: G[fa]) {
        Ex[u] = Ex[fa] + 1 + bro[u]*1.0 / 2;
        get(u);
    }
}


int main() {
    Ex[1] = 1.0;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int pa;
    for (int i=2; i<=n; i++) {
        cin >> pa;
        G[pa].push_back(i);
    }
    dfs(1);
    get(1);

//    for (int i=1; i<=n; i++) cout << sz[i] << " "; cout << endl;
//    for (int i=1; i<=n; i++) cout << bro[i] << " "; cout << endl;

    for (int i=1; i<=n; i++) printf("%.8f ",Ex[i]); printf("\n");



}