#include <stdio.h>
#include<iostream>
using namespace std;
#define INF 0xffffff //无穷大
#define N 500000//定点个数最大值
#define M 500000//边的个数的最大值
int m,n;//边的个数
struct Edge
{
    int b,e;
    double w;
    Edge(){}
    Edge(int b_,int e_,double w_){
        b=b_,e=e_,w=w_;
    }
};
Edge a[M];
int dist[N];
bool Bell_ford_edge(int v0)
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

//如果要优化，可以加一个while语句判断，
//当前是否有更新，如果没有更新，那么就跳出循环，成功。
//当然，这种条件下必须要保证，没有负的权值回路，否则会出现while死循环。
//同时为了寻找一个回路，我们可以加入一个记录父亲节点的数组，最后的时候，使用这个数组建立图，并且查找这个环即可。
