// 15169932_AC_344MS_1380K.cc
//森龄中的最大生成树,最好用kruskal算法求解
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX_EDGE 50000+7
#define MAX_NODE 20000+7
struct Node{
    int b,e,w;
    Node(int b_,int e_,int w_){
        b=b_,e=e_,w=w_;
    }
    Node(){}
};
bool compare(const Node&n1,const Node&n2){return n1.w<n2.w;}
int fa[MAX_NODE];
Node a[MAX_EDGE];
int N,M,m;//第一类有N个,第二类有M个,m条边
int getroot(int x){
    if (x != fa[x]){
        fa[x] = getroot(fa[x]);
    }
    return fa[x];
}
bool same(int i,int j){
    int m=getroot(i);
    int n=getroot(j);
    if(m==n) return true;
    else return false;
}
void merger(int i,int j){
    fa[getroot(j)]=getroot(i);
}
int Kruskal(){
    int res=0;
    for(int i=0;i<m;i++){
        if(!same(a[i].b,a[i].e)){
            res+=a[i].w;
            merger(a[i].b,a[i].e);
        }
    }
    return res;
}
void ShowMap(){
    for(int i=0;i<m;i++){
        cout<<a[i].b<<" "<<a[i].e<<" "<<a[i].w<<endl;
    }
}

int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        for(int i=0;i<MAX_NODE;i++){fa[i]=i;}
        scanf("%d%d%d",&N,&M,&m);
        int b,e,w;
        for(int lines=0;lines<m;lines++){
            scanf("%d%d%d",&b,&e,&w);
            a[lines]=Node(b,e+N,-w);
        }
        sort(a,a+m,compare);
        //ShowMap();
        cout<<10000*(N+M)+Kruskal()<<endl;

    }
}
