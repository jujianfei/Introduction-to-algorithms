
在无向连通图G中，当且仅当删去G中的顶点 v及所有依附于v的所有边后，可将图分割成两个或两个以上的连通分量，则称顶点v为关节点。

 没有关节点的连通图叫做重连通图。在重连通图上, 任何一对顶点之间至少存在有两条路径, 在删去某个顶点及与该顶点相关联的边时, 也不破坏图的连通性。

一个连通图G如果不是重连通图，那么它可以包括几个重连通分量。在一个无向连通图G中, 重连通分量可以利用深度优先生成树找到。



![Markdown](http://i2.buimg.com/1949/5c8f86591f918a6c.png)



图中具有2种边：树边，回边，交叉边(有向图中才有)
顶点 u 是关节点的充要条件：

- 如果顶点 u 是深度优先搜索生成树的根， 则 u 至少有 2 个子女。
- 如果 u 不是生成树的根，则它至少有一个子女 w，从 w 出发，不可能通过 w、 w 的子
孙，以及一条回边组成的路径到达 u 的祖先。

```
low[u] = Min
{
dfn[u],
Min{ low[w] | w 是 u 的一个子女}, (8-2)
Min{ dfn[v] | v 与 u 邻接，且(u,v)是一条回边 }
}
```

“low[w]>=dfn[u]”的含义是：顶点 u 的子女顶点 w，能够通过如前所述的路径到达顶点的最低深度优先数大于等于顶点 u 的深度优先数（注意在深度优先生成树中，顶点 m 是顶点 n的祖先，则必有 dfn[m]<dfn[n]），即 w 及其子孙不存在指向顶点 u 的祖先的回边。这时删除顶点 u及其所关联的边，则以顶点 w 为根的子树就从搜索树中脱离了。


```C++
#include <bits/stdc++.h>
#define RST(X) memset(X,0,sizeof(X))
using namespace std;
#define N 100

//显示双联通分量需要使用
struct Node{
    int b,e;
    //因为是无向边，比较的时候比较特殊
    bool compare(const Node&n){return (n.b==b&&n.e==e)||(n.b==n.e&&n.e==n.b);}
    Node(int b,int e):b(b),e(e){}
    Node(){}
};
vector<Node> stk;


//索引都是从1开始的
int G[N][N];//边的访问标记0:没有边,1:有边,但是没有访问过,2:有边,同时也访问过
int visited[N];//顶点的访问标记
int dfn[N];//dfs的顺序数组
int low[N];//low[u]是从u或u的子孙出发通过回边可以到达的最低深度优先数
int cnt;//dfn的计数器
int rootchild;//dfs的开始节点（根节点的子女数量）//如果少于2个，那么root并不是关键节点
int n,m,b,e;

void Init(){
    RST(G); RST(dfn); RST(low); RST(visited);
    cnt = 1;
    rootchild = 0;
}

void dfs(int u, int root) {
    for (int v=1; v<=n; v++) {
        if (G[u][v] == 1) {//如果存在一条边而且这条边没有被访问

            stk.push_back(Node(u, v));
            G[v][u] = G[u][v] = 2;//标记被访问过
            if (!visited[v]) {
                visited[v] = 1;
                cnt ++;//计数器1,2,3,4...
                dfn[v] = low[v] = cnt;
                dfs(v, root);
                low[u] = min(low[u],low[v]);
                //判断是否关节点
                if (low[v] >= dfn[u] && u!=root || u==root && rootchild > 1) {
                    //可选操作
                    cout << u << "_is_a_key_node" << endl;
                    while(!stk.empty()) {
                        Node top = stk.back();
                        stk.pop_back();
                        cout << top.b << "-" << top.e <<endl;
                        if (top.compare(Node(u, v))) break;
                    }
                    cout<<endl;
                    //可选操作
                }
            } else { //回边
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
}


void solve(int begin){
    dfn[begin] = low[begin] = visited[begin] = 1;
    dfs(begin, begin);
}

int main(){
     freopen("intarjan.txt","r",stdin);
     while(~scanf("%d%d",&n,&m)){
        Init();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&b,&e);
            G[b][e]=G[e][b]=1;
        }
        int root=1;
        //先统计树根的孩子节点有几个
        for (int i=1; i<=n; i++) {
            if (G[root][i]==1) {
                rootchild ++;
            }
        }
        solve(root);

    }
}

```