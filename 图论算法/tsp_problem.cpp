/**
*说明，给定一个n个定点组成的带权的有向图的距离矩阵，
*要求从0点出发，经过每个节点一次之后返回0点，问所经过的最短的总的权重是多少？
*假设一定存在哈密顿回路
*算法复杂度O(2^n*n*n)
*因此n的范围一定比较小
*/

#include<bits/stdc++.h>
using namespace std;
#define N 10
#define INF 0x3f3f3f3f
int G[N][N];
int dp[1<<N][N];
int n,m;
void Input(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){for(int j=0;j<N;j++){G[i][j]=INF;}}
    scanf("%d%d",&n,&m);
    int a,b,v;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&v);
        G[a][b]=v;
        cout<<a<<"->"<<b<<endl;
    }
}
int dfs(int S,int v){
    if(dp[S][v]!=-1)return dp[S][v];
    if(S==(1<<n)-1&&v==0)return dp[S][v]=0;
    int res=INF;
    for(int u=0;u<n;u++){
        if((!(S>>u&1)) && (G[v][u]!=INF)){
            res=min(res,dfs(S|(1<<u),u)+G[v][u]);
        }
    }
    return dp[S][v]=res;
}


int main(){
    freopen("tspin.txt","r",stdin);
    Input();
    cout<<dfs(0,0)<<endl;
}
