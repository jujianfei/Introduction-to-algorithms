// 6661680_AC_0ms_0kB.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
#define M 1000007
#define RST(x) memset(x, 0, sizeof(x))
#include<deque>


#define N 210
#define INF 0x3f3f3f3f
struct Node{
    int c;//容量
    int f;//实际流量
};
int sp,tp;//sx和ex分别代表源点和汇点
int d[N];//层次
Node G[N][N];
int n,m;

int R,C;
int sumR[N];
int sumC[N];
int Ri[N];
int Ci[N];

bool BFS(){
    memset(d,0,sizeof(d));
    deque<int> Q;
    Q.push_back(sp);
    d[sp]=1;
    while(!Q.empty()){
        int tmp=Q.front();
        Q.pop_front();
        for(int i=1;i<=n;i++){
            if(!d[i]&&G[tmp][i].c-G[tmp][i].f){
                d[i]=d[tmp]+1;
                Q.push_back(i);
            }
        }
    }
    return d[tp]!=0;
}
int DFS(int pos,int maxer){
    int f=maxer;
    if(pos==tp)return maxer;//如果到达终点DFS结束返回这条路径上的最小可以减去的值
    for(int i=1;i<=n;i++){
        if(G[pos][i].c-G[pos][i].f&&d[pos]+1==d[i]){//如果存在路径而且在层次网络中
            int a=G[pos][i].c-G[pos][i].f;
            int t=DFS(i,std::min(a,maxer));
            G[pos][i].f+=t;
            G[i][pos].f-=t;
            maxer-=t;//为什么要此顶点得到的流量减去改变量；答案就在下面的  return f-maxer;
        }
    }
    return f-maxer;//其实这里返回给他前一层的就是这个t
}
int slove(){
    int sum=0;
    while(BFS()){
        sum+=DFS(sp,INF);
    }
    return sum;
}


void init() {
    RST(sumR);RST(sumC);
    RST(G);RST(d);
    RST(Ri);RST(Ci);
}
int main()
{
    int u,v,w;
    //freopen("in.txt","r",stdin);

//    while(cin>>m>>n){
//        sp=1,tp=n;
//        memset(G,0,sizeof(G));
//        for(int i=1;i<=m;i++){
//            cin>>u>>v>>w;
//            G[u][v].c+=w;
//        }
//        cout<<slove()<<endl;
//    }

    int cases;
    cin >> cases;
    for (int T=1; T<=cases; T++) {
        init();
        cin >> R >> C;

        for (int i=1; i<=R; i++) cin >> sumR[i];
        for (int i=1; i<=C; i++) cin >> sumC[i];
        Ci[1] = sumC[1];
        for (int i=2; i<=C; i++) { Ci[i] = sumC[i] - sumC[i-1];}
        Ri[1] = sumR[1];
        for (int i=2; i<=R; i++) { Ri[i] = sumR[i] - sumR[i-1];}
        n = R + C;
        sp = n + 1;
        tp = n + 2;

        //从源点向xi进行添加
        for (int i=1; i<=R; i++) G[sp][i].c +=(Ri[i]-C);
        for (int i=R+1; i<=R+C; i++) G[i][tp].c += (Ci[i-R]-R);
        for (int i=1; i<=R; i++) {
            for (int j=R+1; j<=R+C; j++) {
                G[i][j].c += 19;
            }
        }
        //cout << sp << " " << tp << endl;
        n = n + 2;
        slove();
        cout << "Matrix " << T << endl;
        for (int i=1; i<=R; i++) {
            for (int j=R+1; j<=R+C; j++) {
                cout << G[i][j].f + 1 << " ";
            }cout << endl;
        }
        cout << endl;
     }

}

