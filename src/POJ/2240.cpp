// 15168741_AC_829MS_808K.cc
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<map>
using namespace std;
#define INF 1000000 //无穷大
#define MAXN 500000//顶点个数最大值
int n;//顶点个数
int m_;//边的个数

map<string,int> info;
struct Edge
{
    int b,e;
    double w;
    Edge(){}
    Edge(int b_,int e_,double w_){
        b=b_,e=e_,w=w_;
    }
};
Edge m[MAXN];
double dist[MAXN];
void init(){
    n=m_=0;
    info.clear();
}

bool Bell_ford_edge(int v0)
{
    for(int i=0;i<n;i++){
        dist[i]=0.0;
    }dist[v0]=1.0;
    for(int k=0;k<=n;k++){
        for(int i=0;i<m_;i++){
            if(dist[m[i].b]!=0&&dist[m[i].b]*m[i].w>dist[m[i].e]){
                dist[m[i].e]=dist[m[i].b]*m[i].w;
                if(k==n)return false;
            }
        }

    }
    //cout<<"-----"<<dist[v0]<<endl;
    return true;
}

int main( )
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    int cases=0;
    while(1){
        init();
        cin>>n;
        if(!n)break;
        cases++;
        string tmp;
        for(int i=0;i<n;i++){
           cin>>tmp;
           info[tmp]=i;
        }
        cin>>m_;
        double _w;
        string tmp1,tmp2;
        for(int now=0;now<m_;now++){
            cin>>tmp1>>_w>>tmp2;
            m[now]=Edge(info[tmp1],info[tmp2],_w);
        }
        int flag=1;
        for(int i=0;i<n;i++){
            if(!Bell_ford_edge(i)){
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Case "<<cases<<": No"<<endl;
        else
            cout<<"Case "<<cases<<": Yes"<<endl;
    }
    return 0;
}
