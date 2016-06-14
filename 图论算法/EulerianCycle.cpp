#include<bits/stdc++.h>
using namespace std;
#define N 103
struct Edge{
    int b,e;
};

int G[N][N];//0,没有边，1有边没有访问，2右边已经访问
int n,m;
Edge a[N*N];
int globalcounter=10;
int beginer=1;

bool dfs(int v,int w,int cnt){//任意选择一条边，cnt=1
    a[cnt-1].b=v,a[cnt-1].e=w;
    G[v][w]=G[w][v]=2;
    if(cnt==m)return true;

    for(int i=1;i<=n;i++){
        if(G[w][i]==1){
            if(dfs(w,i,cnt+1)){
                return true;
            }
        }
    }

    G[v][w]=G[w][v]=1;
    return false;
}

int main(){
    freopen("EulerianCyclein.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int x,y;
    memset(G,0,sizeof(G));
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        G[x][y]=G[y][x]=1;//从1开始索引
    }
    cout<<dfs(1,2,1)<<endl<<endl;

    for(int i=0;i<globalcounter;i++){
        cout<<a[i].b<<" "<<a[i].e<<endl;
    }
}
