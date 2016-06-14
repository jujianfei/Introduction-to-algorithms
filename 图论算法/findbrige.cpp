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
vector<Node> stk;//存放桥的数组


//索引都是从1开始的
int G[N][N];//边的访问标记0:没有边,1:有边,但是没有访问过,2:有边,同时也访问过
int visited[N];//顶点的访问标记
int dfn[N];//dfs的顺序数组
int low[N];//low[u]是从u或u的子孙出发通过回边可以到达的最低深度优先数
int cnt;//dfn的计数器

int n,m,b,e;

void Init(){
    RST(G);RST(dfn);RST(low);RST(visited);
    cnt=1;
}

void dfs(int u,int root){//现在遍历的方向是u->v
    for(int v=1;v<=n;v++){
        if(G[u][v]==1){//如果存在一条边而且这条边没有被访问
            G[v][u]=G[u][v]=2;//标记被访问过
            if(!visited[v]){
                visited[v]=1;
                cnt++;//计数器1,2,3,4...
                dfn[v]=low[v]=cnt;
                dfs(v,root);
                low[u]=std::min(low[u],low[v]);
                if(dfn[u]<low[v]){
                    stk.push_back(Node(u,v));
                }
            }else{//一定是一条回边
                low[u]=std::min(low[u],dfn[v]);
            }

        }
    }
}


void solve(int begin){
    dfn[begin]=low[begin]=visited[begin]=1;
    dfs(begin,begin);
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
        solve(root);
    }

    for(int i=0;i<stk.size();i++){
        cout<<stk[i].b<<" "<<stk[i].e<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<low[i]<<" "<<dfn[i]<<endl;
    }
}
