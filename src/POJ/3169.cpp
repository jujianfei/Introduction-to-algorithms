// 15170179_AC_125MS_868K.cc
#define INF 0xffffff
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX_EDGE 30000+7
#define MAX_NODE 2000+7
int max(int a,int b){if(a>b)return a;else return b;}
int n,m1,m2,cnt=0;//n代表总的牛头数,m1代表好的信息条数,m2代表关心不好的信息条数
struct Node{
    int b,e,w;
    Node(int b_,int e_,int w_){
        b=b_,e=e_,w=w_;
    }
    Node(){}
};
Node a[MAX_EDGE];
//索引从零开始
void ShowMap(){
    for(int i=0;i<cnt;i++){
        cout<<a[i].b<<" "<<a[i].e<<" "<<a[i].w<<endl;
    }
}
int dist[MAX_NODE];
bool Bell_ford_edge(int v0)
{
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }dist[v0]=0;

    for(int k=1;k<=n;k++){
        for(int i=0;i<cnt;i++){
            if(dist[a[i].b]+a[i].w<dist[a[i].e]){

                dist[a[i].e]=dist[a[i].b]+a[i].w;
                if(k==n)return false;
            }
        }
    }
    return true;
}
int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=0;i<n-1;i++){
        a[cnt++]=Node(i+1,i,0);
    }
    int aa,b,w;
    for(int lines=0;lines<m1;lines++){
        scanf("%d%d%d",&aa,&b,&w);
        a[cnt++]=Node(aa-1,b-1,w);
    }
    for(int lines=0;lines<m2;lines++){
        scanf("%d%d%d",&aa,&b,&w);
        a[cnt++]=Node(b-1,aa-1,-w);
    }
   // ShowMap();
    if(Bell_ford_edge(0)){
       if(dist[n-1]==INF)
           cout<<"-2"<<endl;
       else
           cout<<dist[n-1]<<endl;
    }
    else
        cout<<"-1"<<endl;
}
