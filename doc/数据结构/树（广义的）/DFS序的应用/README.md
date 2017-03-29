# 建立dfs数据结构

```C++
void dfs(int u, int fa){
L[u] = ++cnt;
for(int i = 0; i < g[u].size(); i ++){
    int v = g[u][i];
    if(v == fa) continue;
        dfs(v, u);
    }
    R[u] = cnt;
}
```

# 一共有七种应用

    - 由于时间原因和个人水平，只研究其中的几个模型

## 点权值加上x，询问子树的权值和

```C++
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

#define N 107

int n, m, k;
vector<int> G[N];

int L[N], R[N],dfn[N];
int cnt = 0;
int bit[N];


void Dfs(int u, int fa)
{
    dfn[++cnt] = u;
    L[u] = cnt;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int v = G[u][i];
        if(v != fa) {
            Dfs(v, u);
        }
    }
    R[u] = cnt;
}


void update(int x,int val)  {
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}

int query(int x)  {
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}




int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    Dfs(1, -1);
    cin >> k;
    int op;
    while (k--) {
        cin >> op;
        if (op==0) {
            int x,y;
            cin >> x >> y;
            update(L[x], y);
        } else {
            int x;
            cin >> x;
            cout << query(R[x])-query(L[x]-1) << endl;
        }
    }



}



```
0 代表的操作是 将某个点的权值改变多少，
1 代表的是，查询某个节点的子树的大小。



##  链上的每一个点同时加上某个树，同时查询，点的权值的大小。


转化过程：修改时 1）链两个端点权值加 x 2）链端点
的 lca 权值减 x 3）链端点 lca 的父亲权值减 x；询问时直接查询子树权值和即可

```C++
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

#define N 1007
const int LOGN = 10;
int n, m, k;
vector<int> G[N];

int L[N], R[N],dfn[N];
int cnt = 0;
int bit[N];


void Dfs(int u, int fa)
{
    dfn[++cnt] = u;
    L[u] = cnt;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int v = G[u][i];
        if(v != fa) {
            Dfs(v, u);
        }
    }
    R[u] = cnt;
}


void update(int x,int val)  {
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}

int query(int x)  {
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}


//这里构建最小的公共祖先的函数
int fa[LOGN][N];
int depth[N];

void build(int v, int p, int d) {
    fa[0][v] = p;
    depth[v] = d;
    for (int i=0; i<G[v].size(); i++) {
        if (G[v][i]!=p) {
            build(G[v][i], v, d+1);
        }
    }
}

void init(int root) {
    build(root, -1, 0);
    for (int k=0; k+1<LOGN; k++) {
        for (int v=1; v<=n; v++) {
            if (fa[k][v] < 0) fa[k+1][v] = -1;
            else {
                fa[k+1][v] = fa[k][fa[k][v]];
            }
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k=0; k<LOGN; k++) {
        if ((depth[v]-depth[u]) >> k & 1) {
            v = fa[k][v];
        }
    }
    if (u==v) return u; // 以上是调节到同一层，如果调节到同一层之后是相同的，说明一个是另一个的祖先

    for (int k=LOGN-1; k>=0; k--) {

        if (fa[k][u] != fa[k][v]) {
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    return fa[0][u];
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    init(1);
    Dfs(1, -1);
    cin >> k;
    int op;
    while (k--) {
        cin >> op;
        if (op==0) { // 0 u v +x 链上都加上一个数
            int u, v , x;
            cin >> u >> v >> x;
            int lca = LCA(u, v);
            int lca_fa = fa[0][lca];
            update(L[u], x);
            update(L[v], x);
            update(L[lca], -x);
            if (lca_fa!=-1)
                update(L[lca_fa], -x);
        } else { // 1 x， 查询点的权值的大小
            int x;
            cin >> x;

            cout << query(R[x]) - query(L[x]-1) << endl;

        }
    }
}
```

## 点权值加上x，询问链u，v上的权值的和



将询问操作转化为： 
询问 u 到根的路径权值和+v 到根的路径权值和-lca 到根的路径权值和-lca
的父亲到根的路径权值和

因此询问操作变成了询问 某个点 到根的路径权值和
询问操作转化为求入戳前缀和即可

点权修改只会影响该点子树的询问值的大小。
因此只要在入戳处加上 x，出戳+1 处减去 x，


```C++
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

#define N 1007
const int LOGN = 10;
int n, m, k;
vector<int> G[N];

int L[N], R[N],dfn[N];
int cnt = 0;
int bit[N];


void Dfs(int u, int fa)
{
    dfn[++cnt] = u;
    L[u] = cnt;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int v = G[u][i];
        if(v != fa) {
            Dfs(v, u);
        }
    }
    R[u] = cnt;
}


void update(int x,int val)  {
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}

int query(int x)  {
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}


//这里构建最小的公共祖先的函数
int fa[LOGN][N];
int depth[N];

void build(int v, int p, int d) {
    fa[0][v] = p;
    depth[v] = d;
    for (int i=0; i<G[v].size(); i++) {
        if (G[v][i]!=p) {
            build(G[v][i], v, d+1);
        }
    }
}

void init(int root) {
    build(root, -1, 0);
    for (int k=0; k+1<LOGN; k++) {
        for (int v=1; v<=n; v++) {
            if (fa[k][v] < 0) fa[k+1][v] = -1;
            else {
                fa[k+1][v] = fa[k][fa[k][v]];
            }
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k=0; k<LOGN; k++) {
        if ((depth[v]-depth[u]) >> k & 1) {
            v = fa[k][v];
        }
    }
    if (u==v) return u; // 以上是调节到同一层，如果调节到同一层之后是相同的，说明一个是另一个的祖先

    for (int k=LOGN-1; k>=0; k--) {

        if (fa[k][u] != fa[k][v]) {
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    return fa[0][u];
}



int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    init(1);
    Dfs(1, -1);
    cin >> k;
    int op;
    while (k--) {
        cin >> op;
        if (op==0) { // 0 u +x 点加上一个数
            int u, x;
            cin >> u >> x;
            update(L[u], x);
            update(R[u] + 1, -x);



        } else { // 1 u v， 查询链的权值的大小

            int u ,v;
            cin >> u >> v;
            int lca = LCA(u, v);
            int lca_fa = fa[0][lca];


            if (lca_fa != -1) {


                cout << query(L[u]) + query(L[v]) - query(L[lca]) \
                        - query(L[lca_fa]) << endl;

            }


            else
                cout << query(L[u]) + query(L[v]) - query(L[lca]) << endl;
        }
    }
}

```

## 将 X 所在子树上所有的点的权值加上 x，询问某个点的权值

子树修改只会对子树中点的询问有影响，并且影响值恰为 x。
点权加上 x，
询问点到根节点权值和。
具体操作为：入戳处加 x，出戳+1 处减 x，询问入戳前缀和。


```C++
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

#define N 1007
const int LOGN = 10;
int n, m, k;
vector<int> G[N];

int L[N], R[N],dfn[N];
int cnt = 0;
int bit[N];


void Dfs(int u, int fa)
{
    dfn[++cnt] = u;
    L[u] = cnt;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int v = G[u][i];
        if(v != fa) {
            Dfs(v, u);
        }
    }
    R[u] = cnt;
}


void update(int x,int val)  {
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}

int query(int x)  {
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}


//这里构建最小的公共祖先的函数
int fa[LOGN][N];
int depth[N];

void build(int v, int p, int d) {
    fa[0][v] = p;
    depth[v] = d;
    for (int i=0; i<G[v].size(); i++) {
        if (G[v][i]!=p) {
            build(G[v][i], v, d+1);
        }
    }
}

void init(int root) {
    build(root, -1, 0);
    for (int k=0; k+1<LOGN; k++) {
        for (int v=1; v<=n; v++) {
            if (fa[k][v] < 0) fa[k+1][v] = -1;
            else {
                fa[k+1][v] = fa[k][fa[k][v]];
            }
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k=0; k<LOGN; k++) {
        if ((depth[v]-depth[u]) >> k & 1) {
            v = fa[k][v];
        }
    }
    if (u==v) return u; // 以上是调节到同一层，如果调节到同一层之后是相同的，说明一个是另一个的祖先

    for (int k=LOGN-1; k>=0; k--) {

        if (fa[k][u] != fa[k][v]) {
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    return fa[0][u];
}



int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    init(1);
    Dfs(1, -1);
    cin >> k;
    int op;
    while (k--) {
        cin >> op;
        if (op==0) { // 0 u x 子树加上一个数
            int u, x;
            cin >> u >> x;
            update(L[u], x);
            update(R[u] + 1, -x);


        } else { // 1 u v 查询某个点的权值的大小

            int u;

            cin >> u;
            
            cout << query(u) << endl;

        }
    }

}


```
## 其他比较难，有空整理

