#include <bits/stdc++.h>
using namespace std;
#include "indexpriorityqueue.cpp"
#define INF 0x3f3f3f3f
double besto[N];

struct Edge{
    int e;
    double w;
    Edge(int e,double w):e(e),w(w){}
    Edge(){}
};//类似邻接表的方式存放图


vector<Edge> a[N];
bool mark[N];//标记这一个点，是不是已经加入到最小生成树中了

int n,m;
IndexQ<double> q;//q维护的是，距离生成树中的点的最小值是多少


void Input(){
    memset(mark,0,sizeof(mark));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        besto[i]=INF;
    }
    int b,e;
    double w;
    for(int i=0;i<m;i++){
        cin>>b>>e>>w;
        a[b].push_back(Edge(e,w));
        a[e].push_back(Edge(b,w));//注意无向边的输入是两个方向的
    }
}

void visit(int u){
    mark[u]=true;
    for(auto mem:a[u]){
        if(mark[mem.e]==false){//将和这个定点相关的边加入到队列中，但是跳过已经在队列中的点
            if(mem.w < besto[mem.e]){
                besto[mem.e] = mem.w;
                q.change(mem.e, besto[mem.e]);
            }
        }
    }
}

double ans=0;

void Prime(){
    besto[0]=0.0;
    mark[0]=true;
    q.push(0,0.0);
    while(q.isempty()==false){
        auto tmpnode=q.top();
        q.pop();
        visit(tmpnode);
    }
}

int main(){
    freopen("prime_in.txt","r",stdin);
    Input();
    Prime();
    ans=0;
    for(int i=0;i<n;i++){
        ans+=besto[i];
        cout<<besto[i]<<endl;
    }

    cout<<endl<<ans<<endl;
}
