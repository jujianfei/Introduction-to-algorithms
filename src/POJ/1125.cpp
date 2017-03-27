// 15183776_AC_0MS_772K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
#define INF 0xfffffff
#define N 107
#include <cstdio>
#include <queue>
using namespace std;
int n;
int w[N][N];
struct node{
    int id,weight;
    friend bool operator<(node a, node b){
       return a.weight > b.weight;
    }
};
node d[N];//距离
priority_queue<node> q;
bool visited[N];
void Dijkstra(int s)
{
    for(int i=1;i<=n;i++){
        d[i].id = i;
        d[i].weight=INF;          //估算距离置INF
        visited[i] = false;
    }
    d[s].weight = 0;
    q.push(d[s]);
    while(!q.empty())
    {
        node cd = q.top();
        q.pop();
        int u = cd.id;
        if(visited[u])
            continue;
        visited[u] = true;//u=index
        for(int v=1;v<=n;v++){
            if(v!=u&&!visited[v]&&d[v].weight>d[u].weight+w[u][v])
            {
                d[v].weight = d[u].weight+w[u][v];
                q.push(d[v]);//注意这里!如果没有导致更新出现,也就没有必要将v加入队列
            }
        }
    }
}

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            w[i][j]=INF;
        }
    }
}

void ShowMap(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(w[i][j]==INF){
                cout<<"F ";
            }else{
                cout<<w[i][j]<<" ";
            }
        }cout<<endl;
    }
}



int main(){
   //freopen("D:\\in.txt","r",stdin);
   while(scanf("%d",&n)&&n){
       init();
       for(int i=1;i<=n;i++){
           int pairs,to,time;
           scanf("%d",&pairs);
           for(int j=0;j<pairs;j++){
               scanf("%d%d",&to,&time);
               w[i][to]=time;
           }
       }
       //ShowMap();
       int Min_time=INF;
       int index=-1;
       for(int i=1;i<=n;i++){
           Dijkstra(i);
           int maxer=-1;
           for(int i=1;i<=n;i++){
               maxer=std::max(maxer,d[i].weight);
           }
           if(maxer<Min_time){
               Min_time=maxer;
               index=i;
           }
       }
       if(Min_time!=INF){
            cout<<index<<" "<<Min_time<<endl;
       }else{
           cout<<"disjoint"<<endl;
       }
   }
}



