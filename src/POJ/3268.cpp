// 15276823_AC_110MS_940K.cc
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#include <stdio.h>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f //无穷大
#define N 1007//定点个数最大值
#define M 100007//边的个数的最大值
int m,n,v0;
struct Edge
{
    int b,e;
    double w;
    Edge(){}
    Edge(int b_,int e_,double w_){
        b=b_,e=e_,w=w_;
    }
};
Edge a[M],a2[M];
int dist[N];
int dist2[N];

bool Bell_ford_edge1(int v0)
{
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }dist[v0]=0;
    for(int k=0;k<=n;k++){
        for(int i=0;i<m;i++){
            Edge tmp=a[i];
            if(dist[tmp.b]!=INF && dist[tmp.b]+tmp.w<dist[tmp.e]){
                dist[tmp.e]=dist[tmp.b]+tmp.w;
                if(k==n)return false;
            }
        }
    }
    return true;
}
bool Bell_ford_edge2(int v0)
{
    for(int i=0;i<n;i++){
        dist2[i]=INF;
    }dist2[v0]=0;
    for(int k=0;k<=n;k++){
        for(int i=0;i<m;i++){
            Edge tmp=a2[i];
            if(dist2[tmp.b]!=INF && dist2[tmp.b]+tmp.w<dist2[tmp.e]){
                dist2[tmp.e]=dist2[tmp.b]+tmp.w;
                if(k==n)return false;
            }
        }
    }
    return true;
}


int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&v0);
    --v0;
    
    int from,end,t;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&from,&end,&t);
        a2[i].e=a[i].b=from-1;
        a2[i].b=a[i].e=end-1;
        a2[i].w=a[i].w=t;
    }
    Bell_ford_edge1(v0);

    Bell_ford_edge2(v0);

    int maxertime=-1;
    for(int i=0;i<n;i++){
        if(dist[i]+dist2[i]>maxertime){
            maxertime=dist[i]+dist2[i];
        }
    }
    cout<<maxertime<<endl;
}
