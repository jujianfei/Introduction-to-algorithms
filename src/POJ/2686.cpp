// 6736164_AC_625ms_3780kB.cpp
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
#define N (507) //The size of the array

double dp[N][(1<<9)];
int G[N][N];
int t,n,a,bb,m;
int tick[N];
int visited[N];

void init() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<(1<<9); j++) {
            dp[i][j] = -1.0;
        }
    }
    memset(G, 0, sizeof(G));
    memset(tick, 0 ,sizeof(tick));
    memset(visited, 0, sizeof(visited));
}

double dfs(int i, int j) { // i当前的位置，j当前剩余的车票的数量

    visited[i] = true;
    if (dp[i][j]!=-1.0) {
            visited[i] = false;
            return dp[i][j];
    }
    double ans = INF;
    for (int u=1; u<=n; u++) {

        if (G[i][u] && visited[u]==false) { // 如果当前i->u之间有道路，但是不能有无穷的递归出现
                //使用那一张车票？
                for (int k=0; k<t; k++) {
                    if (j& (1<<k)) {
                        //cout << i << " to " << u << " tick " << k << endl;
                        double tmpans = dfs(u, j&~(1<<k)) + G[i][u]*1.0/tick[k];
                        ans = min(ans, tmpans);
                    }
                }

        }
    }
    visited[i] = false;
    return dp[i][j] = ans;
}

int main () {
    //freopen("in.txt", "r", stdin);
    while (cin >> t >> n >> m >> a >> bb) { // t车票数量，n城市数量，m道路的数量
        init();
        //cout << "==cases==" << endl;
        if (!t&&!n&&!a&&!bb&&!m) break;
        for (int i=0; i<t; i++) {
            cin >> tick[i];
        }
        int b, e, w;
        for (int i=0; i<m; i++) {
            cin >> b >> e >> w;
            G[b][e]=G[e][b]=w;
        }
        //无论处在那个位置，（除了终点之外）如果车票没了，那就无法到达
        for (int i=0; i<=n; i++) dp[i][0] = INF;
        for (int i=0; i<(1<<t); i++) dp[bb][i] = 0;

        //cout << "begin " << a << " end " << bb <<endl;
        double ans = dfs(a, (1<<t)-1);

//        for (int i=1; i<=4; i++) {
//            for (int j=0; j<(1<<t); j++) {
//                cout << dp[i][j] << "   ";
//            }cout << endl;
//        }

        if (ans == INF) {
            cout << "Impossible" << endl;
        } else {
            printf("%.3f\n",ans);
        }
    }
}
