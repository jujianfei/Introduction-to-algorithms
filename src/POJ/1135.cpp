// 15166262_AC_0MS_956K.cc
#include <iostream>
#include <cstdio>
#include <queue>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define maxn 507
#define INF 0xffffff
int w[maxn][maxn];//从1开始
int n,m;
struct node{
    int id,weight;
    friend bool operator<(node a, node b){//重定义优先级，以小为先
       return a.weight > b.weight;
    }
};
priority_queue<node> q;
int parent[maxn];
bool visited[maxn];
node d[maxn];//距离
void Dijkstra(int s)
{
    for(int i=1;i<=n;i++){
        d[i].id = i;
        d[i].weight=INF;          //估算距离置INF
        parent[i] = -1;
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
                parent[v] = u;
                q.push(d[v]);//注意这里!如果没有导致更新出现,也就没有必要将u加入队列
            }
        }
    }
}
void init(){
    memset(d,0,maxn*sizeof(node));
    memset(visited,0,maxn*sizeof(node));
}

int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    int cases=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m==0&&n==0)break;
      cases++;
      for(int i=1;i<=n;i++){
          for(int j=i;j<=n;j++){
              w[i][j]=w[j][i]=INF;
          }
      }
      int a,b,t;
      while(m--){
          scanf("%d%d%d",&a,&b,&t);
          w[a][b]=w[b][a]=t;
      }

      Dijkstra(1);

      double max1=0;
      int index1;
      for(int i=2;i<=n;i++){
          if(max1<d[i].weight){
              max1=d[i].weight;
              index1=i;
          }
      }
      if(max1==0)index1=1;
      double max2=0;
      int index2,index3;
      for(int i=1;i<=n;i++){
          for(int j=i+1;j<=n;j++){
              if(w[i][j]!=INF&&(d[i].weight+d[j].weight+w[i][j])/2.0>max2){
                  index2=i,index3=j;
                  max2=(d[i].weight+d[j].weight+w[i][j])/2.0;
              }
          }
      }
      cout<<"System #"<<cases<<endl;
      if(max1>=max2){
          printf("The last domino falls after %.1f seconds, at key domino %d.\n\n",max1,index1);
      }else{
          printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n",max2,index2,index3);
      }
    }

}
