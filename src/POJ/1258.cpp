// 15242101_AC_16MS_764K.cc
#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
const int N=107;
int n;
int w[N][N];//从0开始
int mincost[N];//每个i连接到已经选过的集合中的最小值
bool visited[N];

int Prime(int v0){
    for(int i=0;i<n;i++){
        mincost[i]=INF;
        visited[i]=false;
    }
    mincost[v0]=0;
    int res=0;
    while(true){
        int v=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==false&&(v==-1||mincost[i]<mincost[v]))v=i;
        }
        if(v==-1)break;
        visited[v]=true;
        res+=mincost[v];
        for(int i=0;i<n;i++){
            mincost[i]=std::min(mincost[i],w[v][i]);
        }
    }
    return res;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&w[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            w[i][i]=INF;
        }
        cout<<Prime(0)<<endl;
    }
}
