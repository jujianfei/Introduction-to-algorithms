// 6593047_AC_485ms_12840kB.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N (507*2)

int G[N][N];
int n,d;
int a[N][N*2];
int  dp[N];

void dfs(int u) {
    dp[u] = 0;
    for (int i=0; i<=n; i++) {
        if (G[u][i] == 1){
            if (dp[i]==-1) dfs(i);
            dp[u] = max(dp[u], dp[i] + 1);
        }

    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> d) {
        memset(G, 0, sizeof(G));
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        for (int i=0; i<=n; i++) {
            for (int j=0; j<d; j++) {
                scanf("%d", &a[i][j]);
            }
            sort(a[i], a[i] + d);
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                bool f = true;
                for (int k=0; k<d; k++) {
                    if (a[i][k] >= a[j][k]) {
                        f  = false; break;
                    }
                }
                if (f) G[i][j] = 1;
            }
        }
        dfs(0);
        if (dp[0]) {
            cout << dp[0] << endl;
        } else {
            cout << "Please look for another gift shop!" << endl;
        }
    }


}
