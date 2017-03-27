#include <bits/stdc++.h>
using namespace std;
#define N 1007
struct Edge{
    int e;
    double w;
    Edge(int e,double w):e(e),w(w){}
    Edge(){}
};//类似邻接表的方式存放图
struct Node{//存放在队列之中，实际上是一条边
    int b,e;
    double w;
    Node(int b,int e,double w):b(b),e(e),w(w){}
    Node(){}
    bool operator <(const Node&rhs)const{
        return w>rhs.w;//重载<运算符，优先队列最小的值优先
    }
};
vector<Edge> a[N];
bool mark[N];//标记这一个点，是不是已经加入到最小生成树中了
int n,m;
priority_queue<Node> q;
void Input(){
    memset(mark,0,sizeof(mark));
    cin>>n>>m;
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
    for(auto &mem:a[u]){
        if(mark[mem.e]==false){//将和这个定点相关的边加入到队列中，但是跳过已经在队列中的点
            q.push(Node(u,mem.e,mem.w));
        }
    }
}

double Prime_lazy(){
    double ans=0;
    visit(0);
    while(q.size()!=0){
        auto top=q.top();
        q.pop();
        if(mark[top.b]&&mark[top.e])continue;//跳过无效的边
        ans+=top.w;
        if(mark[top.b]==false){
            visit(top.b);
        }
        if(mark[top.e]==false){
            visit(top.e);
        }
    }
    return ans;
}

int main(){
    freopen("prime_in.txt","r",stdin);
    Input();
    cout<<Prime_lazy()<<endl;
}
