// 6732839_AC_266ms_1468kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N (50007) //The size of the array

//struct Node {
//    int b,e,c;
//    bool operator < (const Node & n) const { return e < n.b; }
//};
int n,m;
//Node a[N];

struct Edge { int b, e, w; };
int x,y,c;
Edge a[N];
int cur = 0;
int maxerb = -INF;
int minera = INF;
int dist[N];


void Bell_ford_edge()
{
    int update = true;
    while (update) {
        update = false;
        for(int i=0;i<m;i++){
            Edge tmp=a[i];
            if(dist[tmp.b]!=INF && dist[tmp.b]+tmp.w<dist[tmp.e]){
                dist[tmp.e]=dist[tmp.b]+tmp.w;
                update = true;
            }
        }
        for(int i=minera;i<=maxerb + 1;i++){     //要使所有点满足s[i]-s[i-1] <= 1
            if(dist[i+1]>dist[i]+1){
                dist[i+1]=dist[i]+1;
                update=true;
            }
        }

        for(int i=maxerb+1;i>=minera;i--){     //要使所有点满足s[i-1]-s[i] <= 0
            if(dist[i]>dist[i+1]){
                dist[i]=dist[i+1];
                update=true;
            }
        }
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &x, &y, &c);
        minera = min(minera, x);
        maxerb = max(maxerb, y);
        a[cur].b = y + 1;
        a[cur].e = x;
        a[cur++].w = -c;
    }
//    for (int i=minera; i<=maxerb + 1; i++) {
//        a[cur].b = i+1;
//        a[cur].e = i;
//        a[cur].w = 0;
//        cur ++;
//        a[cur].b = i;
//        a[cur].e = i+1;
//        a[cur].w = 1;
//        cur ++;
//    }
    m = cur;
    memset(dist, 0x3f, sizeof(dist));
    dist[maxerb+1] = 0;
    Bell_ford_edge();
    printf("%d\n", -dist[minera]);

}
