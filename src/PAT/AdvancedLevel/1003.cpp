// 给定一张图，求最短路的条数，和最短路中的召集人数输多的那一条路径，
// Dijkstra的深入理解 + 动态规划
#include <bits/stdc++.h>
using namespace std;

#define N 507
#define INF 0x3f3f3f3f

int G[N][N];
int n, m, s, tar;
int a[N];
int vis[N];
int dis[N];

int way[N];
int total[N]; // 到目前为止的最大的人数



void relax(int s) {
    vis[s] = 1;
    for (int i=0; i<n; i++) {
        if (!vis[i] && dis[s] + G[s][i] < dis[i]) {
            // 如果直接小于了，那么就直接更新成从那个点过来的方式的个数
            dis[i] = dis[s] + G[s][i];
            way[i] = way[s];
            total[i] = total[s] + a[i];
        } else if (!vis[i] && dis[s] + G[s][i] == dis[i]) {
            way[i] += way[s];
            total[i] = max(total[i], total[s]+a[i]);
        }
    }
}

void Dijkstra(int v0) {
    dis[v0] = 0;
    way[v0] = 1;
    total[v0] = a[v0];
    for (int i=0; i<n; i++) {
        //找到最小的并且放松
        int miner = INF, rec = -1;
        for (int i=0; i<n; i++) {
            if (vis[i] == 0) {
                if (dis[i] < miner) {
                    miner = dis[i];
                    rec = i;
                }
            }
        }
        relax(rec);
    }


}

int main() {

   // freopen("in.txt", "r", stdin);
    memset(G, 0x3f, sizeof(G));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));

    cin >> n >> m >> s >> tar;
    for (int i=0; i<n; i++) cin >> a[i];
    int b, e, w;

    for (int i=0; i<m; i++) {
        cin >> b >> e >> w;
        G[b][e] = G[e][b] = w;
    }

    Dijkstra(s);

    cout << way[tar] << " " << total[tar] << endl;

}
