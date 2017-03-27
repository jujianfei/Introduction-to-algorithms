#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, q, x;
int fa[3*maxn];
int sz[3*maxn];
int ans[3*maxn];
vector<int> G[3*maxn];

void dfs(int u) {
    sz[u] = 1;
    ans[u] = u;
    int mmax = 0;    //重儿子
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > sz[mmax])
            mmax = v;
    }
    if (sz[mmax] * 2 > sz[u])
    {

        int now = ans[mmax];
        while ((sz[u] - sz[now]) * 2 > sz[u])
            now = fa[now];
        ans[u] = now;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        G[fa[i]].push_back(i);
    }
    dfs(1);
    while (q--)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}