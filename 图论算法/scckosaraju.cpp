/*
13 22
0 1
0 5
2 0
6 0
2 3
3 2
3 5
5 4
4 3
4 2
6 4
11 4
7 6
7 8
8 7
6 9
8 9
9 10
9 11
11 12
12 9
10 12
*/

//要求：求一个图的强联通分量，并打印出来
#include<bits/stdc++.h>
#include<vector>
#define N 107
using namespace std;
#define RSTVEC(x) for(int i=0;i<N;i++){x[i].clear();}

int n,m;
vector<int> G[N];
vector<int> GR[N];
deque<int> tp;
int visit[N];
int cnt=0;//联通分量个数
int tag[N];//标记是哪一个联通分量
/**
*
*
*
*
*
*
*/

//清空原图，并输入信息
void input(){
    RSTVEC(G);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
    }
}
//求反向的图，存放在GR中
void reverser(){
    RSTVEC(GR);
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            GR[j].push_back(i);
        }
    }
}

//在反向图中进行DFS求反向图的逆后序
//如果使用vector存放输出信息还需要逆置
//这里我么直接使用双端队列，把排序信息放到队首即可
void dfs(int v){
    visit[v]=1;
    for(int i=0;i<GR[v].size();i++){
        if(!visit[GR[v][i]]){
            dfs(GR[v][i]);
        }
    }
    tp.push_front(v);
}

//反向图中的拓扑排序，调用dfs
void topo(){
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
        }
    }
}

/***********************************************/
//在dfs的过程中要标记标签等
void sec_dfs(int v){
    visit[v]=1;
    tag[v]=cnt;
    for(int i=0;i<G[v].size();i++){
        if(!visit[G[v][i]]){
            sec_dfs(G[v][i]);
        }
    }
}
//利用tp队列中的顺序在原图中进行第二种sec_dfs
void getans(){
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        if(!visit[tp[i]]){
            cnt++;
            sec_dfs(tp[i]);
        }
    }
}

//显示结果
void showres(){
    vector<int> G[N];
    int maxer=-1;
    for(int i=0;i<n;i++){
        maxer=std::max(maxer,tag[i]);
        G[tag[i]].push_back(i);
    }
    for(int i=1;i<=maxer;i++){
        cout<<i<<": ";
        for(int j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }cout<<endl;
    }

}

int main(){
    freopen("in.txt","r",stdin);
    input();
    reverser();
    topo();
    getans();
    showres();
}
