// 6664809_AC_60ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <map>
#include <deque>
using namespace std;
#define N 500
#define INF 0x3f3f3f3f

int n,m,k;
int cnt;
map<string, int> mp;
string tmp, tmp2;
int tar[N];
int devices[N];
int d0[N][N];
struct Node{
    int c;//容量
    int f;//实际流量
};
Node G[N][N];
int sp,tp;//sx和ex分别代表源点和汇点
int d[N];//层次


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





int get(string s) {
    if (mp.find(s) == mp.end()) return mp[s]=cnt++;
    else return mp[s];
}

void build_floyed() {
    for (int k=1; k<=cnt; k++) {
        for (int i=1; i<=cnt; i++) {
            for (int j=1; j<=cnt; j++) {
                d0[i][j] = d0[i][j] || (d0[i][k] && d0[k][j]);
            }
        }
    }
}

void init() {
    cnt = 1;
    mp.clear();
    memset(d0, 0, sizeof(d0));
    for (int i=0; i<N; i++) d0[i][i] = 1;
    memset(d, 0, sizeof(d));
    memset(G, 0, sizeof(G));
}

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--) {
        init();
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> tmp;
            tar[i] =  get(tmp);
        }
        cin >> m;
        for (int i=1; i<=m; i++) {
            cin >> tmp2 >> tmp;
            devices[i] = get(tmp);
        }
        cin >> k;
        for (int i=1; i<=k; i++) {
            cin >> tmp >> tmp2;
            d0[get(tmp)][get(tmp2)] = 1;
        }
        cnt--;
        build_floyed();
        /////////////
//        for (int i=1; i<=cnt; i++) {
//            for (int j=1; j<=cnt; j++) {
//                cout << d0[i][j] << " ";
//            }cout << endl;
//        }
        //////////////////
        sp = n + m + 1;
        tp = sp + 1;

        for (int i=1; i<=m; i++) G[sp][i].c += 1;
        for (int i=m+1; i<=m+n; i++) G[i][tp].c += 1;
        for (int i=1; i<=m; i++) {
            int tag1 = devices[i];
            for (int j=m+1; j<=m+n; j++) {
                int tag2 = tar[j-m];
                if (d0[tag1][tag2]) {
                    //cout << "tag1 " << tag1 << "tag2 " << tag2 << endl;
                    G[i][j].c += INF;
                }
            }
        }
        n = tp;
//        cout << " - " << sp << " - " << tp << " - " << n << endl;
//
//        for (int i=1; i<=n; i++) {
//            for (int j=1; j<=n; j++) {
//                cout << G[i][j].c << " " ;
//            }cout << endl;
//        }

        cout << m - slove() << endl ;
        if (cases!=0) cout << endl;


    }

}
