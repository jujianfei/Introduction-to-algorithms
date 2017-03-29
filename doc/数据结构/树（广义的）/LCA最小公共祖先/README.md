## 基于二分搜索的算法


记节点v到根的深度为depth(v)。那么，如果节点w是u和v的公共祖先的话，让u向上走depth(u)-depth(w)，让v向上走depth(v)-depth(w)步，都将走到w。因此，首先将u和v中较深的节点向上走|depth(u)-depth(v)|不，再一起一步步向上走，直到走到同一个节点，就可以在O(depth(u)+depth(v))时间内求出LCA


- 优化

```
parent2[v] = parent[parent[v]];
得到向上走两步所到的点。
再进一步利用信息。
parent4[v] = parent2[parent2[v]];
得到向上走4个点得到的信息。

```

按照这个思想就可以二分搜索了。

```C++
vector<int> G[MAX_V];  // 图的邻接表表示

int parent[MAX_LOG_V][MAX_V];  // 向上走2^k步所到的节点（超过根时记为-1）
int depth[MAX_V];              // 节点的深度

void dfs(int v, int p, int d)
{
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != p)
            dfs(G[v][i], v, d + 1);
    }
}

// 预处理
void init(int V)
{
    // 预处理出parent[0]和depth
    dfs(0, -1, 0);
    // 预处理出parent
    for (int k = 0; k + 1 < MAX_LOG_V; k++)
    {
        for (int v = 0; v < V; v++)
        {
            if (parent[k][v] < 0)
                parent[k + 1][v] = -1;
            else
            {
                parent[k + 1][v] = parent[k][parent[k][v]];
            }
 
        }
    }
}
 
// 计算u和v的LCA
int lca(int u, int v)
{
    // 让u和v向上走到同一深度
    if (depth[u] > depth[v])
        swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++)
    {
        if ((depth[v] - depth[u]) >> k & 1)
        {
            v = parent[k][v];
        }
    }
    if (u == v)
        return u;
    // 利用二分搜索计算LCA
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
    {
        if (parent[k][u] != parent[k][v])
        {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

```


## 基于RMQ的实现

```C++
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N (100007)
using namespace std;

struct edge {
    int id, to, cost;
};

int n;
vector<int> G[N];//树的表示
int vis[N*2];//dfs访问的顺序
int depth[N*2]; // 节点的深度
int id[N];// 第一次出现在vis中的下标
void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vis[k] = v;
    depth[k++] = d;
    for (int i=0; i<G[v].size(); i++) {
        if (G[v][i]!=p) {
            dfs(G[v][i], v, d+1, k);
            vis[k] = v;
            depth[k++] = d;
        }
    }
}

// **RMQ**模板,下标从1开始，对外接口：N数据的范围，n建立RMQ的范围1->n，建立RMQ的数组名称
int dp[N*2][20];
int  LOG[N*2];
void Make_Rmqindex(int n,int b[]) {
    int i,j;
    for(i=1;i<=n;i++)
        dp[0][i]=i;
    for(i=1;i<=LOG[n];i++)
    {
        int limit=n+1-(1<<i);
        for(j=1;j<=limit;j++)
        {
            int x=dp[i-1][j],y=dp[i-1][j+(1<<i>>1)];
            dp[i][j]=b[x]<b[y]?x:y;
        }
    }
}

int Rmq_Index(int l,int r,int b[]) {
    int k=LOG[r-l+1];
    int x=dp[k][l];
    int y=dp[k][r-(1<<k)+1];
    return b[x]<b[y]?x:y;
}

void rmq_init() { //对depth进行RMQ，返回的不是最小的值，而是最小的值对应的下标
    LOG[0]=-1;
    for(int i=1;i<N*2-1;i++)
        LOG[i]=LOG[i>>1]+1;
    Make_Rmqindex(n, depth);
}

//*RMQ模板end

int LCA(int u, int v) { //最小公共祖先LCA
    return vis[Rmq_Index(min(id[u], id[v]), max(id[u], id[v]), depth)];
}


int main()
{
    G[1].push_back(2);
    G[1].push_back(3);
    G[2].push_back(4);
    G[3].push_back(6);
    G[2].push_back(5);
    G[5].push_back(7);
    G[5].push_back(8);
    int k = 1; // 让下标从1开始
    dfs(1, -1, 0, k);
    n = k - 1; // dfs之后数组的大小是多少
    rmq_init();
    int x, y;
    while (1) {
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
}

//题目来自于挑战程序设计 p329

```

## Pr 

- POJ-2763-House_Wife_Wind
