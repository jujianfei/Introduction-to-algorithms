POJ3169 Layout

题意：

n头牛编号为1到n，按照编号的顺序排成一列，每两头牛的之间的距离 >= 0。这些牛的距离存在着一些约束关系：1.有ml组（u, v, w）的约束关系，表示牛[u]和牛[v]之间的距离必须 <= w。2.有md组（u, v, w）的约束关系，表示牛[u]和牛[v]之间的距离必须 >= w。问如果这n头无法排成队伍，则输出-1，如果牛[1]和牛[n]的距离可以无限远，则输出-2，否则则输出牛[1]和牛[n]之间的最大距离。

分析：

记第i号牛的位置是d[i]。首先，牛是按照编号顺序排列的，所以有d[i]<=d[i+1]成立。其次，对于每对关系好的牛之间的最大距离限制，都有d[AL]+DL >=d[BL]成立。同样，对于每对关系不好的牛，都有d[AD]+DD<=d[BD]成立。因此，原问题可以转化为在满足这三类不等式的情况下，求解d的d[N] -d[1]的最大值问题。这是线性规划问题，可以使用单源最短路径算法求解。

这些不等式的特点是所有的式子的两边都只出现了1个变量。实际上，图上的最短路问题也可以用这样的形式表示出来。记从起点s出发，到各个顶点v的最短距离为d(v)。因此，对于每条权值为w的边e=(v,u)，都有d(v)+w >=d(u)成立。反之，在满足全部这些约束不等式的d中，d(v)-d(s)的最大值就是从s到v的最短距离。需要注意这里不是最小值，而是最大值对应着最短距离。

把原来的问题和最短路问题进行比较就可以发现，两个问题都是完全一样的形式。也就是说，可以通过把原来的问题的每一个约束不等式对应成图中的一条边来构图，然后通过解决最短路问题来解决原问题。首先把顶点编号为1~N，d[i]<=d[i+1]变形为d[i+1]+0>=d[i]，因此从顶点i+1向顶点i连一条权值为0的边。同样d[AL]+DL>=d[BL]对应从顶点BL连一条权值为DL的边，d[AD]+DD<=d[BD]对应从顶点BD向顶点AD连一条权值为-DD的边。所求的问题是d[N]-d[1]的最大值，对应为顶点1到顶点N的最短距离。由于图中存在负权边，因此不使用Dijkstra算法而是使用Bellman-Ford算法求解。即使这样复杂度也只有O(N(N+ML+MD))。

```C++

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
const int INF = 1000000000;
int N, ML, MD;
int AL[maxn], BL[maxn], DL[maxn];
int AD[maxn], BD[maxn], DD[maxn];
int d[maxn];

void solve() {
    fill(d, d+N, INF);
    d[0] = 0;
    //用Bellman-Ford算法计算d
    for(int k=0; k < N; ++k) {
        //从i+1到i的权值为0
        for(int i=0; i+1 < N; ++i) {
            if(d[i+1] < INF) d[i] = min(d[i], d[i+1]);
        }
        //从AL到BL的权值为DL
        for(int i=0; i < ML; ++i) {
            if(d[AL[i]-1] <INF)
                d[BL[i]-1] = min(d[BL[i]-1], d[AL[i]-1] + DL[i]);
        }
        //从BD到AD的权值为-DD
        for(int i=0; i < MD; ++i) {
            if(d[BD[i]-1] < INF) {
                d[AD[i]-1] = min(d[AD[i]-1], d[BD[i]-1] -DD[i]);
            }
        }
    }
    int res = d[N-1];
    if(d[0] < 0) {
        //存在负圈则无解
        res = -1;
    } else if(res == INF) {
        res = -2;
    }
    printf("%d\n", res);
}

int main() {
    int i;
    while(~scanf("%d%d%d",&N, &ML, &MD)) {
        for(i=0; i<ML; ++i) {
            scanf("%d%d%d",&AL[i], &BL[i], &DL[i]);
        }
        for(i=0; i<MD; ++i) {
            scanf("%d%d%d",&AD[i], &BD[i], &DD[i]);
        }
        solve();
    }
    return 0;
}
```