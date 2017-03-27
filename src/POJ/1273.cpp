// 15264670_AC_16MS_1080K.cc
#include<iostream>
#include<string.h>
#include<deque>
using namespace std;
#define N 210
#define INF 0x3f3f3f3f
struct Node{
    int c;//容量
    int f;//实际流量
};
int sp,tp;//sx和ex分别代表源点和汇点
int d[N];//层次
Node G[N][N];
int n,m;
bool BFS(){
    memset(d,0,sizeof(d));
    deque<int> Q;
    Q.push_back(sp);
    d[sp]=1;
    while(!Q.empty()){
        int tmp=Q.front();
        Q.pop_front();
        for(int i=1;i<=n;i++){
            if(!d[i]&&G[tmp][i].c-G[tmp][i].f){
                d[i]=d[tmp]+1;
                Q.push_back(i);
            }
        }
    }
    return d[tp]!=0;
}

int DFS(int pos,int maxer){
    int f=maxer;
    if(pos==tp)return maxer;//如果到达终点DFS结束返回这条路径上的最小可以减去的值
    for(int i=1;i<=n;i++){
        if(G[pos][i].c-G[pos][i].f&&d[pos]+1==d[i]){//如果存在路径而且在层次网络中
            int a=G[pos][i].c-G[pos][i].f;
            int t=DFS(i,std::min(a,maxer));
            G[pos][i].f+=t;
            G[i][pos].f-=t;
            maxer-=t;//为什么要此顶点得到的流量减去改变量；答案就在下面的  return f-maxer;
        }
    }
    return f-maxer;//其实这里返回给他前一层的就是这个t
}

int slove(){
    int sum=0;
    while(BFS()){
        sum+=DFS(sp,INF);
    }
    return sum;
}

int main()
{
    int u,v,w;
    //freopen("D://in.txt","r",stdin);
    while(cin>>m>>n){
        sp=1,tp=n;
        memset(G,0,sizeof(G));
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
            G[u][v].c+=w;
        }
        cout<<slove()<<endl;
    }
    return 0;
}
