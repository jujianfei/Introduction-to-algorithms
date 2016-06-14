/*
8 15
4 5 0.35
5 4 0.35
4 7 0.37
5 7 0.28
7 5 0.28
5 1 0.32
0 4 0.38
0 2 0.26
7 3 0.39
1 3 0.29
2 7 0.34
6 2 0.40
3 6 0.52
6 0 0.58
6 4 0.93
*/

#include<bits/stdc++.h>
#include<vector>
#define N 107
#define INF 0x3f3f3f
using namespace std;
struct Node{
    int v;
    double w;
    Node(){}
    Node(int v,double w):v(v),w(w){}
};
double dist[N];
int visit[N];
int path[N];
int m,n;
vector<Node> G[N];

void input(){
    cin>>n>>m;
    int a,b;
    double w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        G[a].push_back(Node(b,w));
    }
}
struct Point{
    double w;
    int id;
    Point(double w,int id):id(id),w(w){}
    Point(){}
    bool operator<(const Point n)const{
        return w>n.w;
    }
};

void Dijkstra(int s){
    for(int i=0;i<n;i++)dist[i]=INF;
    memset(visit,0,sizeof(visit));
    priority_queue<Point> q;
    q.push(Point(0,s));
    dist[s]=0;
    while(q.empty()==false){
        double w=q.top().w;
        int id=q.top().id;
        q.pop();



        visit[id]=true;
        for(int i=0;i<G[id].size();i++){
            int adj=G[id][i].v;
            double value=G[id][i].w;

            if(dist[id]+value<dist[adj]){
                dist[adj] = dist[id]+value;
                    if(visit[adj]==true)continue;
                    q.push(Point(dist[adj],adj));

            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<endl;
    }
}
int main(){
    freopen("Dijkstrain.txt","r",stdin);
    input();
    Dijkstra(0);
}
