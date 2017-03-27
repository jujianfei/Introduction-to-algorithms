// 6752986_AC_188ms_1344kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 100007
using namespace std;
#define N 5000//定点个数最大值
#define M 50000//边的个数的最大值
int m,n;//点的个数边的个数
int K;
struct Edge{
    int b,e;
    double w;
    Edge(){}
    Edge(int b_,int e_,double w_){b=b_,e=e_,w=w_;}
};

Edge a[M];
Edge ori[M];
int dist[N];

void Bell_ford_edge(int v0) {
    memset(dist, 0x3f, sizeof(dist));
    dist[v0] = 0;
    bool update = true;
    while (update){
        update = false;
        for(int i=0; i<m; i++){
            Edge tmp = a[i];
            if(dist[tmp.b]!=INF && dist[tmp.b]+tmp.w<dist[tmp.e]){
                dist[tmp.e]=dist[tmp.b]+tmp.w;
                update = true;
            }
        }
    }
}

bool can(int x) { //fj能提供的最长的线路是x，那些比他长得都置为1, 其他的都置为0，
    for (int i=0; i<m; i++) {
        a[i] = ori[i];
        if (a[i].w>x) a[i].w=1;
        else          a[i].w=0;
    }
    Bell_ford_edge(1);
    if (dist[n] == INF) return false;
    if (dist[n] <= K) return true;
    else return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &K);
    int b,e,w;
    int cur = 0;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &b, &e, &w);
        ori[cur].b = b, ori[cur].e = e, ori[cur].w = w;
        cur ++;
        ori[cur].b = e, ori[cur].e = b, ori[cur].w = w;
        cur ++;
    }
    m = cur;
    int l = 0;
    int r = INF;
    int mid;
    if (can(0)) {
        cout << "0" << endl;
        return 0;
    }
    while (l+1<r) {
        mid = (l+r)/2;
        if (can(mid)) r=mid;
        else l=mid;
    }
    if (r == INF) {
        cout << "-1" << endl;
    } else {
        cout << r << endl;
    }

}
